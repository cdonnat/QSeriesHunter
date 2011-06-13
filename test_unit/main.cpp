#include <QtTest>
#include <QCoreApplication>

#include "tst_networkaccess.h"
#include "tst_downloader.h"
#include "tst_isohunt.h"
#include "tst_serie.h"
#include "tst_torrentfindercontroller.h"
#include "tst_seriescontroller.h"
#include "tst_seriesmodel.h"
#include "tst_scheduler.h"

int main(int argc, char *argv[])
{
     QCoreApplication app(argc, argv);

     return QTest::qExec (new TestNetworkAccess) ||
            QTest::qExec (new TestDownloader) ||
            QTest::qExec (new TestIsohunt) ||
            QTest::qExec (new TestSerie) ||
            QTest::qExec (new TestTorrentFinderController) ||
            QTest::qExec (new TestSeriesController) ||
            QTest::qExec (new TestSeriesModel) ||
            QTest::qExec (new TestScheduler);
}
