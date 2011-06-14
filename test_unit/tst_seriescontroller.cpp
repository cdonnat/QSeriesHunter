#include "tst_seriescontroller.h"

#include <QTest>

const Serie house_season_1 ("House", 1, 1);
const Serie house_season_2 ("House", 2, 2);

TestSeriesController::TestSeriesController(QObject *parent) :
    QObject(parent)
{
}

void TestSeriesController::test ()
{
    TestSeriesController  fixture;

    QVERIFY2(!fixture._sut.contains (house_season_1), "Exists when empty");
    QVERIFY2(fixture._sut.nbSeries () == 0, "Size when empty");

    fixture._sut.addSerie (house_season_2);
    QVERIFY2(!fixture._sut.contains (house_season_1), "Exists when not in");
    QVERIFY2(fixture._sut.nbSeries () == 1, "Size when 1");

    fixture._sut.addSerie (house_season_1);
    QVERIFY2(fixture._sut.contains (house_season_1), "Exists when in");
    QVERIFY2(fixture._sut.nbSeries () == 2, "Size when 2");

    fixture._sut.removeSerie (house_season_1);
    QVERIFY2(fixture._sut.nbSeries () == 1, "Size when 1'");
}
