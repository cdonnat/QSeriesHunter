#include <QTest>
#include <QNetworkConfiguration>
#include "tst_networkaccess.h"

TestNetworkAccess::TestNetworkAccess()
{
}

void TestNetworkAccess::TestCase()
{
    TestNetworkAccess  fixture;

    QVERIFY2 (!fixture.sut.contentIsReady(), "Initial content is ready");

    fixture.sut.read("http://www.google.fr");
    QVERIFY2 (fixture.sut.contentIsReady(), "Content is ready with correct site");
    QVERIFY2 (fixture.sut.content() != "", "Content of correct site");

    fixture.sut.read("localhost");
    QVERIFY2 (!fixture.sut.contentIsReady(), "Content is not ready with wrong site");
}
