#ifndef TST_SERIESWIDGET_H
#define TST_SERIESWIDGET_H

#include <QObject>

#include "serieswidget.h"

class TestSeriesWidget : public QObject
{
    Q_OBJECT
public:
    explicit TestSeriesWidget(QObject *parent = 0);

private slots:
    void testUpdate();

private:
    SeriesWidget * _sut;
};

#endif // TST_SERIESWIDGET_H
