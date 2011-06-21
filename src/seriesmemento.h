#ifndef SERIESMEMENTO_H
#define SERIESMEMENTO_H

#include <QMap>
#include "serie.h"

class SeriesMemento
{
public:
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last save memento is returned. An empty memento is returned if none are found.]
    static SeriesMemento loadFromInitFile();

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Memento is written in init file.]
    void saveInInitFile();

private:
    //----------------------------------------------------------------------------------------------
    SeriesMemento(const QMap<Serie, uint> & series);

    //----------------------------------------------------------------------------------------------
    const QMap<Serie, uint> & get () const;

    friend class SeriesController;

    QMap<Serie, uint>  _save;
};

#endif // SERIESMEMENTO_H
