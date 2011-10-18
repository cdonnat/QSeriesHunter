#include <QtTest>
#include <QFile>

#include "tst_seriesprovider.h"

#include "stub_networkaccess.h"
#include "seriesprovider.h"

TestSeriesProvider::TestSeriesProvider()
{
    this->_networkAccess    = new NetworkAccessStub();
    this->_sut              = new SeriesProvider(this->_networkAccess);
}

TestSeriesProvider::~TestSeriesProvider()
{
    delete this->_sut;
    delete this->_networkAccess;
}

QString getFileContent()
{
    QFile  input(":input/all_series.json");
    input.open(QIODevice::ReadOnly);
    return input.readAll();    
}

void TestSeriesProvider::testNominalCase()
{
    TestSeriesProvider fixture;
    QString            expectedUrl = "http://api.betaseries.com/shows/display/all.xml?key=ce26d57deee0";
    
    fixture._networkAccess->setContent(getFileContent());
    fixture._networkAccess->setIsReady(true);
    fixture._sut->searchAllSeries();

    QVERIFY2(fixture._networkAccess->url() == expectedUrl, "Correct url");

    QVERIFY2(fixture._sut->getAllSeries().size() > 0, "Number of series read");
}

void TestSeriesProvider::testFailCase()
{
    TestSeriesProvider fixture;

    fixture._networkAccess->setIsReady(false);
    fixture._sut->searchAllSeries();

    QVERIFY2(fixture._sut->getAllSeries().size() == 0, "No series found");
}
