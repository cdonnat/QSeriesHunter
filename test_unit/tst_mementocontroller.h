#ifndef TST_MEMENTOCONTROLLER_H
#define TST_MEMENTOCONTROLLER_H

#include <QObject>

#include "mementocontroller.h"
#include "seriescontroller.h"

class TestMementoController : public QObject
{
    Q_OBJECT
public:
    explicit TestMementoController(QObject *parent = 0);

private Q_SLOTS:
    virtual void initTestCase();
    void testCase();
    virtual void cleanUpTestCase();

private:
    SeriesController   _series;
    MementoController  _sut;
};

#endif // TST_MEMENTOCONTROLLER_H
