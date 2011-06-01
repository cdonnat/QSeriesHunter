#include "tst_isohunt.h"

#include "isohunt.h"
#include "stub_networkaccess.h"

#include <QtTest>
#include <QString>

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

void TestIsohunt::testNominalCase()
{
    TestIsohunt fixture;

    fixture.networkAccess->setContent(getJsonInput());
    fixture.networkAccess->setIsReady(true);

    fixture.sut->search("How I Met Your Mother");

    TorrentFinderResults results = fixture.sut->getResults();

    QVERIFY2(fixture.networkAccess->url() == "http://ca.isohunt.com/js/json.php?ihq=How+I+Met+Your+Mother",
             "Expected request");
    QVERIFY2(!results.isEmpty(), "Results are retrieved");
    QVERIFY2(results.front().name() == "<b>HIMYM</b> - Season 1",
             "Expected name");
    QVERIFY2(results.front().url() == "http://ca.isohunt.com/download/29646977/himym.torrent",
             "Expected url");
    QVERIFY2(results.front().seed() == 133, "Expected number of seed");
}

void TestIsohunt::testFailCase()
{}
