#include "seriescontroller.h"

//----------------------------------------------------------------------------------------------
SeriesController::SeriesController()
{
}

//----------------------------------------------------------------------------------------------
bool SeriesController::contains (const Serie & serie) const
{
    return _series.contains (serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesController::nbSeries() const
{
    return _series.size ();
}

//----------------------------------------------------------------------------------------------
SeriesIterator SeriesController::series() const
{
    return _series.constBegin ();
}

//----------------------------------------------------------------------------------------------
void SeriesController::addSerie (const Serie & serie)
{
    Q_ASSERT (!this->contains (serie));
    _series.append (serie);
}

//----------------------------------------------------------------------------------------------
void SeriesController::removeSerie(const Serie & serie)
{
    Q_ASSERT (this->contains (serie));
    _series.removeOne (serie);
}
