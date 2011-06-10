#include "tst_serie.h"
#include "serie.h"

#include <QTest>

const QString & name                  = "House";
const uint      season                = 1;
const uint      nbEpisodes            = 22;
const uint      lastEpisodeDownloaded = 20;

TestSerie::TestSerie(QObject *parent) :
    QObject(parent)
{
    sut = new Serie(name, season, nbEpisodes, lastEpisodeDownloaded);
}

void TestSerie::testCase ()
{
    TestSerie fixture;

    QVERIFY2(fixture.sut->name () == name, "name");
    QVERIFY2(fixture.sut->season () == season, "season");
    QVERIFY2(fixture.sut->lastEpisodeDownloaded () == lastEpisodeDownloaded, "lastEpisodeSeen");
    QVERIFY2(!fixture.sut->isFinished (), "not Finished");

    QVERIFY2(fixture.sut->nextEpisode () == lastEpisodeDownloaded + 1, "next Episode");
    fixture.sut->inc ();
    QVERIFY2(fixture.sut->lastEpisodeDownloaded () == lastEpisodeDownloaded + 1, "lastEpisodeSeen + 1");
    QVERIFY2(!fixture.sut->isFinished (), "not Finished yet");


    fixture.sut->inc ();
    QVERIFY2(fixture.sut->lastEpisodeDownloaded () == lastEpisodeDownloaded + 2, "lastEpisodeSeen + 2");
    QVERIFY2(fixture.sut->isFinished (), "is Finished");
}
