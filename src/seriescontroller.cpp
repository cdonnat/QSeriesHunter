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
const Serie & SeriesController::at(uint index) const
{
    Q_ASSERT (index < nbSeries());
    return _series.at (index);
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

//----------------------------------------------------------------------------------------------
void SeriesController::inc (const Serie & serie)
{
    Q_ASSERT (this->contains (serie));
    int index = _series.indexOf (serie);
    _series[index].inc();
}
