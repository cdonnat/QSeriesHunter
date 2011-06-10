#include "tst_seriescontroller.h"

#include <QTest>

const Serie house_season_1 ("House", 1, 22, 1);
const Serie house_season_2 ("House", 2, 21, 2);

TestSeriesController::TestSeriesController(QObject *parent) :
    QObject(parent)
{
}

void TestSeriesController::test ()
{
    TestSeriesController  fixture;

    QVERIFY2(!fixture._sut.exists (house_season_1), "Exists when empty");
    fixture._sut.addSerie (house_season_2);
    QVERIFY2(!fixture._sut.exists (house_season_1), "Exists when not in");
    fixture._sut.addSerie (house_season_1);
    QVERIFY2(fixture._sut.exists (house_season_1), "Exists when in");
}
