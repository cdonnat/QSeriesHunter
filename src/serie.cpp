#include "serie.h"

//----------------------------------------------------------------------------------------------
Serie::Serie(const QString & name, uint season, uint nbEpisodes, uint lastEpisodeDownloaded)
    : _name(name),
      _season(season),
      _nbEpisodes(nbEpisodes),
      _lastEpisodeDownloaded(lastEpisodeDownloaded)
{
    Q_ASSERT (_season > 0);
    Q_ASSERT (_nbEpisodes > 0);
    Q_ASSERT (_lastEpisodeDownloaded < _nbEpisodes);
}

//----------------------------------------------------------------------------------------------
Serie::Serie (const Serie & serie)
    :_name(serie.name()),
     _season(serie.season()),
     _nbEpisodes(serie._nbEpisodes),
     _lastEpisodeDownloaded(serie.lastEpisodeDownloaded())
{
}

//----------------------------------------------------------------------------------------------
void Serie::inc()
{
    Q_ASSERT (!this->isFinished ());
    _lastEpisodeDownloaded++;
}

//----------------------------------------------------------------------------------------------
bool Serie::isFinished() const
{
    return _lastEpisodeDownloaded == _nbEpisodes;
}

//----------------------------------------------------------------------------------------------
const QString & Serie::name() const
{
    return _name;
}

//----------------------------------------------------------------------------------------------
uint Serie::season() const
{
    return _season;
}

//----------------------------------------------------------------------------------------------
uint Serie::nextEpisode () const
{
    Q_ASSERT(!this->isFinished ());
    return _lastEpisodeDownloaded + 1;
}

//----------------------------------------------------------------------------------------------
uint Serie::lastEpisodeDownloaded() const
{
    return _lastEpisodeDownloaded;
}

//----------------------------------------------------------------------------------------------
bool operator==(const Serie & l, const Serie & r)
{
    return (l.name () == r.name ()) && (l.season () == r.season ());
}

//----------------------------------------------------------------------------------------------
bool operator!=(const Serie & l, const Serie & r)
{
    return !(l == r);
}
