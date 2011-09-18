#ifndef TESTFILESTUBE_H
#define TESTFILESTUBE_H

#include <QObject>

class FilesTube;
class NetworkAccessStub;

class TestFilesTube: public QObject
{
    Q_OBJECT

public:
    TestFilesTube();
    ~TestFilesTube();

private Q_SLOTS:
    void testRequestFailed();
    void testNominalCaseTwice();
    void testEmptyXmlContent();
    void testCorruptedXmlContent();

private:
    void nominalCase();

private :
    NetworkAccessStub  * _networkAccess;
    FilesTube          * _sut;
};

#endif // TESTFILESTUBE_H
