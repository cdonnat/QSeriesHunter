#include "tst_finderselection.h"

#include <QTest>

#include "finderselection.h"
#include "findercontroller.h"
#include "stub_finderselection.h"

TestFinderSelection::TestFinderSelection()
{
    _finderWidgetStub = new FinderSelectionWidgetStub();
    _finderController = new FinderController();
    _sut              = new FinderSelection(_finderController, _finderWidgetStub);
}

void TestFinderSelection::testNominal ()
{
    TestFinderSelection fixture;
    
    fixture._sut->enableTorrent(true);
    QVERIFY2(fixture._finderWidgetStub->torrentIsEnable(), "Torrent box is checked");
    QVERIFY2(!fixture._finderWidgetStub->ddlIsEnable(), "DDL box is not checked");
    QVERIFY2(fixture._finderController->isEnabled("Torrent"), "Torrent selected");
    QVERIFY2(!fixture._finderController->isEnabled("DirectDownload"), "DDL not selected");
    
    fixture._sut->enableDirectDownload(true);
    QVERIFY2(fixture._finderWidgetStub->torrentIsEnable(), "Torrent box is checked");
    QVERIFY2(fixture._finderWidgetStub->ddlIsEnable(), "DDL box is checked");
    QVERIFY2(fixture._finderController->isEnabled("Torrent"), "Torrent selected");
    QVERIFY2(fixture._finderController->isEnabled("DirectDownload"), "DDL selected");   
    
    fixture._sut->enableTorrent(false);
    QVERIFY2(!fixture._finderWidgetStub->torrentIsEnable(), "Torrent box is not checked");
    QVERIFY2(fixture._finderWidgetStub->ddlIsEnable(), "DDL box is checked");
    QVERIFY2(!fixture._finderController->isEnabled("Torrent"), "Torrent not selected");
    QVERIFY2(fixture._finderController->isEnabled("DirectDownload"), "DDL selected");
}
