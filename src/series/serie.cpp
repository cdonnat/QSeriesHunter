#include "serie.h"

//----------------------------------------------------------------------------------------------
Serie::Serie(const QString & name, uint season)
    : _name(name),
      _season(season)
{
    Q_ASSERT (_season > 0);
}

//----------------------------------------------------------------------------------------------
Serie::Serie (const Serie & serie)
    :_name(serie.name()),
     _season(serie.season())
{
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
