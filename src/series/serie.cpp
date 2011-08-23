#include "serie.h"

//----------------------------------------------------------------------------------------------
Serie::Serie(const QString & name, uint season, uint lastEpisode)
    : _name(name),
      _season(season),
      _lastEpisode(lastEpisode)
{
    Q_ASSERT (_season > 0);
}

//----------------------------------------------------------------------------------------------
Serie::Serie (const Serie & serie)
    :_name(serie.name()),
     _season(serie.season()),
     _lastEpisode(serie.lastEpisode())
{
}

//----------------------------------------------------------------------------------------------
void Serie::inc()
{
    ++_lastEpisode;
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
uint Serie::lastEpisode() const
{
    return _lastEpisode;
}

//----------------------------------------------------------------------------------------------
bool operator<(const Serie & l, const Serie & r)
{
    return (l.name () < r.name ()) || (l.season () < r.season ());
}

//----------------------------------------------------------------------------------------------
bool Serie::operator==(const Serie & r)
{
    return (_name == r.name ()) && (_season == r.season ());
}

//----------------------------------------------------------------------------------------------
bool Serie::operator!=(const Serie & r)
{
    return !this->operator == (r);
}
