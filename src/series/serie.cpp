#include "serie.h"

//----------------------------------------------------------------------------------------------
Serie::Serie(const QString & name, uint season, uint lastEpisode, bool isEnable)
    : _name(name),
      _season(season),
      _lastEpisode(lastEpisode),
      _isEnable(isEnable)
{
    Q_ASSERT (_season > 0);
}

//----------------------------------------------------------------------------------------------
Serie::Serie (const Serie & serie)
    :_name(serie.name()),
     _season(serie.season()),
     _lastEpisode(serie.lastEpisode()),
     _isEnable(serie.isEnable())
{
}

//----------------------------------------------------------------------------------------------
void Serie::inc()
{
    ++_lastEpisode;
}


//----------------------------------------------------------------------------------------------
void Serie::setLastEpisode (uint lastEpisode)
{
    _lastEpisode = lastEpisode;
}

//----------------------------------------------------------------------------------------------
void Serie::enable(bool isEnable)
{
    _isEnable = isEnable;
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
bool Serie::isEnable() const
{
    return _isEnable;
}

//----------------------------------------------------------------------------------------------
bool operator<(const Serie & l, const Serie & r)
{
    if (l.name() == r.name())
        return l.season() < r.season();
    else
        return l.name() < r.name();
}

//----------------------------------------------------------------------------------------------
bool Serie::operator==(const Serie & r) const
{
    return (_name == r.name ()) && (_season == r.season ());
}

//----------------------------------------------------------------------------------------------
bool Serie::operator!=(const Serie & r) const
{
    return !this->operator == (r);
}
