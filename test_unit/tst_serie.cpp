#include "tst_serie.h"
#include "serie.h"

#include <QTest>

const QString & name                  = "House";
const uint      season                = 1;

TestSerie::TestSerie(QObject *parent) :
    QObject(parent)
{
    sut = new Serie(name, season);
}

void TestSerie::testCase ()
{
    TestSerie fixture;

    QVERIFY2(fixture.sut->name () == name, "name");
    QVERIFY2(fixture.sut->season () == season, "season");
}

void TestSerie::testOperators ()
{
    QVERIFY2 (Serie("House", 1) == Serie("House", 1), "1");
    QVERIFY2 (Serie("House", 1) != Serie("House", 2), "2");
    QVERIFY2 (Serie("House", 1) != Serie("house", 1), "3");
    QVERIFY2 (Serie("House", 1) < Serie("House", 2), "4");
    QVERIFY2 (Serie("Dexter", 1) < Serie("House", 1), "5");
}
