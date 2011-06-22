#include "tst_isohunt.h"

#include "isohunt.h"
#include "stub_networkaccess.h"

#include <QtTest>
#include <QString>
#include <QDebug>

TestIsohunt::TestIsohunt()
{
    this->networkAccess = new NetworkAccessStub;
    this->sut           = new Isohunt(this->networkAccess);
}

QString  getJsonInput()
{
    QString path = QCoreApplication::applicationDirPath() +
                   "/../test_unit/input/json_input.txt";
    QFile  input (path);
    input.open(QIODevice::ReadOnly);
    return input.readAll();
}

TestIsohunt::~TestIsohunt()
{
    delete this->sut;
    delete this->networkAccess;
}

void TestIsohunt::testRequestFailed()
{
    TestIsohunt          fixture;
    TorrentFinderResults results;

    fixture.sut->search("How I Met Your Mother");
    results = fixture.sut->getResults();
    QVERIFY2(results.isEmpty(), "Empty list");
}

void TestIsohunt::nominalCase ()
{
    this->networkAccess->setContent(getJsonInput());
    this->networkAccess->setIsReady(true);

    this->sut->search("How I Met Your Mother");
    TorrentFinderResults results = this->sut->getResults();

    QVERIFY2(this->networkAccess->url() == "http://ca.isohunt.com/js/json.php?ihq=How+I+Met+Your+Mother",
             "Expected request");
    qDebug() << results.size ();
    QVERIFY2(results.size() == 100, "Results are retrieved");
    QVERIFY2(results.front().name() == "<b>HIMYM</b> - Season 1",
             "Expected name");
    QVERIFY2(results.front().url() == "http://ca.isohunt.com/download/29646977/himym.torrent",
             "Expected url");
    QVERIFY2(results.front().seed() == 133, "Expected number of seed");
}

void TestIsohunt::testNominalCaseTwice()
{
    TestIsohunt fixture;
    fixture.nominalCase ();
    fixture.nominalCase ();
}

void TestIsohunt::testEmptyJsonContent()
{
    TestIsohunt fixture;
    fixture.networkAccess->setIsReady(true);

    fixture.sut->search("House");

    TorrentFinderResults results = fixture.sut->getResults();

    QVERIFY2(fixture.networkAccess->url() == "http://ca.isohunt.com/js/json.php?ihq=House",
             "Expected request");
    QVERIFY2(results.isEmpty(), "Empty list");
}

void TestIsohunt::testCorruptedJsonContent()
{
    TestIsohunt fixture;
    fixture.networkAccess->setContent ("title:");
    fixture.networkAccess->setIsReady(true);

    fixture.sut->search("House");

    TorrentFinderResults results = fixture.sut->getResults();

    QVERIFY2(fixture.networkAccess->url() == "http://ca.isohunt.com/js/json.php?ihq=House",
             "Expected request");
}
