#include "serie.h"

//----------------------------------------------------------------------------------------------
Serie::Serie(const QString & name, uint season, uint nbEpisodes, uint lastEpisodeSeen)
    : _name(name), _season(season), _nbEpisodes(nbEpisodes), _lastEpisodeSeen(lastEpisodeSeen)
{
    Q_ASSERT (_season > 0);
    Q_ASSERT (_nbEpisodes > 0);
    Q_ASSERT (_lastEpisodeSeen <= _nbEpisodes);
}

//----------------------------------------------------------------------------------------------
void Serie::nextEpisode()
{
    Q_ASSERT (!this->isFinished ());
    _lastEpisodeSeen++;
}

//----------------------------------------------------------------------------------------------
bool Serie::isFinished() const
{
    return _lastEpisodeSeen == _nbEpisodes;
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
uint Serie::lastEpisodeSeen() const
{
    return _lastEpisodeSeen;
}
