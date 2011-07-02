#include "torrentfindercontroller.h"

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
// REQ [None.]
// ENS [Return format on 2 digits.]
QString toTwoDigits (uint number)
{
    return QString::number (number).rightJustified (2, '0');
}

//----------------------------------------------------------------------------------------------
TorrentFinderController::TorrentFinderController()
{
    _regExp.setCaseSensitivity (Qt::CaseInsensitive);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::addTorrentFinder (ITorrentFinder * torrentFinder)
{
    Q_ASSERT (torrentFinder);
    _finders.insert (torrentFinder);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::searchEpisode (const Serie & serie, uint episode)
{
    this->reset();
    this->searchEpisodeInAllFinders (serie, episode);
    this->findBestMatch (serie, episode);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::reset ()
{
    _episodeIsFound = false;
    _results.clear ();
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::searchEpisodeInAllFinders(const Serie & serie, uint episode)
{
    foreach (ITorrentFinder * finder, _finders) {
        finder->search (QString("%1 S%2E%3")
                        .arg (serie.name ())
                        .arg (toTwoDigits (serie.season ()))
                        .arg (toTwoDigits (episode)));
        _results.append (finder->getResults ());
    }
    sortResultsBySeed ();
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findBestMatch (const Serie & serie, uint episode)
{
    _regExp.setPattern (QString(".*%1.*%2.*%3.*")
                        .arg (getNameForMatch (serie))
                        .arg (toTwoDigits (serie.season ()))
                        .arg (toTwoDigits (episode)));

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