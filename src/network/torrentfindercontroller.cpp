#include "torrentfindercontroller.h"
#include "regexpprovider_se.h"
#include "regexpprovider_x.h"

#include "serie.h"

//----------------------------------------------------------------------------------------------
bool greaterThan (const TorrentFinderResult & l, const TorrentFinderResult & r)
{
    return l.seed () > r.seed ();
}

//----------------------------------------------------------------------------------------------
TorrentFinderController::TorrentFinderController():_episodeIsFound(false)
{
    _regExpProviders << new RegExpProvider_Se;
    _regExpProviders << new RegExpProvider_X;
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::addTorrentFinder (ITorrentFinder * torrentFinder)
{
    Q_ASSERT (torrentFinder);
    _finders.insert (torrentFinder);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findNextEpisode (const Serie & serie)
{
    this->reset();
    this->findNextEpisodeInAllFinders (serie);
    this->sortResultsBySeed ();
    this->findBestMatch (serie);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::reset ()
{
    _episodeIsFound = false;
    _results.clear ();
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findNextEpisodeInAllFinders(const Serie & serie)
{
    foreach (ITorrentFinder * finder, _finders) {
        foreach (RegExpProvider * regExpProvider, _regExpProviders) {
            finder->find (regExpProvider->getFindRegExp(serie, serie.lastEpisode() + 1));
            _results.append (finder->getResults ());

        }
    }
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findBestMatch (const Serie & serie)
{
    _episodeIsFound = false;
    
    foreach(TorrentFinderResult res, _results) {
        
        foreach (RegExpProvider * regExpProvider, _regExpProviders) {
            _episodeIsFound = _episodeIsFound || 
                              regExpProvider->resultIsMatching(serie, serie.lastEpisode() + 1, res.name ());
        }
        
        if (_episodeIsFound) {
            _url            = res.url ();
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::sortResultsBySeed ()
{
    qSort (_results.begin (), _results.end (), greaterThan);
}


//----------------------------------------------------------------------------------------------
bool TorrentFinderController::episodeIsFound () const
{
    return _episodeIsFound;
}

//----------------------------------------------------------------------------------------------
const QString & TorrentFinderController::getEpisodeUrl () const
{
    Q_ASSERT (this->episodeIsFound ());
    return _url;
}
