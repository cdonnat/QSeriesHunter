#ifndef SERIESMEMENTO_H
#define SERIESMEMENTO_H

#include <QList>
#include "serie.h"

class QDataStream;

class SeriesMemento
{
public:
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last save memento is returned. An empty memento is returned if none are found.]
    static SeriesMemento loadFromStream(QDataStream & o);

    friend QDataStream & operator<<(QDataStream & o, const SeriesMemento & serieMemento);
    
private:
    //----------------------------------------------------------------------------------------------
    SeriesMemento(const QList<Serie> & series);

    //----------------------------------------------------------------------------------------------
    const QList<Serie> & get () const;

    friend class SeriesController;

    QList<Serie>  _save;
};


#endif // SERIESMEMENTO_H
