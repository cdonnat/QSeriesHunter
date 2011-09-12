#ifndef SCHEDULER_H
#define SCHEDULER_H

class Downloader;
class ILogger;
class ISeriesController;
class Serie;
class FinderController;
class QString;

class Scheduler
{
public:

    //----------------------------------------------------------------------------------------------
    // Constructors
    // [Inputs are not null.]
    explicit Scheduler(ISeriesController       * const seriesController,
                       FinderController        * const finder,
                       Downloader              * const downloader,
                       ILogger                 * const logger);

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Loop on each serie and try to download the next episode.]
    void update ();

private:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Next episode full name of the serie is returned.
    //      If serie is House Season 1 and last episode seen is episode 3 then "House S01E04"
    //      will be returned.]
    QString nextEpisodeFullName(const Serie & serie);

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
    FinderController        * const _finder;
    Downloader              * const _downloader;
    ILogger                 * const _logger;
};

#endif // SCHEDULER_H
