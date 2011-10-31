#include "tst_seriesmodel.h"

#include "stub_seriesprovider.h"

#include <QTest>
#include <QSignalSpy>

#include "shared.h"

const int nbColumns = 8;

const QDate current(2011, 10, 31);

TestSeriesModel::TestSeriesModel(QObject *parent) :
    QObject(parent),_seriesProvider (new SeriesProviderStub), _sut(_seriesProvider, current)
{
}

void TestSeriesModel::testRows()
{
    TestSeriesModel fixture;
    QVERIFY2 (fixture._sut.rowCount () == 0, "Rows equals 0");

    fixture._sut.addSerie (houseSeason1);
    QVERIFY2 (fixture._sut.rowCount () == 1, "Rows equals 1");

    fixture._sut.removeSerie (houseSeason1);
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

    Serie serie1 = Serie("House", 1 , 2);
    Serie serie2 = Serie("How I Met Your Mother", 3, 3);
    
    fixture._seriesProvider->setAiredDetails(2, QDate(2011, 10, 30), 3, QDate(2011, 11, 4));
    fixture._sut.addSerie (serie1);    
    fixture._seriesProvider->setAiredDetails(0, QDate(), 0, QDate());
    fixture._sut.addSerie (serie2);

    checkDecorationRole (fixture._sut, 0, 0, QVariant (), "decoration role");
    checkDisplayRole (fixture._sut, 0, 1, QVariant (serie1.name ()),
                      "index (1,1)");
    checkDisplayRole (fixture._sut, 0, 2, QVariant (serie1.season ()),
                      "index (1,2)");
    checkDisplayRole (fixture._sut, 0, 3, QVariant (serie1.lastEpisode ()),
                      "index (1,3)");
    checkDisplayRole (fixture._sut, 0, 4, QVariant (2), "index(1,4)");
    //    checkDisplayRole (fixture._sut, 0, 5, 
    checkDisplayRole (fixture._sut, 0, 6, QVariant (3), "index(1,6)");
    //    checkDisplayRole (fixture._sut, 0, 7, QVariant (3), "index(1,6)");
    //
    checkDisplayRole (fixture._sut, 1, 1, QVariant (serie2.name ()),
                      "index (2,1)");
    checkDisplayRole (fixture._sut, 1, 2, QVariant (serie2.season ()),
                      "index (2,2)");
    checkDisplayRole (fixture._sut, 1, 3, QVariant (serie2.lastEpisode ()),
                      "index (2,3)");
    checkDisplayRole (fixture._sut, 1, 4, QVariant ("Unknown"), "index(2,4)");
    checkDisplayRole (fixture._sut, 1, 5, QVariant ("Unknown"), "index(2,5)");
    checkDisplayRole (fixture._sut, 1, 6, QVariant ("Unknown"), "index(2,6)");
    checkDisplayRole (fixture._sut, 1, 7, QVariant ("Unknown"), "index(2,7)");
    //
    checkDisplayRole (fixture._sut, 9, 0, QVariant (), "invalid index");
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

    checkHeaderData (fixture._sut, 1, Qt::Horizontal, Qt::DisplayRole, "Name", "Name");
    checkHeaderData (fixture._sut, 2, Qt::Horizontal, Qt::DisplayRole, "Season", "Season");
    checkHeaderData (fixture._sut, 3, Qt::Horizontal, Qt::DisplayRole, "Last Episode Downloaded",
                     "Last episode");
    checkHeaderData (fixture._sut, 4, Qt::Horizontal, Qt::DisplayRole, "Last Aired Episode", 
                     "Last Aire Episode");
    checkHeaderData (fixture._sut, 5, Qt::Horizontal, Qt::DisplayRole, "Last Aired Episode Date", 
                     "Last Aire Episode Date");
    checkHeaderData (fixture._sut, 6, Qt::Horizontal, Qt::DisplayRole, "Next Aired Episode", 
                     "Next Aire Episode");
    checkHeaderData (fixture._sut, 7, Qt::Horizontal, Qt::DisplayRole, "Next Aired Episode Date", 
                     "Next Aire Episode Date");
    
    checkHeaderData (fixture._sut, 1, Qt::Horizontal, Qt::DecorationRole, "", "Decoration Role");
    checkHeaderData (fixture._sut, 1, Qt::Vertical, Qt::DecorationRole, "", "Vertical");
    checkHeaderData (fixture._sut, -1, Qt::Horizontal, Qt::DecorationRole, "", "Invalid Section");
}

