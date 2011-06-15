#include "seriescontroller.h"

//----------------------------------------------------------------------------------------------
SeriesController::SeriesController()
{
}

//----------------------------------------------------------------------------------------------
bool SeriesController::contains (const Serie & serie) const
{
    return _series.keys ().contains (serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesController::nbSeries() const
{
    return _series.size ();
}

//----------------------------------------------------------------------------------------------
const Serie & SeriesController::at (uint index) const
{
    return (_series.constBegin () + int(index)).key ();
}

//----------------------------------------------------------------------------------------------
uint SeriesController::lastEpisodeDl (const Serie & serie) const
{
    Q_ASSERT (this->contains (serie));
    return _series.value (serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesController::nextEpisode (const Serie & serie) const
{
    Q_ASSERT (this->contains (serie));
    return _series.value (serie) + 1;
}


//----------------------------------------------------------------------------------------------
void SeriesController::addSerie (const Serie & serie, uint episode)
{
    Q_ASSERT (!this->contains (serie));
    _series.insert (serie, episode);
}

//----------------------------------------------------------------------------------------------
void SeriesController::removeSerie(const Serie & serie)
{
    Q_ASSERT (this->contains (serie));
    _series.remove (serie);
}

//----------------------------------------------------------------------------------------------
void SeriesController::inc (const Serie & serie)
{
    Q_ASSERT (this->contains (serie));
    _series[serie]++;
}
