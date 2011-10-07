#include "seriescontroller.h"
#include "seriesmemento.h"

#include <QtAlgorithms>

//----------------------------------------------------------------------------------------------
SeriesController::SeriesController()
{
}

//----------------------------------------------------------------------------------------------
bool SeriesController::contains (const Serie & serie) const
{
    return _series.contains(serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesController::nbSeries() const
{
    return _series.size ();
}

//----------------------------------------------------------------------------------------------
const Serie & SeriesController::at (uint index) const
{
    return _series.at(index);
}

//----------------------------------------------------------------------------------------------
SeriesMemento SeriesController::createMemento () const
{
    return SeriesMemento(_series);
}

//----------------------------------------------------------------------------------------------
void SeriesController::addSerie (const Serie & serie)
{
    Q_ASSERT (!this->contains (serie));
    _series << serie;
    qSort(_series.begin(), _series.end());
}

//----------------------------------------------------------------------------------------------
void SeriesController::removeSerie(const Serie & serie)
{
    Q_ASSERT (this->contains (serie));
    _series.removeOne(serie);
}

//----------------------------------------------------------------------------------------------
void SeriesController::inc (const Serie & serie)
{
    Q_ASSERT (this->contains (serie));
    Series::iterator  it = qBinaryFind(_series.begin(), _series.end(), serie);
    it->inc();
}

//----------------------------------------------------------------------------------------------
void SeriesController::enable (const Serie & serie, bool isEnable)
{
    Q_ASSERT (this->contains (serie));
    Series::iterator  it = qBinaryFind(_series.begin(), _series.end(), serie);
    it->enable(isEnable);
}

//----------------------------------------------------------------------------------------------
void SeriesController::loadFrom (const SeriesMemento &memento)
{
    _series = memento.get ();
}
