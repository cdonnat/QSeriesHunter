#include "tst_isohunt.h"

#include "isohunt.h"
#include "stub_networkaccess.h"

#include <QtTest>
#include <QString>

TestIsohunt::TestIsohunt()
{
    this->_networkAccess = new NetworkAccessStub;
    this->_sut           = new Isohunt(this->_networkAccess);
}

QString  getJsonInput()
{
    QFile  input (":input/json_input.txt");
    input.open(QIODevice::ReadOnly);
    return input.readAll();
}

TestIsohunt::~TestIsohunt()
{
    delete this->_sut;
    delete this->_networkAccess;
}

void TestIsohunt::testRequestFailed()
{
    TestIsohunt   fixture;
    FinderResults results;

    fixture._sut->find("How I Met Your Mother");
    results = fixture._sut->getResults();
    QVERIFY2(results.isEmpty(), "Empty list");
}

void TestIsohunt::nominalCase ()
{
    this->_networkAccess->setContent(getJsonInput());
    this->_networkAccess->setIsReady(true);

    this->_sut->find("How I Met Your Mother");
    FinderResults results = this->_sut->getResults();

    QVERIFY2(this->_networkAccess->url() ==
             "http://ca.isohunt.com/js/json.php?ihq=How+I+Met+Your+Mother",
             "Expected request");

    QVERIFY2(results.size() == 100, "Results are retrieved");
    QVERIFY2(results.front().name() == "<b>HIMYM</b> - Season 1",
             "Expected name");
    QVERIFY2(results.front().url() ==
             "http://ca.isohunt.com/download/29646977/himym.torrent",
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
    fixture._networkAccess->setIsReady(true);

    fixture._sut->find("House");

    FinderResults results = fixture._sut->getResults();

    QVERIFY2(fixture._networkAccess->url() ==
             "http://ca.isohunt.com/js/json.php?ihq=House",
             "Expected request");
    QVERIFY2(results.isEmpty(), "Empty list");
}

void TestIsohunt::testCorruptedJsonContent()
{
    TestIsohunt fixture;
    fixture._networkAccess->setContent ("title:");
    fixture._networkAccess->setIsReady(true);

    fixture._sut->find("House");

    QVERIFY2(fixture._networkAccess->url() ==
             "http://ca.isohunt.com/js/json.php?ihq=House",
             "Expected request");
}
