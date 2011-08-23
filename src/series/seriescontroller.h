#ifndef SERIESCONTROLLER_H
#define SERIESCONTROLLER_H

#include "iseriescontroller.h"
#include "serie.h"

#include <QList>

class SerieMemento;

class SeriesController : public ISeriesController
{
public:

    //----------------------------------------------------------------------------------------------
    explicit SeriesController();

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual bool contains (const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual uint nbSeries () const;

    //----------------------------------------------------------------------------------------------
    virtual const Serie & at (uint index) const;

    //----------------------------------------------------------------------------------------------
    virtual SeriesMemento createMemento () const;

    // Commands :

    //----------------------------------------------------------------------------------------------
    virtual void addSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void removeSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void inc (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void loadFrom (const SeriesMemento &memento);

private :
    typedef QList<Serie> Series;

    Series  _series;
};

#endif // SERIESCONTROLLER_H
