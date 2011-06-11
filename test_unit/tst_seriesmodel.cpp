#include "tst_seriesmodel.h"

#include <QTest>
#include <QSignalSpy>

#include "serie.h"

const int nbColumns = 3;

const Serie house_season_1 ("House", 1, 22, 0);
const Serie himym_season_2 ("How I Met Your Mother", 2, 23, 2);

TestSeriesModel::TestSeriesModel(QObject *parent) :
    QObject(parent)
{
}

void TestSeriesModel::testRows()
{
    TestSeriesModel fixture;
    QVERIFY2 (fixture._sut.rowCount () == 0, "Rows equals 0");

    fixture._sut.addSerie (house_season_1);
    QVERIFY2 (fixture._sut.rowCount () == 1, "Rows equals 1");

    fixture._sut.removeSerie (house_season_1);
    QVERIFY2 (fixture._sut.rowCount () == 0, "Rows equals 0");
}

void TestSeriesModel::testColumns()
{
    TestSeriesModel fixture;
    QVERIFY2 (fixture._sut.columnCount () == nbColumns, "Default nb columns");
}

void checkDisplayRole (const SeriesModel & sut,
                       int row, int col, const QVariant & expected,
                       const QString & comment)
{
    QVERIFY2 (sut.data (sut.index (row,col), Qt::DisplayRole) == expected,
              comment.toStdString ().c_str ());
}

void checkDecorationRole (const SeriesModel & sut,
                          int row, int col, const QVariant & expected,
                          const QString & comment)
{
    QVERIFY2 (sut.data (sut.index (row,col), Qt::DecorationRole) == expected,
              comment.toStdString ().c_str ());
}

void TestSeriesModel::testData()
{
    TestSeriesModel fixture;

    checkDisplayRole (fixture._sut, 0, 0, QVariant (), "no data");

    fixture._sut.addSerie (house_season_1);
    fixture._sut.addSerie (himym_season_2);

    checkDecorationRole (fixture._sut, 0, 0, QVariant (), "decoration role");
    checkDisplayRole (fixture._sut, 0, 0, QVariant (house_season_1.name ()),
                      "index (1,1)");
    checkDisplayRole (fixture._sut, 0, 1, QVariant (house_season_1.season ()),
                      "index (1,2)");
    checkDisplayRole (fixture._sut, 0, 2, QVariant (house_season_1.lastEpisodeDownloaded ()),
                      "index (1,3)");
    checkDisplayRole (fixture._sut, 1, 0, QVariant (himym_season_2.name ()),
                      "index (2,1)");
    checkDisplayRole (fixture._sut, 1, 1, QVariant (himym_season_2.season ()),
                      "index (2,2)");
    checkDisplayRole (fixture._sut, 1, 2, QVariant (himym_season_2.lastEpisodeDownloaded ()),
                      "index (2,3)");
    checkDisplayRole (fixture._sut, 4, 0, QVariant (), "invalid index");
}

void checkHeaderData (const SeriesModel & sut,
                      int   section,
                      Qt::Orientation orientation,
                      int   role,
                      const QString & expected,
                      const QString & comment)
{
    QVERIFY2 (sut.headerData (section, orientation, role).toString ()== expected,
              comment.toStdString ().c_str ());
}

void TestSeriesModel::testHeaderData()
{
    TestSeriesModel fixture;

    checkHeaderData (fixture._sut, 0, Qt::Horizontal, Qt::DisplayRole, "Name", "Name");
    checkHeaderData (fixture._sut, 1, Qt::Horizontal, Qt::DisplayRole, "Season", "Season");
    checkHeaderData (fixture._sut, 2, Qt::Horizontal, Qt::DisplayRole, "Last Episode Downloaded",
                     "Last episode");
    checkHeaderData (fixture._sut, 0, Qt::Horizontal, Qt::DecorationRole, "", "Decoration Role");
    checkHeaderData (fixture._sut, 0, Qt::Vertical, Qt::DecorationRole, "", "Vertical");
    checkHeaderData (fixture._sut, -1, Qt::Horizontal, Qt::DecorationRole, "", "Invalid Section");
}

