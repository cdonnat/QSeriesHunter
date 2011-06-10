#ifndef TST_TORRENTFINDERCONTROLLER_H
#define TST_TORRENTFINDERCONTROLLER_H

#include <QObject>

#include "torrentfindercontroller.h"
#include "stub_torrentfinder.h"

class TestTorrentFinderController : public QObject
{
    Q_OBJECT
public:
    explicit TestTorrentFinderController(QObject *parent = 0);

private slots:
    void testInitialResult();
    void testNominalCase();
    void testRequestSent();
    void testSerieWithSpaces();

private:
    TorrentFinderStub         _finder1, _finder2;
    TorrentFinderController   _sut;
};

#endif // TST_TORRENTFINDERCONTROLLER_H
