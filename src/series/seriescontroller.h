#ifndef SERIESCONTROLLER_H
#define SERIESCONTROLLER_H

#include "iseriescontroller.h"
#include "seriesprovider.h"
#include "serie.h"

#include <QList>
#include <QMap>
#include <QPair>
#include <QDate>

class SerieMemento;

class SeriesController : public ISeriesController
{
public:

    //----------------------------------------------------------------------------------------------
    SeriesController(SeriesProvider * seriesProvider, const QDate & currentDate);

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual bool contains (const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual uint nbSeries () const;

    //----------------------------------------------------------------------------------------------
    virtual const Serie & at (uint index) const;

    //----------------------------------------------------------------------------------------------
    virtual SeriesMemento createMemento () const;

    //----------------------------------------------------------------------------------------------
    virtual bool aNewEpisodeIsAvailable(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual bool nextAiredEpisodeDetailsAreAvailable(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual bool lastAiredEpisodeDetailsAreAvailable(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual uint nextAiredEpisode(const Serie & serie) const;
       
    //----------------------------------------------------------------------------------------------
    virtual QDate nextAiredEpisodeDate(const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual uint lastAiredEpisode(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual QDate lastAiredEpisodeDate(const Serie & serie) const;

    
    // Commands :

    //----------------------------------------------------------------------------------------------
    virtual void addSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void removeSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void inc (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void setLastEpisode(const Serie & serie);
    
    //----------------------------------------------------------------------------------------------
    virtual void enable (const Serie & serie, bool isEnable);
    
    //----------------------------------------------------------------------------------------------
    virtual void loadFrom (const SeriesMemento &memento);

private :
    
    typedef QList<Serie>                                           Series;
    typedef QMap<Serie, 
                QPair<AiredEpisodeDetails, AiredEpisodeDetails> >  SeriesDetails;

    SeriesProvider * _seriesProvider;
    Series           _series;
    SeriesDetails    _seriesDetails;
    QDate            _currentDate;
};

#endif // SERIESCONTROLLER_H
