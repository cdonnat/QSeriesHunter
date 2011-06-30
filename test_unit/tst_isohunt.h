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
    void testRequestFailed();
    void testNominalCaseTwice();
    void testEmptyJsonContent();
    void testCorruptedJsonContent();

private:
    void nominalCase();

private :
    NetworkAccessStub  * _networkAccess;
    Isohunt            * _sut;
};

#endif // TESTISOHUNT_H
