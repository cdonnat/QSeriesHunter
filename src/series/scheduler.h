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
    explicit Scheduler(ISeriesController       * const seriesController,
                       TorrentFinderController * const finder,
                       Downloader              * const downloader,
                       ILogger                 * const logger);

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
    ISeriesController       * const _seriesController;
    TorrentFinderController * const _finder;
    Downloader              * const _downloader;
    ILogger                 * const _logger;
};

#endif // SCHEDULER_H
