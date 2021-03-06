#ifndef TST_SCHEDULER_H
#define TST_SCHEDULER_H

#include <QObject>

class Scheduler;
class SeriesModel;
class FinderController;
class DefaultAppRunnerStub;
class Downloader;
class LoggerStub;
class NetworkAccessStub;
class FinderStub;
class SeriesProviderStub;

class TestScheduler : public QObject
{
    Q_OBJECT
public:
    explicit TestScheduler(QObject *parent = 0);

private Q_SLOTS:
    void testNoSeries();
    void testNominalTorrent();
    void testNominalDdl();
    void testNoNewEpisode();
    void testFail();

private:
    Scheduler                * _sut;
    SeriesModel              * _series;
    FinderController         * _finders;
    DefaultAppRunnerStub     * _serieDownloader;
    Downloader               * _downloader;
    LoggerStub               * _logger;
    NetworkAccessStub        * _network;
    FinderStub               * _finder;
    SeriesProviderStub       * _seriesProvider;
};

#endif // TST_SCHEDULER_H
