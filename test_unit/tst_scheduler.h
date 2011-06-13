#ifndef TST_SCHEDULER_H
#define TST_SCHEDULER_H

#include <QObject>

class Scheduler;
class SeriesModel;
class TorrentFinderController;
class SerieDownloaderStub;
class Downloader;
class LoggerStub;
class NetworkAccessStub;
class TorrentFinderStub;

class TestScheduler : public QObject
{
    Q_OBJECT
public:
    explicit TestScheduler(QObject *parent = 0);

private Q_SLOTS:
    void testNoSeries();
    void testNominal();
    void testFail();

private:
    Scheduler                * _sut;
    SeriesModel              * _series;
    TorrentFinderController  * _finders;
    SerieDownloaderStub      * _serieDownloader;
    Downloader               * _downloader;
    LoggerStub               * _logger;
    NetworkAccessStub        * _network;
    TorrentFinderStub        * _finder;
};

#endif // TST_SCHEDULER_H
