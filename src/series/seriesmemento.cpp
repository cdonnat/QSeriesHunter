#include "seriesmemento.h"

#include <QDataStream>
#include <QFile>
#include <QDir>
#include <QString>

//----------------------------------------------------------------------------------------------
SeriesMemento::SeriesMemento(const QMap<Serie, uint> & series): _save(series)
{
}

//----------------------------------------------------------------------------------------------
const QMap<Serie, uint> & SeriesMemento::get () const
{
    return _save;
}

//----------------------------------------------------------------------------------------------
SeriesMemento SeriesMemento::loadFromInitFile(const QString & absolutePathInitFile)
{
    QFile  initFile(absolutePathInitFile);
    initFile.open(QIODevice::ReadOnly);

    QDataStream in(&initFile);
    QMap<Serie, uint >  series;

    in.setVersion (QDataStream::Qt_4_7);
    in >> series;
    initFile.close ();
    return SeriesMemento(series);
}

//----------------------------------------------------------------------------------------------
QDataStream & operator>> (QDataStream & dataStream, Serie & serie)
{
    QString name;
    uint    season;
    dataStream >> name;
    dataStream >> season;
    serie = Serie(name, season);
    return dataStream;
}

//----------------------------------------------------------------------------------------------
QDataStream & operator<< (QDataStream & dataStream, const Serie & serie)
{
    dataStream << serie.name ();
    dataStream << serie.season ();
    return dataStream;
}

//----------------------------------------------------------------------------------------------
void SeriesMemento::saveInInitFile(const QString & absolutePathInitFile)
{
    QFile  initFile(absolutePathInitFile);
    initFile.open(QIODevice::WriteOnly);

    QDataStream out(&initFile);
    out.setVersion (QDataStream::Qt_4_7);
    out << _save;
    initFile.close ();
}
