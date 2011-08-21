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
// REQ [None.]
// ENS [Name is returne for matching (ex: The Event -> The.*Event)]
QString getNameForMatch (const Serie & serie)
{
    return QRegExp::escape (serie.name ()).replace (' ', ".*");
}

//----------------------------------------------------------------------------------------------
TorrentFinderController::TorrentFinderController():_episodeIsFound(false)
{
    _regExpProviders << new RegExpProvider_Se;
    _regExpProviders << new RegExpProvider_X;
    _regExp.setCaseSensitivity (Qt::CaseInsensitive);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::addTorrentFinder (ITorrentFinder * torrentFinder)
{
    Q_ASSERT (torrentFinder);
    _finders.insert (torrentFinder);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findEpisode (const Serie & serie, uint episode)
{
    this->reset();
    this->findEpisodeInAllFinders (serie, episode);
    this->findBestMatch (serie, episode);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::reset ()
{
    _episodeIsFound = false;
    _results.clear ();
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findEpisodeInAllFinders(const Serie & serie, uint episode)
{
    foreach (ITorrentFinder * finder, _finders) {
        foreach (RegExpProvider * regExpProvider, _regExpProviders) {
            finder->find (regExpProvider->getFindRegExp(serie, episode));
            _results.append (finder->getResults ());

        }
    }
    sortResultsBySeed ();
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findBestMatch (const Serie & serie, uint episode)
{
    _regExp.setPattern (QString(".*%1.*%2.*%3.*")
                        .arg (getNameForMatch (serie))
                        .arg (serie.season ())
                        .arg (episode));

    foreach(TorrentFinderResult res, _results) {
        _episodeIsFound =_regExp.exactMatch (res.name ());
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
