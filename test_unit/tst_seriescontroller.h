#ifndef TST_SERIESCONTROLLER_H
#define TST_SERIESCONTROLLER_H

#include <QObject>

#include "seriescontroller.h"

class SeriesProviderStub;

class TestSeriesController : public QObject
{
    Q_OBJECT
public:
    explicit TestSeriesController(QObject *parent = 0);

private slots:
    void test ();
    void testRobustness ();
    void testAiredEpisode ();
    void testNoAiredEpisodeDetails ();
    
private :
    SeriesProviderStub * _seriesProvider;
    SeriesController   * _sut;
};

#endif // TST_SERIESCONTROLLER_H
