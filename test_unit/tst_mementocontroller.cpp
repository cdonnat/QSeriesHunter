#include "tst_mementocontroller.h"

#include "findercontroller.h"
#include "editfinderwidget.h"

#include <QString>
#include <QDir>
#include <QFile>
#include <QTest>

#include "shared.h"

const QString initFile = "test.ini";

TestMementoController::TestMementoController(QObject *parent) :
    QObject(parent)
{
    _finderController = new FinderController;
    _editFinder       = new EditFinder(_finderController, 
                                       new EditFinderWidget);
    _sut = new MementoController(&_series, _editFinder, initFile);
}

void TestMementoController::initTestCase()
{
    QFile::remove (initFile);
}

void TestMementoController::cleanUpTestCase()
{
    QFile::remove (initFile);
}

void TestMementoController::testCase ()
{
    TestMementoController fixture;

    fixture._sut->loadMemento ();
    QVERIFY2 (fixture._series.nbSeries () == 0, "Load when no memento saved.");
    QVERIFY2 (fixture._finderController->isEnabled("Torrent"), "Torrent enable by default");
    QVERIFY2 (!fixture._finderController->isEnabled("DirectDownload"), "DDL not enable by default");
    
    fixture._series.addSerie (houseSeason1);
    fixture._series.addSerie (houseSeason2);
    fixture._finderController->enable("Torrent", false);
    fixture._finderController->enable("DirectDownload", true);
    fixture._sut->saveMemento ();

    fixture._series.removeSerie (houseSeason1);
    fixture._series.removeSerie (houseSeason2);
    fixture._finderController->enable("DirectDownload", false);
    QVERIFY2(fixture._series.nbSeries () == 0, "Before loading memento");
    fixture._sut->loadMemento ();
    QVERIFY2(fixture._series.contains (houseSeason1), "Load OK 1");
    QVERIFY2(fixture._series.contains (houseSeason2), "Load OK 2");
    QVERIFY2 (!fixture._finderController->isEnabled("Torrent"), "Torrent loading ok");
    QVERIFY2 (fixture._finderController->isEnabled("DirectDownload"), "DDL loading ok");    
}
