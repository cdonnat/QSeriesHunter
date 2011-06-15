#include "tst_seriescontroller.h"

#include "shared.h"

#include <QTest>

TestSeriesController::TestSeriesController(QObject *parent) :
    QObject(parent)
{
}

void TestSeriesController::test ()
{
    TestSeriesController  fixture;

    QVERIFY2(!fixture._sut.contains (houseSeason1), "Exists when empty");
    QVERIFY2(fixture._sut.nbSeries () == 0, "Size when empty");

    fixture._sut.addSerie (houseSeason2);
    QVERIFY2(!fixture._sut.contains (houseSeason1), "Exists when not in");
    QVERIFY2(fixture._sut.nbSeries () == 1, "Size when 1");

    fixture._sut.addSerie (houseSeason1);
    QVERIFY2(fixture._sut.contains (houseSeason1), "Exists when in");
    QVERIFY2(fixture._sut.nbSeries () == 2, "Size when 2");

    fixture._sut.removeSerie (houseSeason1);
    QVERIFY2(fixture._sut.nbSeries () == 1, "Size when 1'");
}
