#include "tst_serieswidget.h"
#include "stub_logger.h"

#include <QTest>
#include <QSignalSpy>

TestSeriesWidget::TestSeriesWidget(QObject *parent) :
    QObject(parent)
{
    _sut = new SeriesWidget(new LoggerStub, "test.ini");
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