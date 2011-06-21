#ifndef SERIESMEMENTO_H
#define SERIESMEMENTO_H

#include <QMap>
#include "serie.h"

class QString;

class SeriesMemento
{
public:
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last save memento is returned. An empty memento is returned if none are found.]
    static SeriesMemento loadFromInitFile(const QString & absolutePathInitFile);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Memento is written in init file.]
    void saveInInitFile(const QString & absolutePathInitFile);

private:
    //----------------------------------------------------------------------------------------------
    SeriesMemento(const QMap<Serie, uint> & series);

    //----------------------------------------------------------------------------------------------
    const QMap<Serie, uint> & get () const;

    friend class SeriesController;

    QMap<Serie, uint>  _save;
};

#endif // SERIESMEMENTO_H
