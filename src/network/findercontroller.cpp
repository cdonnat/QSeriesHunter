#include "findercontroller.h"
#include "regexpprovider_se.h"
#include "regexpprovider_x.h"

#include "serie.h"

//----------------------------------------------------------------------------------------------
bool greaterThan (const FinderResult & l, const FinderResult & r)
{
    return l.seed () > r.seed ();
}

//----------------------------------------------------------------------------------------------
FinderController::FinderController():_episodeIsFound(false)
{
    _regExpProviders << new RegExpProvider_Se;
    _regExpProviders << new RegExpProvider_X;
    _typeAuthorized.insert("Torrent", true);
    _typeAuthorized.insert("DirectDownload", false);
}

//----------------------------------------------------------------------------------------------
void FinderController::addFinder (AbstractFinder * finder)
{
    Q_ASSERT (finder);
    _finders.insert (finder);
}

//----------------------------------------------------------------------------------------------
void FinderController::enable (const QString &  finderType, bool isEnable)
{
    Q_ASSERT(_typeAuthorized.contains (finderType));
    _typeAuthorized[finderType] = isEnable;
}

//----------------------------------------------------------------------------------------------
bool FinderController::isEnabled (const QString & finderType)
{
    Q_ASSERT(_typeAuthorized.contains (finderType));
    return _typeAuthorized[finderType];
}

//----------------------------------------------------------------------------------------------
void FinderController::findNextEpisode (const Serie & serie)
{
    Q_ASSERT(isEnabled("Torrent") || isEnabled("DirectDownload"));
    this->reset();
    this->findNextEpisodeInAllFinders (serie);
    this->sortResultsBySeed ();
    this->findBestMatch (serie);
}

//----------------------------------------------------------------------------------------------
void FinderController::reset ()
{
    _episodeIsFound = false;
    _results.clear ();
}

//----------------------------------------------------------------------------------------------
void FinderController::findNextEpisodeInAllFinders(const Serie & serie)
{
    foreach (AbstractFinder * finder, _finders) {
        if (_typeAuthorized [finder->getType()]) {
            foreach (RegExpProvider * regExpProvider,_regExpProviders) {
                finder->find (regExpProvider->getFindRegExp(serie, serie.lastEpisode() + 1));
                _results.append (finder->getResults ());
            }
        }
    }
}

//----------------------------------------------------------------------------------------------
void FinderController::findBestMatch (const Serie & serie)
{
    _episodeIsFound = false;
    
    foreach(FinderResult res, _results) {
        
        foreach (RegExpProvider * regExpProvider, _regExpProviders) {
            _episodeIsFound = _episodeIsFound || 
                              regExpProvider->resultIsMatching(serie, 
                                                               serie.lastEpisode() + 1, 
                                                               res.name ());
        }
        
        if (_episodeIsFound) {
            _url            = res.url ();
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------
void FinderController::sortResultsBySeed ()
{
    qSort (_results.begin (), _results.end (), greaterThan);
}


//----------------------------------------------------------------------------------------------
bool FinderController::episodeIsFound () const
{
    return _episodeIsFound;
}

//----------------------------------------------------------------------------------------------
const QString & FinderController::getEpisodeUrl () const
{
    Q_ASSERT (this->episodeIsFound ());
    return _url;
}

//----------------------------------------------------------------------------------------------
FindersMemento FinderController::createMemento() const
{
    return FindersMemento(_typeAuthorized["Torrent"], _typeAuthorized["DirectDownload"]);
}


//----------------------------------------------------------------------------------------------
void FinderController::loadFrom (const FindersMemento & memento)
{
    enable ("Torrent", memento.isTorrentEnable());
    enable ("DirectDownload", memento.isDirectDownloadEnable());
}

