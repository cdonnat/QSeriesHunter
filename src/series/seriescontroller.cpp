#include "seriescontroller.h"
#include "seriesmemento.h"

#include <QtAlgorithms>

//----------------------------------------------------------------------------------------------
SeriesController::SeriesController(SeriesProvider * seriesProvider,
                                   const QDate & currentDate):
_seriesProvider(seriesProvider), _currentDate(currentDate)
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
    _seriesDetails.insert(serie, 
                          qMakePair(_seriesProvider->lastAiredEpisode(serie),
                                    _seriesProvider->nextAiredEpisode(serie)));
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
    foreach (Serie serie, memento.get())
    {
        addSerie(serie);
    }
}

//----------------------------------------------------------------------------------------------
bool SeriesController::aNewEpisodeIsAvailable(const Serie & serie) const
{
    Q_ASSERT(contains(serie));
    AiredEpisodeDetails lastAired = _seriesDetails[serie].first;
    
    return lastAired.episode() > serie.lastEpisode() &&
           lastAired.date() < _currentDate;
}

//----------------------------------------------------------------------------------------------
uint SeriesController::nextAiredEpisode(const Serie & serie) const
{
    Q_ASSERT(nextAiredEpisodeDetailsAreAvailable(serie));
    return _seriesDetails[serie].second.episode();
}

//----------------------------------------------------------------------------------------------
QDate SeriesController::nextAiredEpisodeDate(const Serie & serie) const
{
    Q_ASSERT(nextAiredEpisodeDetailsAreAvailable(serie));
    return _seriesDetails[serie].second.date();
}

//----------------------------------------------------------------------------------------------
uint SeriesController::lastAiredEpisode(const Serie & serie) const
{
    Q_ASSERT(lastAiredEpisodeDetailsAreAvailable(serie));
    return _seriesDetails[serie].first.episode();
}

//----------------------------------------------------------------------------------------------
QDate SeriesController::lastAiredEpisodeDate(const Serie & serie) const
{
    Q_ASSERT(lastAiredEpisodeDetailsAreAvailable(serie));
    return _seriesDetails[serie].first.date();
}

//----------------------------------------------------------------------------------------------
bool SeriesController::nextAiredEpisodeDetailsAreAvailable(const Serie & serie) const 
{
    return !_seriesDetails[serie].second.date().isNull();
}

//----------------------------------------------------------------------------------------------
bool SeriesController::lastAiredEpisodeDetailsAreAvailable(const Serie & serie) const 
{
    return !_seriesDetails[serie].first.date().isNull();
}    
