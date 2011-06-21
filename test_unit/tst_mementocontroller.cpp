#include "tst_mementocontroller.h"

#include <QString>
#include <QDir>
#include <QFile>
#include <QTest>

#include "shared.h"

const QString initFile = "test.ini";

TestMementoController::TestMementoController(QObject *parent) :
    QObject(parent), _sut(&_series, initFile)
{
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

    fixture._sut.loadMemento ();
    QVERIFY2 (fixture._series.nbSeries () == 0, "Load when no memento saved.");

    fixture._series.addSerie (houseSeason1);
    fixture._series.addSerie (houseSeason2);
    fixture._sut.saveMemento ();

    fixture._series.removeSerie (houseSeason1);
    fixture._series.removeSerie (houseSeason2);
    QVERIFY2(fixture._series.nbSeries () == 0, "Before loading memento");
    fixture._sut.loadMemento ();
    QVERIFY2(fixture._series.contains (houseSeason1), "Load OK 1");
    QVERIFY2(fixture._series.contains (houseSeason2), "Load OK 2");
}
