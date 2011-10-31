#include <QtTest>
#include <QFile>

#include "tst_seriesprovider.h"

#include "stub_networkaccess.h"
#include "seriesprovider.h"
#include "serie.h"

const QDate currentDate = QDate(2011, 10, 22);

//--------------------------------------------------------------------------------------------------
TestSeriesProvider::TestSeriesProvider()
{
    this->_networkAccess    = new NetworkAccessStub();
    this->_sut              = new SeriesProvider(this->_networkAccess, QDateTime(currentDate));
}

//--------------------------------------------------------------------------------------------------
TestSeriesProvider::~TestSeriesProvider()
{
    delete this->_sut;
    delete this->_networkAccess;
}

//--------------------------------------------------------------------------------------------------
QString getFileContent(const QString & file)
{
    QFile  input(file);
    input.open(QIODevice::ReadOnly);
    return input.readAll();    
}

//--------------------------------------------------------------------------------------------------
void TestSeriesProvider::testNominalCase()
{
    TestSeriesProvider fixture;
    QString            expectedUrl = "http://api.betaseries.com/shows/display/all.json?key=ce26d57deee0";
    
    fixture._networkAccess->setContent(getFileContent(":input/all_series.json"));
    fixture._networkAccess->setIsReady(true);
    fixture._sut->searchAllSeries();

    QVERIFY2(fixture._networkAccess->url() == expectedUrl, "Correct url");

    QVERIFY2(fixture._sut->getAllSeries().size() > 0, "Number of series read");
}

//--------------------------------------------------------------------------------------------------
void TestSeriesProvider::testNextAiredEpisode()
{
    TestSeriesProvider fixture;
    
    fixture._networkAccess->setContent(getFileContent(":input/all_series.json"));
    fixture._networkAccess->setIsReady(true);
    fixture._sut->searchAllSeries();
    fixture._networkAccess->setContent(getFileContent(":input/dexter_s06.json"));
    fixture._networkAccess->setIsReady(true);
    
    AiredEpisodeDetails details = fixture._sut->nextAiredEpisode(Serie("Dexter", 6));
    
    QVERIFY2(fixture._networkAccess->url() == 
             "http://api.betaseries.com/shows/episodes/dexter.json?key=ce26d57deee0&season=6",
             "Expected url for next episode aired");
    QVERIFY2(details.episode() == 4, "Next episode number");
    QVERIFY2(details.date() == QDate(2011, 10, 24), "Next episode date");
    
    fixture._networkAccess->setContent(getFileContent(":input/dexter_s06.json"));
    fixture._networkAccess->setIsReady(false);
    
    details = fixture._sut->nextAiredEpisode(Serie("Dexter", 6));
    QVERIFY2(details.date() == QDate(), "Invalid Next episode date");    

    fixture._networkAccess->setContent("{}");
    fixture._networkAccess->setIsReady(true);
    
    details = fixture._sut->nextAiredEpisode(Serie("Dexter", 6));
    QVERIFY2(details.date() == QDate(), "Invalid Next episode date");    
}

//--------------------------------------------------------------------------------------------------
void TestSeriesProvider::testLastAiredEpisode()
{
    TestSeriesProvider fixture;
    
    fixture._networkAccess->setContent(getFileContent(":input/all_series.json"));
    fixture._networkAccess->setIsReady(true);
    fixture._sut->searchAllSeries();
    fixture._networkAccess->setContent(getFileContent(":input/dexter_s06.json"));
    fixture._networkAccess->setIsReady(true);
    
    AiredEpisodeDetails details = fixture._sut->lastAiredEpisode(Serie("Dexter", 6));
    
    QVERIFY2(fixture._networkAccess->url() == 
             "http://api.betaseries.com/shows/episodes/dexter.json?key=ce26d57deee0&season=6",
             "Expected url for last episode aired");
    QVERIFY2(details.episode() == 3, "Next episode number");
    QVERIFY2(details.date() == QDate(2011, 10, 17), "Last episode date");
    
    fixture._networkAccess->setContent(getFileContent(":input/dexter_s06.json"));
    fixture._networkAccess->setIsReady(false);
    
    details = fixture._sut->lastAiredEpisode(Serie("Dexter", 6));
    QVERIFY2(details.date() == QDate(), "Invalid last episode date");    
    
    fixture._networkAccess->setContent("{}");
    fixture._networkAccess->setIsReady(true);
    
    details = fixture._sut->nextAiredEpisode(Serie("Dexter", 6));
    QVERIFY2(details.date() == QDate(), "Invalid last episode date");    
}

//--------------------------------------------------------------------------------------------------
void TestSeriesProvider::testNextAiredEpisodeRobustness()
{
    TestSeriesProvider fixture;
    
    fixture._networkAccess->setContent(getFileContent(":input/all_series.json"));
    fixture._networkAccess->setIsReady(true);
    fixture._sut->searchAllSeries();
    
    AiredEpisodeDetails details = fixture._sut->nextAiredEpisode(Serie("Wrong serie", 1));
    QVERIFY2(details.episode() == 0, "Default episode");
    QVERIFY2(details.date() == QDate(), "Default date");    
}

//--------------------------------------------------------------------------------------------------
void TestSeriesProvider::testFailCase()
{
    TestSeriesProvider fixture;

    fixture._networkAccess->setIsReady(false);
    fixture._sut->searchAllSeries();

    QVERIFY2(fixture._sut->getAllSeries().size() == 0, "No series found");
}
