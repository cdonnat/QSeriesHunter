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
// ENS [Format season on 2 digits.]
QString getFormatSeason (const Serie & serie)
{
    return QString::number (serie.season ()).rightJustified (2, '0');
}


//----------------------------------------------------------------------------------------------
// REQ [None.]
// ENS [Format episode on 2 digits.]
QString getFormatEpisode (uint episode)
{
   return QString::number (episode).rightJustified (2, '0');
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
    foreach (ITorrentFinder * finder, _finders)
    {
        finder->search (QString("%1 S%2E%3")
                        .arg (serie.name ())
                        .arg (getFormatSeason (serie))
                        .arg (getFormatEpisode (episode)));
        _results.append (finder->getResults ());
    }
    //
    qSort (_results.begin (), _results.end (), greaterThan);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findBestMatch (const Serie & serie, uint episode)
{
    _regExp.setPattern (QString(".*%1.*%2.*%3.*")
                        .arg (getNameForMatch (serie))
                        .arg (getFormatSeason (serie))
                        .arg (getFormatEpisode (episode)));

    foreach(TorrentFinderResult res, _results)
    {
        if (_regExp.exactMatch (res.name ()))
        {
            _episodeIsFound = true;
            _url            = res.url ();
            break;
        }
    }
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
