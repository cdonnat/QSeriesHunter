#include "tst_serie.h"
#include "serie.h"

#include <QTest>

const QString & name                  = "House";
const uint      season                = 1;
const uint      lastEpisodeDownloaded = 20;

TestSerie::TestSerie(QObject *parent) :
    QObject(parent)
{
    sut = new Serie(name, season, lastEpisodeDownloaded);
}

void TestSerie::testCase ()
{
    TestSerie fixture;

    QVERIFY2(fixture.sut->name () == name, "name");
    QVERIFY2(fixture.sut->season () == season, "season");
    QVERIFY2(fixture.sut->lastEpisodeDownloaded () == lastEpisodeDownloaded, "lastEpisodeSeen");

    QVERIFY2(fixture.sut->nextEpisode () == lastEpisodeDownloaded + 1, "next Episode");
    fixture.sut->inc ();
    QVERIFY2(fixture.sut->lastEpisodeDownloaded () == lastEpisodeDownloaded + 1, "lastEpisodeSeen + 1");
}

void TestSerie::testOperators ()
{
    QVERIFY2 (Serie("House", 1, 1) == Serie("House", 1, 1), "1");
    QVERIFY2 (Serie("House", 1, 1) == Serie("House", 1, 2), "2");
    QVERIFY2 (Serie("House", 1, 1) == Serie("House", 1, 1), "3");
    QVERIFY2 (Serie("House", 1, 1) != Serie("House", 2, 1), "4");
    QVERIFY2 (Serie("House", 1, 1) != Serie("house", 1, 1), "5");
}
