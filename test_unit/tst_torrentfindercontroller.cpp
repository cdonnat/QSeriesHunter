#include "tst_torrentfindercontroller.h"

#include <QTest>

#include "shared.h"

//----------------------------------------------------------------------------------------------
TestTorrentFinderController::TestTorrentFinderController(QObject *parent) :
    QObject(parent)
{
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testInitialResult()
{
    TestTorrentFinderController fixture;
    QVERIFY2 (!fixture._sut.episodeIsFound (), "Initial is found");
    fixture._sut.findEpisode (houseSeason1, 2);
    QVERIFY2 (!fixture._sut.episodeIsFound (), "Initial is found 2");
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testRequestSent ()
{
    TestTorrentFinderController fixture;
    fixture._sut.addTorrentFinder (&fixture._finder1);

    fixture._sut.findEpisode (houseSeason1, 1);
    QVERIFY2(fixture._finder1.getRequest () == "|House S01E01|House 1x01", "Test 1");
    fixture._finder1.reset();
    
    fixture._sut.findEpisode (himymSeason3, 10);
    QVERIFY2(fixture._finder1.getRequest () == "|How I Met Your Mother S03E10|How I Met Your Mother 3x10", "Test 2");
    fixture._finder1.reset();
    
    fixture._sut.findEpisode (dexterSeason10, 5);
    QVERIFY2(fixture._finder1.getRequest () == "|Dexter S10E05|Dexter 10x05", "Test 3");
    fixture._finder1.reset();
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testNominalCase ()
{
    TestTorrentFinderController fixture;

    fixture._finder1.setResults (
                TorrentFinderResults () << TorrentFinderResult("House", "http", 1));
    fixture._finder2.setResults (
                TorrentFinderResults() << TorrentFinderResult("houseief", "url", 15)
                                       << TorrentFinderResult("house.S02E07.LOL", "xxx", 2));
    //
    fixture._sut.addTorrentFinder (&fixture._finder1);
    fixture._sut.addTorrentFinder (&fixture._finder2);
    //
    fixture._sut.findEpisode (houseSeason2, 7);
    //
    QVERIFY2(fixture._sut.episodeIsFound (), "Episode found");
    QVERIFY2(fixture._sut.getEpisodeUrl () == "xxx", "Episode url");
    QVERIFY2(fixture._finder1.getRequest () == "|House S02E07|House 2x07", "Request Finder 1");
    QVERIFY2(fixture._finder2.getRequest () == "|House S02E07|House 2x07", "Request Finder 2");
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testSerieWithSpaces ()
{
    TestTorrentFinderController fixture;

    fixture._finder1.setResults (
                TorrentFinderResults () << TorrentFinderResult("-The-Event-S01-E01", "http",1));
    //
    fixture._sut.addTorrentFinder (&fixture._finder1);
    //
    fixture._sut.findEpisode (theEventSeason1, 1);
    //
    QVERIFY2(fixture._sut.episodeIsFound (), "Episode found");
    QVERIFY2(fixture._finder1.getRequest () == "|The Event S01E01|The Event 1x01", "Request Finder 1");
}
