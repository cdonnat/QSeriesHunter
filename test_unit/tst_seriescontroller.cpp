#include "tst_seriescontroller.h"

#include "shared.h"
#include "stub_seriesprovider.h"

#include <QDateTime>
#include <QTest>

const QDate currentDate = QDate (2011, 10, 15);

TestSeriesController::TestSeriesController(QObject *parent) :
    QObject(parent)
{
    _seriesProvider = new SeriesProviderStub;
    _sut            = new SeriesController(_seriesProvider, currentDate);
}

void TestSeriesController::test ()
{
    TestSeriesController  fixture;

    QVERIFY2(!fixture._sut->contains (houseSeason1), "Exists when empty");
    QVERIFY2(fixture._sut->nbSeries () == 0, "Size when empty");

    fixture._sut->addSerie (houseSeason2);
    QVERIFY2(!fixture._sut->contains (houseSeason1), "Exists when not in");
    QVERIFY2(fixture._sut->nbSeries () == 1, "Size when 1");

    fixture._sut->addSerie (houseSeason1);
    QVERIFY2(fixture._sut->contains (houseSeason1), "Exists when in");
    QVERIFY2(fixture._sut->nbSeries () == 2, "Size when 2");

    fixture._sut->removeSerie (houseSeason1);
    QVERIFY2(fixture._sut->nbSeries () == 1, "Size when 1'");
    
    fixture._sut->enable(houseSeason2, false);
    QVERIFY2(!fixture._sut->at (0).isEnable(), "Is not enable");
}


void TestSeriesController::testRobustness ()
{
    TestSeriesController fixture;
    
    fixture._sut->addSerie(Serie("Desperate", 7));
    fixture._sut->addSerie(Serie("Dexter", 1));
    
    QVERIFY2(fixture._sut->at(0) == Serie("Desperate", 7), "Desperate should be first");
}

void TestSeriesController::testAiredEpisode ()
{
    TestSeriesController    fixture;
    
    fixture._seriesProvider->setAiredDetails(2, QDate(2011, 10, 13), 3, QDate(2011, 10, 20));
    
    Serie desperate("Desperate", 2, 1);
    fixture._sut->addSerie(desperate);
    
    QVERIFY2(fixture._sut->aNewEpisodeIsAvailable(desperate), 
             "A new ep is available");
    QVERIFY2(fixture._sut->nextAiredEpisodeDetailsAreAvailable(desperate), 
             "Next aired episode details available");
    QVERIFY2(fixture._sut->lastAiredEpisodeDetailsAreAvailable(desperate), 
             "Last aired episode details available");    
    QVERIFY2(fixture._sut->nextAiredEpisode(desperate) == 
             fixture._seriesProvider->_next.episode(), 
             "Next aired episode");
    QVERIFY2(fixture._sut->nextAiredEpisodeDate(desperate) == 
             fixture._seriesProvider->_next.date(),
             "Next aired episode date");   
    QVERIFY2(fixture._sut->lastAiredEpisode(desperate) == 
             fixture._seriesProvider->_last.episode(), 
             "Last aired episode");
    QVERIFY2(fixture._sut->lastAiredEpisodeDate(desperate) == 
             fixture._seriesProvider->_last.date(),
             "Last aired episode date");   
    //
    fixture._seriesProvider->setAiredDetails(8, currentDate, 0, QDate());
    fixture._sut->addSerie(Serie("Dexter", 4, 7));
    
    QVERIFY2(!fixture._sut->aNewEpisodeIsAvailable(Serie("Dexter", 4, 8)), 
             "A new ep is not available");
}


void TestSeriesController::testNoAiredEpisodeDetails ()
{
    TestSeriesController fixture;
    
    fixture._seriesProvider->setAiredDetails(0, QDate(), 0, QDate());
    Serie dexter("Dexter", 2);
    fixture._sut->addSerie(dexter);
        
    QVERIFY2(!fixture._sut->lastAiredEpisodeDetailsAreAvailable(dexter),
             "No details");
    QVERIFY2(!fixture._sut->nextAiredEpisodeDetailsAreAvailable(dexter),
             "No details");
}