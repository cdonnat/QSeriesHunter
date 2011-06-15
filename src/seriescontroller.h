#ifndef SERIESCONTROLLER_H
#define SERIESCONTROLLER_H

#include "iseriescontroller.h"
#include "serie.h"

#include <QMap>

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
    virtual uint lastEpisodeDl (const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual uint nextEpisode (const Serie & serie) const;

    // Commands :

    //----------------------------------------------------------------------------------------------
    virtual void addSerie (const Serie & serie, uint episode = 0);

    //----------------------------------------------------------------------------------------------
    virtual void removeSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void inc (const Serie & serie);

private :
    typedef QMap<Serie, uint> MapSeries;

    MapSeries  _series;
};

#endif // SERIESCONTROLLER_H
