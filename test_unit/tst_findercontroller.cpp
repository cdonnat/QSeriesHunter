#include "tst_findercontroller.h"

#include <QTest>

#include "shared.h"

//----------------------------------------------------------------------------------------------
TestFinderController::TestFinderController(const QString & finder1Type,
                                           const QString & finder2Type,
                                           QObject *parent) :
    QObject(parent), _finder1(finder1Type), _finder2(finder2Type)
{
}

//----------------------------------------------------------------------------------------------
void TestFinderController::testInitialResult()
{
    TestFinderController fixture;
    QVERIFY2 (!fixture._sut.episodeIsFound (), "Initial is found");
    fixture._sut.findNextEpisode (Serie("House", 1, 2));
    QVERIFY2 (!fixture._sut.episodeIsFound (), "Initial is found 2");
}

//----------------------------------------------------------------------------------------------
void TestFinderController::testRequestSent ()
{
    TestFinderController fixture;
    fixture._sut.addFinder (&fixture._finder1);

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
void TestFinderController::testNominalCase ()
{
    TestFinderController fixture;

    fixture._finder1.setResults (
                FinderResults () << FinderResult("House", "http", 1));
    fixture._finder2.setResults (
                FinderResults() << FinderResult("houseief", "url", 15)
                                       << FinderResult("house.S02E07.LOL", "xxx", 2));
    //
    fixture._sut.addFinder (&fixture._finder1);
    fixture._sut.addFinder (&fixture._finder2);
    //
    fixture._sut.findNextEpisode (Serie("House", 2, 6));
    //
    QVERIFY2(fixture._sut.episodeIsFound (), "Episode found");
    QVERIFY2(fixture._sut.getEpisodeUrl () == "xxx", "Episode url");
    QVERIFY2(fixture._finder1.getRequest () == "|House S02E07|House 2x07", "Request Finder 1");
    QVERIFY2(fixture._finder2.getRequest () == "|House S02E07|House 2x07", "Request Finder 2");
}

//----------------------------------------------------------------------------------------------
void TestFinderController::testSerieWithSpaces ()
{
    TestFinderController fixture;

    fixture._finder1.setResults (
                FinderResults () << FinderResult("-The-Event-S01-E01", "http",1));
    //
    fixture._sut.addFinder (&fixture._finder1);
    //
    fixture._sut.findNextEpisode (Serie("The Event", 1 , 0));
    //
    QVERIFY2(fixture._sut.episodeIsFound (), "Episode found");
    QVERIFY2(fixture._finder1.getRequest () == "|The Event S01E01|The Event 1x01", "Request Finder 1");
}

//----------------------------------------------------------------------------------------------
void TestFinderController::testRegExp ()
{
    TestFinderController fixture;
    
    fixture._finder1.setResults (FinderResults () << FinderResult("Merlin Season 1-2-3", "http",1));
    //
    fixture._sut.addFinder (&fixture._finder1);
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

void TestFinderController::exercizeAndCheckFinderSelection(bool            torrentShouldBeEmpty,
                                                           bool            ddlShouldBeEmpty,
                                                           const QString & comment)
{
    _finder1.reset();
    _finder2.reset();
    _sut.findNextEpisode(Serie("House", 1 ,1));
    QVERIFY2(_finder1.getRequest().isEmpty() == torrentShouldBeEmpty, "Torrent finder request ");
    QVERIFY2(_finder2.getRequest().isEmpty() == ddlShouldBeEmpty, "DLL finder request ");
}

void TestFinderController::testFinderSelection()
{
    TestFinderController fixture("Torrent", "DirectDownload");
    //
    fixture._sut.addFinder(&fixture._finder1);
    fixture._sut.addFinder(&fixture._finder2);
    fixture.exercizeAndCheckFinderSelection(false, true, "Initial");
    //
    fixture._sut.enable("DirectDownload", true);
    fixture.exercizeAndCheckFinderSelection(false, false, "Both active");
    //
    fixture._sut.enable("Torrent", false);
    fixture.exercizeAndCheckFinderSelection(true, false, "DDL only");
}

