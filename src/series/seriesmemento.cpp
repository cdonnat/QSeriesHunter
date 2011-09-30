#include "seriesmemento.h"

#include <QDataStream>
#include <QFile>
#include <QDir>
#include <QString>

//----------------------------------------------------------------------------------------------
SeriesMemento::SeriesMemento(const QList<Serie> & series): _save(series)
{
}

//----------------------------------------------------------------------------------------------
const QList<Serie> & SeriesMemento::get () const
{
    return _save;
}

//----------------------------------------------------------------------------------------------
SeriesMemento SeriesMemento::loadFromStream(QDataStream & dataStream)
{
    QList<Serie>  series;
    dataStream >> series;
    return SeriesMemento(series);
}

//----------------------------------------------------------------------------------------------
QDataStream & operator>> (QDataStream & dataStream, Serie & serie)
{
    QString name;
    uint    season;
    uint    episode;
    dataStream >> name;
    dataStream >> season;
    dataStream >> episode;
    serie = Serie(name, season, episode);
    return dataStream;
}

//----------------------------------------------------------------------------------------------
QDataStream & operator<< (QDataStream & dataStream, const Serie & serie)
{
    dataStream << serie.name ();
    dataStream << serie.season ();
    dataStream << serie.lastEpisode();
    return dataStream;
}

QDataStream & operator<<(QDataStream & o, const SeriesMemento & serieMemento)
{
    o << serieMemento._save;
    return o;
}
