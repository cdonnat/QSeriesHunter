#ifndef SCHEDULER_H
#define SCHEDULER_H

class Downloader;
class ILogger;
class ISeriesController;
class Serie;
class TorrentFinderController;

class Scheduler
{
public:

    //----------------------------------------------------------------------------------------------
    // Constructors
    // [Inputs are not null.]
    explicit Scheduler(ISeriesController       * seriesController,
                       TorrentFinderController * finder,
                       Downloader              * downloader,
                       ILogger                 * logger);

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Loop on each serie and try to download the next episode.]
    void update ();

private:

    //----------------------------------------------------------------------------------------------
    // REQ [At least one serie is followed.]
    // ENS [Try to download next episode of each serie.]
    void lookForNewEpisodes();

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Try to download next episode of the given serie.]
    void lookForNewEpisode (const Serie & serie);

private:
    ISeriesController       * _seriesController;
    TorrentFinderController * _finder;
    Downloader              * _downloader;
    ILogger                 * _logger;
};

#endif // SCHEDULER_H
