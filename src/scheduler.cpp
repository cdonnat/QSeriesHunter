#include "scheduler.h"

#include "log.h"
#include "ilogger.h"
#include "serie.h"
#include "seriesmodel.h"
#include "torrentfindercontroller.h"
#include "downloader.h"

#include <QObject>

//----------------------------------------------------------------------------------------------
Scheduler::Scheduler(ISeriesController       * seriesController,
                     TorrentFinderController * finder,
                     Downloader              * downloader,
                     ILogger                 * logger)
    : _seriesController(seriesController),
      _finder(finder),
      _downloader(downloader),
      _logger(logger)
{
    Q_ASSERT (seriesController != NULL);
    Q_ASSERT (finder != NULL);
    Q_ASSERT (downloader != NULL);
    Q_ASSERT (logger != NULL);
}


//----------------------------------------------------------------------------------------------
void Scheduler::update ()
{
    _logger->logInfo (startLooking);
    if (_seriesController->nbSeries () > 0)
    {
        lookForNewEpisodes ();
    }
    else
    {
        _logger->logWarning (noSeriesFollowed);
    }
    _logger->logInfo (endLooking);
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
void Scheduler::lookForNewEpisode (const Serie & serie)
{
    const QString episodeName = QObject::tr("%1 Season %2 Episode %3")
            .arg(serie.name ())
            .arg(serie.season ())
            .arg(serie.nextEpisode ());

    _logger->logInfo (QObject::tr ("Looking for %1 ...").arg (episodeName));

    _finder->searchNextEpisode (serie);
    if (_finder->nextEpisodeIsFound ())
    {
        _logger->logSuccess (QObject::tr ("%1 found").arg (episodeName));
        _downloader->downloadTorrent (_finder->getNextEpisodeUrl ());
        if (_downloader->downloadIsSuccessful ())
        {
            _downloader->downloadSerie ();
            _seriesController->inc (serie);
            _logger->logSuccess (QObject::tr ("%1 download started").arg (episodeName));
        }
    }
    else
    {
        _logger->logInfo (QObject::tr ("%1 not found").arg (episodeName));
    }
}
