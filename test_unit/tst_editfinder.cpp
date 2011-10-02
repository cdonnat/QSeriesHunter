#include "tst_editfinder.h"

#include <QTest>

#include "editfinder.h"
#include "findercontroller.h"
#include "stub_editfinderwidget.h"

TestEditFinder::TestEditFinder()
{
    _editFinderWidgetStub = new EditFinderWidgetStub();
    _finderController     = new FinderController();
    _sut                  = new EditFinder(_finderController, _editFinderWidgetStub);
}

void TestEditFinder::testNominal ()
{
    TestEditFinder fixture;
    
    fixture._sut->enableTorrent(true);
    QVERIFY2(fixture._editFinderWidgetStub->torrentIsEnable(), "Torrent box is checked");
    QVERIFY2(!fixture._editFinderWidgetStub->ddlIsEnable(), "DDL box is not checked");
    QVERIFY2(fixture._finderController->isEnabled("Torrent"), "Torrent selected");
    QVERIFY2(!fixture._finderController->isEnabled("DirectDownload"), "DDL not selected");
    
    fixture._sut->enableDirectDownload(true);
    QVERIFY2(fixture._editFinderWidgetStub->torrentIsEnable(), "Torrent box is checked");
    QVERIFY2(fixture._editFinderWidgetStub->ddlIsEnable(), "DDL box is checked");
    QVERIFY2(fixture._finderController->isEnabled("Torrent"), "Torrent selected");
    QVERIFY2(fixture._finderController->isEnabled("DirectDownload"), "DDL selected");   
    
    fixture._sut->enableTorrent(false);
    QVERIFY2(!fixture._editFinderWidgetStub->torrentIsEnable(), "Torrent box is not checked");
    QVERIFY2(fixture._editFinderWidgetStub->ddlIsEnable(), "DDL box is checked");
    QVERIFY2(!fixture._finderController->isEnabled("Torrent"), "Torrent not selected");
    QVERIFY2(fixture._finderController->isEnabled("DirectDownload"), "DDL selected");
}
