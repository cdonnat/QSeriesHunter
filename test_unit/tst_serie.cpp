#include "tst_serie.h"
#include "serie.h"

#include <QTest>

const QString & name            = "House";
const uint      season          = 1;
const uint      nbEpisodes      = 22;
const uint      lastEpisodeSeen = 20;

TestSerie::TestSerie(QObject *parent) :
    QObject(parent)
{
    sut = new Serie(name, season, nbEpisodes, lastEpisodeSeen);
}

void TestSerie::testCase ()
{
    TestSerie fixture;

    QVERIFY2(fixture.sut->name () == name, "name");
    QVERIFY2(fixture.sut->season () == season, "season");
    QVERIFY2(fixture.sut->lastEpisodeSeen () == lastEpisodeSeen, "lastEpisodeSeen");
    QVERIFY2(!fixture.sut->isFinished (), "not Finished");

    fixture.sut->nextEpisode ();
    QVERIFY2(fixture.sut->lastEpisodeSeen () == lastEpisodeSeen + 1, "lastEpisodeSeen + 1");
    QVERIFY2(!fixture.sut->isFinished (), "not Finished yet");


    fixture.sut->nextEpisode ();
    QVERIFY2(fixture.sut->lastEpisodeSeen () == lastEpisodeSeen + 2, "lastEpisodeSeen + 2");
    QVERIFY2(fixture.sut->isFinished (), "is Finished");
}
