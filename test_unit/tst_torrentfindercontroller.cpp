#include "tst_torrentfindercontroller.h"

#include <QTest>

#include "serie.h"

//----------------------------------------------------------------------------------------------
TestTorrentFinderController::TestTorrentFinderController(QObject *parent) :
    QObject(parent)
{
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testInitialResult()
{
    TestTorrentFinderController fixture;
    QVERIFY2 (!fixture._sut.nextEpisodeIsFound (), "Initial is found");
    fixture._sut.searchNextEpisode (Serie("House", 1, 22, 0));
    QVERIFY2 (!fixture._sut.nextEpisodeIsFound (), "Initial is found 2");
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testRequestSent ()
{
    TestTorrentFinderController fixture;
    fixture._sut.addTorrentFinder (&fixture._finder1);

    fixture._sut.searchNextEpisode (Serie("House", 1, 22, 0));
    QVERIFY2(fixture._finder1.getRequest () == "House S01E01", "Test 1");

    fixture._sut.searchNextEpisode (Serie("How I Met Your Mother", 3, 22, 9));
    QVERIFY2(fixture._finder1.getRequest () == "How I Met Your Mother S03E10", "Test 2");

    fixture._sut.searchNextEpisode (Serie("Dexter", 10, 11, 4));
    QVERIFY2(fixture._finder1.getRequest () == "Dexter S10E05", "Test 3");
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testNominalCase ()
{
    TestTorrentFinderController fixture;

    fixture._finder1.setResults (
                TorrentFinderResults () << TorrentFinderResult("House", "http",1));
    fixture._finder2.setResults (
                TorrentFinderResults() << TorrentFinderResult("houseief", "url", 15)
                                       << TorrentFinderResult("house.S05E07.LOL", "xxx", 2));
    //
    fixture._sut.addTorrentFinder (&fixture._finder1);
    fixture._sut.addTorrentFinder (&fixture._finder2);
    //
    fixture._sut.searchNextEpisode (Serie("House", 5, 22, 6));
    //
    QVERIFY2(fixture._sut.nextEpisodeIsFound (), "Episode found");
    QVERIFY2(fixture._sut.getNextEpisodeUrl () == "xxx", "Episode url");
    QVERIFY2(fixture._finder1.getRequest () == "House S05E07", "Request Finder 1");
    QVERIFY2(fixture._finder2.getRequest () == "House S05E07", "Request Finder 2");
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
    fixture._sut.searchNextEpisode (Serie("The Event", 1, 22, 0));
    //
    QVERIFY2(fixture._sut.nextEpisodeIsFound (), "Episode found");
    QVERIFY2(fixture._finder1.getRequest () == "The Event S01E01", "Request Finder 1");
}
