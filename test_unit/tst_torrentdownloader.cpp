#include <QtTest>

#include "torrentdownloader.h"

#include "stub_networkaccess.h"
#include "tst_torrentdownloader.h"

TestTorrentDownloader::TestTorrentDownloader()
{
    this->networkAccess  = new NetworkAccessStub();
    this->sut            = new TorrentDownloader(this->networkAccess, NULL);   
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
    fixture.sut->download(urlToRead);

    QVERIFY2(fixture.networkAccess->url() == urlToRead,
             "Correct url");
}
