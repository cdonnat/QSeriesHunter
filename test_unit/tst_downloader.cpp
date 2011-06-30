#include <QtTest>

#include "downloader.h"

#include "stub_defaultapprunner.h"
#include "stub_networkaccess.h"
#include "tst_downloader.h"

TestDownloader::TestDownloader()
{
    this->_networkAccess    = new NetworkAccessStub();
    this->_defaultAppRunner = new DefaultAppRunnerStub();
    this->_sut              = new Downloader(this->_networkAccess,
                                             this->_defaultAppRunner);
}

TestDownloader::~TestDownloader()
{
    delete this->_sut;
    delete this->_networkAccess;
    delete this->_defaultAppRunner;
}

void TestDownloader::testNominalCase()
{
    TestDownloader fixture;
    QString        urlToRead = "http://ca.isohunt.com/download/13555522/c.torrent";

    fixture._networkAccess->setContent("Torrent");
    fixture._networkAccess->setIsReady(true);
    fixture._sut->downloadTorrent (urlToRead);

    QVERIFY2(fixture._networkAccess->url() == urlToRead, "Correct url");
    QVERIFY2(fixture._sut->downloadIsSuccessful (), "Download is successful");

    fixture._sut->runTorrentWithExternalDefaultApp ();
    QVERIFY2(QFile::exists (fixture._defaultAppRunner->_absoluteFileName),
             "Torrent file created");
}

void TestDownloader::testFailCase()
{
    TestDownloader fixture;

    fixture._networkAccess->setIsReady(false);
    fixture._sut->downloadTorrent ("http:://whatever");

    QVERIFY2(!fixture._sut->downloadIsSuccessful (),
             "Download is not successful");
}
