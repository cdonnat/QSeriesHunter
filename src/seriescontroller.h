#ifndef SERIESCONTROLLER_H
#define SERIESCONTROLLER_H

#include "serie.h"

#include <QList>

typedef QList<Serie>::const_iterator SeriesIterator;

class SeriesController
{
public:

    //----------------------------------------------------------------------------------------------
    explicit SeriesController();

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if serie already exists (i.e: same name and same season).]
    bool contains (const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Number of series is returned.]
    uint nbSeries() const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [An iterator on all series is returned.]
    SeriesIterator series() const;

    // Commands :

    //----------------------------------------------------------------------------------------------
    // REQ [Serie does not exist.]
    // ENS [Serie is added.]
    void addSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    // REQ [Serie exists.]
    // ENS [Serie is added.]
    void removeSerie(const Serie & serie);


private :
    QList<Serie>  _series;
};

#endif // SERIESCONTROLLER_H
