#ifndef TESTISOHUNT_H
#define TESTISOHUNT_H

#include <QObject>

class Isohunt;
class NetworkAccessStub;

class TestIsohunt: public QObject
{
    Q_OBJECT

public:
    TestIsohunt();
    ~TestIsohunt();

private Q_SLOTS:
    void testNominalCase();
    void testFailCase();

private :
    NetworkAccessStub  * networkAccess;
    Isohunt            * sut;
};

#endif // TESTISOHUNT_H
