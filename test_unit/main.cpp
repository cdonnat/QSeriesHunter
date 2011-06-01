#include <QtTest>
#include <QCoreApplication>

#include "tst_networkaccess.h"
#include "tst_torrentdownloader.h"
#include "tst_isohunt.h"
#include "tst_serie.h"

int main(int argc, char *argv[])
{
     QCoreApplication app(argc, argv);

    return QTest::qExec(new TestNetworkAccess) ||
           QTest::qExec(new TestTorrentDownloader) ||
           QTest::qExec(new TestIsohunt) ||
           QTest::qExec (new TestSerie);
}
