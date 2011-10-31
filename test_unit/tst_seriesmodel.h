#ifndef TST_SERIESMODEL_H
#define TST_SERIESMODEL_H

#include <QObject>

#include "seriesmodel.h"

class SeriesProviderStub;

class TestSeriesModel : public QObject
{
    Q_OBJECT
public:
    explicit TestSeriesModel(QObject *parent = 0);

private slots:
    void testRows();
    void testColumns();
    void testData();
    void testHeaderData();

private:
    SeriesProviderStub * _seriesProvider;
    SeriesModel          _sut;
};

#endif // TST_SERIESMODEL_H
