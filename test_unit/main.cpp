#include <QtTest>
#include <QApplication>

#include "tst_networkaccess.h"
#include "tst_downloader.h"
#include "tst_isohunt.h"
#include "tst_serie.h"
#include "tst_findercontroller.h"
#include "tst_seriescontroller.h"
#include "tst_seriesmodel.h"
#include "tst_scheduler.h"
#include "tst_editserie.h"
#include "tst_mementocontroller.h"
#include "tst_serieswidget.h"
#include "tst_mainwindow.h"
#include "tst_filestube.h"

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);

     return QTest::qExec (new TestNetworkAccess) ||
            QTest::qExec (new TestDownloader) ||
            QTest::qExec (new TestIsohunt) ||
            QTest::qExec (new TestSerie) ||
            QTest::qExec (new TestFinderController) ||
            QTest::qExec (new TestSeriesController) ||
            QTest::qExec (new TestSeriesModel) ||
            QTest::qExec (new TestScheduler) ||
            QTest::qExec (new TestEditSerie) ||
            QTest::qExec (new TestMementoController) ||
            QTest::qExec (new TestMainWindow) ||
            QTest::qExec (new TestSeriesWidget) ||
            QTest::qExec (new TestFilesTube);
}
