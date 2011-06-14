#include "serie.h"

//----------------------------------------------------------------------------------------------
Serie::Serie(const QString & name, uint season,uint lastEpisodeDownloaded)
    : _name(name),
      _season(season),
      _lastEpisodeDownloaded(lastEpisodeDownloaded)
{
    Q_ASSERT (_season > 0);
}

//----------------------------------------------------------------------------------------------
Serie::Serie (const Serie & serie)
    :_name(serie.name()),
     _season(serie.season()),
     _lastEpisodeDownloaded(serie.lastEpisodeDownloaded())
{
}

//----------------------------------------------------------------------------------------------
void Serie::inc()
{
    _lastEpisodeDownloaded++;
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
