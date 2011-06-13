#ifndef SERIESCONTROLLER_H
#define SERIESCONTROLLER_H

#include "serie.h"

#include <QList>


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
    // REQ [0 <= index < nbSerie.]
    // ENS [Serie at given index is returned.]
    const Serie & at(uint index) const;

    // Commands :

    //----------------------------------------------------------------------------------------------
    // REQ [Serie does not exist.]
    // ENS [Serie is added.]
    void addSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    // REQ [Serie exists.]
    // ENS [Serie is added.]
    void removeSerie(const Serie & serie);

    void inc (const Serie & serie);

private :
    QList<Serie>  _series;
};

#endif // SERIESCONTROLLER_H
