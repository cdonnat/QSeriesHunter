#include "scheduler.h"

#include "log.h"
#include "ilogger.h"
#include "serie.h"
#include "seriesmodel.h"
#include "findercontroller.h"
#include "downloader.h"

#include <QObject>

//----------------------------------------------------------------------------------------------
Scheduler::Scheduler(ISeriesController       * const seriesController,
                     FinderController        * const finder,
                     Downloader              * const downloader,
                     ILogger                 * const logger)
    : _seriesController(seriesController),
      _finder(finder),
      _downloader(downloader),
      _logger(logger)
{
    Q_ASSERT (_seriesController != NULL);
    Q_ASSERT (_finder != NULL);
    Q_ASSERT (_downloader != NULL);
    Q_ASSERT (_logger != NULL);
}


//----------------------------------------------------------------------------------------------
void Scheduler::update ()
{
    _logger->logInfo (QObject::tr ("Start updating..."));
    if (_seriesController->nbSeries () > 0) {
        lookForNewEpisodes ();
    }
    else {
        _logger->logWarning (noSeriesFollowed);
    }
    _logger->logInfo (QObject::tr ("Updating finished!"));
}

//----------------------------------------------------------------------------------------------
void Scheduler::lookForNewEpisodes()
{
    Q_ASSERT (_seriesController->nbSeries () > 0);
    for (uint i = 0; i < _seriesController->nbSeries (); ++i)
    {
        lookForNewEpisode (_seriesController->at (i));
    }
}

//----------------------------------------------------------------------------------------------
QString Scheduler::nextEpisodeFullName(const Serie & serie)
{
    return  QObject::tr("%1 Season %2 Episode %3")
            .arg(serie.name ())
            .arg(serie.season ())
            .arg(serie.lastEpisode () + 1);
}

//----------------------------------------------------------------------------------------------
void Scheduler::tryToDownloadEpisode (const Serie & serie)
{
    Q_ASSERT(_finder->episodeIsFound());
    
    if (_finder->episodeFoundIsFromTorrent()) {
        _downloader->downloadTorrent (_finder->getEpisodeUrl ());
    
        if (_downloader->downloadIsSuccessful ()) {
            _downloader->runTorrentWithExternalDefaultApp ();
            _logger->logSuccess (QObject::tr ("%1 download started")
                                 .arg (nextEpisodeFullName(serie)));
            _seriesController->inc (serie);
        }
    }
    else
    {
        _logger->logInfo(_finder->getEpisodeUrl());
        _seriesController->inc (serie);
    }
}


//----------------------------------------------------------------------------------------------
void Scheduler::lookForNewEpisode (const Serie & serie)
{
    _logger->logInfo (QObject::tr ("Looking for %1 ...").arg (nextEpisodeFullName(serie)));
    _finder->findNextEpisode (serie);

    if (_finder->episodeIsFound ()) {
        _logger->logSuccess (QObject::tr ("%1 found").arg (nextEpisodeFullName(serie)));
        tryToDownloadEpisode(serie);
    }
    else {
        _logger->logInfo (QObject::tr ("%1 not found").arg (nextEpisodeFullName(serie)));
    }
}
