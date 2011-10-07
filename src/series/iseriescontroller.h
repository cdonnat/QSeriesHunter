#ifndef ISERIESCONTROLLER_H
#define ISERIESCONTROLLER_H

#include <QtGlobal>

class Serie;
class SeriesMemento;

class ISeriesController
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~ISeriesController() {}

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if serie already exists (i.e: same name and same season).]
    virtual bool contains (const Serie & serie) const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [0 <= index < nbEpisode.]
    // ENS [True is returned if serie already exists (i.e: same name and same season).]
    virtual const Serie & at (uint index) const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Number of series is returned.]
    virtual uint nbSeries () const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Return a memento that represents the state of the series controller.]
    virtual SeriesMemento createMemento() const = 0;

    // Commands :

    //----------------------------------------------------------------------------------------------
    // REQ [Serie does not exist.]
    // ENS [Serie is added.]
    virtual void addSerie (const Serie & serie) = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [Serie exists.]
    // ENS [Serie is added.]
    virtual void removeSerie (const Serie & serie) = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [Serie exists.]
    // ENS [Last episode downloaded of the serie is incremented.]
    virtual void inc (const Serie & serie) = 0;
    
    //----------------------------------------------------------------------------------------------
    // REQ [Serie exists.]
    // ENS [Enable or disable specified serie.]
    virtual void enable (const Serie & serie, bool isEnable) = 0;
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Series controller is created from memento.]
    virtual void loadFrom (const SeriesMemento & memento) = 0;
};

#endif // ISERIESCONTROLLER_H
