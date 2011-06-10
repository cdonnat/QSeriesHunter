#include "seriescontroller.h"

//----------------------------------------------------------------------------------------------
SeriesController::SeriesController()
{
}

//----------------------------------------------------------------------------------------------
bool SeriesController::exists (const Serie & serie) const
{
    return false;
}

//----------------------------------------------------------------------------------------------
uint SeriesController::nbSeries() const
{
    return 0;
}

//----------------------------------------------------------------------------------------------
SeriesIterator SeriesController::series() const
{
}

//----------------------------------------------------------------------------------------------
void SeriesController::addSerie (const Serie & serie)
{
}

//----------------------------------------------------------------------------------------------
void SeriesController::removeSerie(const Serie & serie)
{
}

//----------------------------------------------------------------------------------------------
void SeriesController::modifySerie(const Serie & serieToChange, const Serie & newSerie)
{
}
