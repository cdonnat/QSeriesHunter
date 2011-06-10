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
// REQ [Season is not finished.]
// ENS [Format next episode on 2 digits.]
QString getFormatNextEpisode (const Serie & serie)
{
    Q_ASSERT(!serie.isFinished ());
    return QString::number (serie.nextEpisode ()).rightJustified (2, '0');
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
void TorrentFinderController::searchNextEpisode (const Serie & serie)
{
    Q_ASSERT(!serie.isFinished ());
    this->reset();
    this->searchNextEpisodeInAllFinders (serie);
    this->findBestMatch (serie);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::reset ()
{
    _nextEpisodeIsFound = false;
    _results.clear ();
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::searchNextEpisodeInAllFinders(const Serie & serie)
{
    Q_ASSERT(!serie.isFinished ());
    foreach (ITorrentFinder * finder, _finders)
    {
        finder->search (QString("%1 S%2E%3")
                        .arg (serie.name ())
                        .arg (getFormatSeason (serie))
                        .arg (getFormatNextEpisode (serie)));
        _results.append (finder->getResults ());
    }
    //
    qSort (_results.begin (), _results.end (), greaterThan);
}

//----------------------------------------------------------------------------------------------
void TorrentFinderController::findBestMatch (const Serie & serie)
{
    Q_ASSERT(!serie.isFinished ());
    _regExp.setPattern (QString(".*%1.*%2.*%3.*")
                        .arg (getNameForMatch (serie))
                        .arg (getFormatSeason (serie))
                        .arg (getFormatNextEpisode (serie)));

    foreach(TorrentFinderResult res, _results)
    {
        if (_regExp.exactMatch (res.name ()))
        {
            _nextEpisodeIsFound = true;
            _url                = res.url ();
            break;
        }
    }
}

//----------------------------------------------------------------------------------------------
bool TorrentFinderController::nextEpisodeIsFound () const
{
    return _nextEpisodeIsFound;
}

//----------------------------------------------------------------------------------------------
const QString & TorrentFinderController::getNextEpisodeUrl () const
{
    Q_ASSERT (this->nextEpisodeIsFound ());
    return _url;
}
