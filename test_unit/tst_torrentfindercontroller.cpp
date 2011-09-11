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
    fixture._sut.findNextEpisode (Serie("House", 1, 2));
    QVERIFY2 (!fixture._sut.episodeIsFound (), "Initial is found 2");
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testRequestSent ()
{
    TestTorrentFinderController fixture;
    fixture._sut.addTorrentFinder (&fixture._finder1);

    fixture._sut.findNextEpisode (Serie("House", 1, 0));
    QVERIFY2(fixture._finder1.getRequest () == "|House S01E01|House 1x01", "Test 1");
    fixture._finder1.reset();
    
    fixture._sut.findNextEpisode (Serie("How I Met Your Mother", 3, 9));
    QVERIFY2(fixture._finder1.getRequest () == "|How I Met Your Mother S03E10|How I Met Your Mother 3x10", "Test 2");
    fixture._finder1.reset();
    
    fixture._sut.findNextEpisode (Serie("Dexter", 10, 4));
    QVERIFY2(fixture._finder1.getRequest () == "|Dexter S10E05|Dexter 10x05", "Test 3");
    fixture._finder1.reset();
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testNominalCase ()
{
    TestTorrentFinderController fixture;

    fixture._finder1.setResults (
                FinderResults () << FinderResult("House", "http", 1));
    fixture._finder2.setResults (
                FinderResults() << FinderResult("houseief", "url", 15)
                                       << FinderResult("house.S02E07.LOL", "xxx", 2));
    //
    fixture._sut.addTorrentFinder (&fixture._finder1);
    fixture._sut.addTorrentFinder (&fixture._finder2);
    //
    fixture._sut.findNextEpisode (Serie("House", 2, 6));
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
                FinderResults () << FinderResult("-The-Event-S01-E01", "http",1));
    //
    fixture._sut.addTorrentFinder (&fixture._finder1);
    //
    fixture._sut.findNextEpisode (Serie("The Event", 1 , 0));
    //
    QVERIFY2(fixture._sut.episodeIsFound (), "Episode found");
    QVERIFY2(fixture._finder1.getRequest () == "|The Event S01E01|The Event 1x01", "Request Finder 1");
}

//----------------------------------------------------------------------------------------------
void TestTorrentFinderController::testRegExp ()
{
    TestTorrentFinderController fixture;
    
    fixture._finder1.setResults (FinderResults () << FinderResult("Merlin Season 1-2-3", "http",1));
    //
    fixture._sut.addTorrentFinder (&fixture._finder1);
    //
    fixture._sut.findNextEpisode (Serie("Merlin", 2, 2));
    //
    QVERIFY2(!fixture._sut.episodeIsFound (), "Episode not found, the regexp doesnt match");
    
    fixture._finder1.setResults (
                                 FinderResults () << FinderResult("Merlin 2x03", "http",1));
    //
    fixture._sut.findNextEpisode (Serie("Merlin", 2, 2));
    //
    QVERIFY2(fixture._sut.episodeIsFound (), "Episode found, the regexp match");
}