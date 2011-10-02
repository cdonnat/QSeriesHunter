#include "tst_filestube.h"

#include "filestube.h"
#include "stub_networkaccess.h"

#include <QtTest>
#include <QString>
#include <QDebug>

TestFilesTube::TestFilesTube()
{
    this->_networkAccess = new NetworkAccessStub;
    this->_sut           = new FilesTube(this->_networkAccess);
}

const QString request = "http://api.filestube.com/?key=ff5286516f86965dadfeb44bc87d4c36&sort=dd&phrase=";

QString  geXmlInput()
{
    QFile  input (":input/xml_input.xml");
    input.open(QIODevice::ReadOnly);
    return input.readAll();
}

TestFilesTube::~TestFilesTube()
{
    delete this->_sut;
    delete this->_networkAccess;
}

void TestFilesTube::testRequestFailed()
{
    TestFilesTube   fixture;
    FinderResults results;

    fixture._sut->find("How I Met Your Mother");
    results = fixture._sut->getResults();
    QVERIFY2(results.isEmpty(), "List should be empty");
}

void TestFilesTube::nominalCase ()
{
    this->_networkAccess->setContent(geXmlInput());
    this->_networkAccess->setIsReady(true);

    this->_sut->find("ubuntu");
    FinderResults results = this->_sut->getResults();

    QVERIFY2(this->_networkAccess->url() ==
             "http://api.filestube.com/?key=ff5286516f86965dadfeb44bc87d4c36&sort=dd&phrase=ubuntu",
             "Expected request");

    QVERIFY2(results.size() == 10, "Results are retrieved");
    QVERIFY2(results.front().name() == "ubuntu",
             "Expected name");
    QVERIFY2(results.front().url() ==
             "http://www.filestube.com/feef0ae28c89dbe403e9/go.html",
             "Expected url");
    QVERIFY2(results.front().seed() == 0, "Expected number of seed");
}

void TestFilesTube::testNominalCaseTwice()
{
    TestFilesTube fixture;
    fixture.nominalCase ();
    fixture.nominalCase ();
}

void TestFilesTube::testEmptyXmlContent()
{
    TestFilesTube fixture;
    fixture._networkAccess->setIsReady(true);

    fixture._sut->find("House");

    FinderResults results = fixture._sut->getResults();

    QVERIFY2(fixture._networkAccess->url() ==
             request + "House",
             "Expected request");
    QVERIFY2(results.isEmpty(), "Empty list");
}

void TestFilesTube::testCorruptedXmlContent()
{
    TestFilesTube fixture;
    fixture._networkAccess->setContent ("<answer> <hasResults");
    fixture._networkAccess->setIsReady(true);

    fixture._sut->find("House");

    QVERIFY2(fixture._networkAccess->url() == request + "House", "Expected request");
}

