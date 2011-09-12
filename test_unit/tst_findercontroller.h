#ifndef TST_TORRENTFINDERCONTROLLER_H
#define TST_TORRENTFINDERCONTROLLER_H

#include <QObject>

#include "findercontroller.h"
#include "stub_finder.h"

class TestFinderController : public QObject
{
    Q_OBJECT
public:
    explicit TestFinderController(QObject *parent = 0);

private slots:
    void testInitialResult();
    void testNominalCase();
    void testRequestSent();
    void testSerieWithSpaces();
    void testRegExp();

private:
    FinderStub           _finder1, _finder2;
    FinderController     _sut;
};

#endif // TST_TORRENTFINDERCONTROLLER_H
