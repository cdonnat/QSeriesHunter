#ifndef SCHEDULER_H
#define SCHEDULER_H

class ILogger;
class Serie;
class SeriesModel;
class TorrentFinderController;
class Downloader;

class Scheduler
{
public:

    //----------------------------------------------------------------------------------------------
    // Constructors
    explicit Scheduler(SeriesModel             * seriesModel,
                       TorrentFinderController * finder,
                       Downloader       * downloader,
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
    SeriesModel             * _seriesModel;
    TorrentFinderController * _finder;
    Downloader       * _downloader;
    ILogger                 * _logger;
};

#endif // SCHEDULER_H
