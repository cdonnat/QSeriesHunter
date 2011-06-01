#include <QtTest>

#include "torrentdownloader.h"

#include "stub_networkaccess.h"
#include "tst_torrentdownloader.h"

TestTorrentDownloader::TestTorrentDownloader()
{
    this->networkAccess  = new NetworkAccessStub();
    this->sut            = new TorrentDownloader(this->networkAccess, NULL);
    this->fileName       = "torrentProviderTest.txt";
    QFile::remove(this->fileName);
}

TestTorrentDownloader::~TestTorrentDownloader()
{
    delete this->sut;
    delete this->networkAccess;
}

void TestTorrentDownloader::testNominalCase()
{
    TestTorrentDownloader fixture;
    QString               urlToRead = "http://ca.isohunt.com/download/13555522/c.torrent";

    fixture.networkAccess->setContent("Torrent");
    fixture.networkAccess->setIsReady(true);
    fixture.sut->download(urlToRead, fixture.fileName);

    QVERIFY2(QFile::exists(fixture.fileName), "File successfully downloaded");
    QVERIFY2(fixture.networkAccess->url() == urlToRead,
             "Correct url");
}

void TestTorrentDownloader::testFailCase()
{
    TestTorrentDownloader fixture;

    fixture.sut->download("", fixture.fileName);

    QVERIFY2(!QFile::exists(fixture.fileName), "File download failed");
}
