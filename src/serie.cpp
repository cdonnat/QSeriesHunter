#include "serie.h"

//----------------------------------------------------------------------------------------------
Serie::Serie(const QString & name, uint season, uint nbEpisodes, uint lastEpisodeDownloaded)
    : _name(name),
      _season(season),
      _nbEpisodes(nbEpisodes),
      _lastEpisodeDownloaded(lastEpisodeDownloaded)
{
    Q_ASSERT (_season > 0);
    Q_ASSERT (_nbEpisodes > 0);
    Q_ASSERT (_lastEpisodeDownloaded < _nbEpisodes);
}

//----------------------------------------------------------------------------------------------
void Serie::inc()
{
    Q_ASSERT (!this->isFinished ());
    _lastEpisodeDownloaded++;
}

//----------------------------------------------------------------------------------------------
bool Serie::isFinished() const
{
    return _lastEpisodeDownloaded == _nbEpisodes;
}

//----------------------------------------------------------------------------------------------
const QString & Serie::name() const
{
    return _name;
}

//----------------------------------------------------------------------------------------------
uint Serie::season() const
{
    return _season;
}

//----------------------------------------------------------------------------------------------
uint Serie::nextEpisode () const
{
    Q_ASSERT(!this->isFinished ());
    return _lastEpisodeDownloaded + 1;
}

//----------------------------------------------------------------------------------------------
uint Serie::lastEpisodeDownloaded() const
{
    return _lastEpisodeDownloaded;
}
