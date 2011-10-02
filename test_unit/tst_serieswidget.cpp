#include "tst_serieswidget.h"
#include "builder.h"

#include <QTest>
#include <QSignalSpy>

TestSeriesWidget::TestSeriesWidget(QObject *parent) :
    QObject(parent)
{
    Builder builder("init.txt");
    _sut = builder.getSeriesWidget();
}

void TestSeriesWidget::testUpdate()
{
    TestSeriesWidget fixture;
    
    QSignalSpy spyUpdateBegin(fixture._sut, SIGNAL(updateBegin()));
    QSignalSpy spyUpdateEnd(fixture._sut, SIGNAL(updateEnd()));
   
    fixture._sut->update();
    
    QVERIFY2(spyUpdateBegin.count() == 1, "Update begin");
    QVERIFY2(spyUpdateEnd.count() == 1, "Update end");   
}