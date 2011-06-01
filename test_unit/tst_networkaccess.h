#ifndef TST_NETWORKACCESS_H
#define TST_NETWORKACCESS_H

#include <QObject>

#include "networkaccess.h"

class TestNetworkAccess: public QObject
{
    Q_OBJECT

public:
    TestNetworkAccess();

private Q_SLOTS:
    void TestCase();

private:
    NetworkAccess  sut;
};

#endif // TST_NETWORKACCESS_H
