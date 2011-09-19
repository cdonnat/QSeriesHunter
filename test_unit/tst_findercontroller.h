#ifndef TST_TORRENTFINDERCONTROLLER_H
#define TST_TORRENTFINDERCONTROLLER_H

#include <QObject>

#include "findercontroller.h"
#include "stub_finder.h"

class TestFinderController : public QObject
{
    Q_OBJECT
public:
    explicit TestFinderController(const QString & finder1Type = "Torrent",
                                  const QString & finder2Type = "Torrent",
                                  QObject *parent = 0);

private slots:
    void testInitialResult();
    void testNominalCase();
    void testRequestSent();
    void testSerieWithSpaces();
    void testRegExp();
    void testFinderSelection();

private:
    FinderStub           _finder1, _finder2;
    FinderController     _sut;
    
    void exercizeAndCheckFinderSelection
    (bool torrentShouldBeEmpty,
     bool ddlShouldBeEmpty,
     const QString & comment);
};

#endif // TST_TORRENTFINDERCONTROLLER_H
