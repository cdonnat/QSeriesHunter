#ifndef TST_SERIESPROVIDER_H
#define TST_SERIESPROVIDER_H

#include <QObject>

class NetworkAccessStub;
class SeriesProvider;

class TestSeriesProvider : public QObject
{
    Q_OBJECT

public:
    TestSeriesProvider();
    virtual ~TestSeriesProvider();

private Q_SLOTS:
    void testNominalCase();
    void testFailCase();
    void testNextAiredEpisode();
    void testLastAiredEpisode();
    void testNextAiredEpisodeRobustness();
    
private :
    NetworkAccessStub    * _networkAccess;
    SeriesProvider       * _sut;
};

#endif // TST_SERIESPROVIDER_H
