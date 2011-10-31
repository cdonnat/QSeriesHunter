#include "stub_seriesprovider.h"

#include "stub_networkaccess.h"
#include <QDateTime>

SeriesProviderStub::SeriesProviderStub()
:SeriesProvider(new NetworkAccessStub, QDateTime::currentDateTime())
{}

//----------------------------------------------------------------------------------------------
QStringList SeriesProviderStub::getAllSeries () const 
{
    return QStringList();
} 

//----------------------------------------------------------------------------------------------
AiredEpisodeDetails SeriesProviderStub::nextAiredEpisode (const Serie & serie) const
{
    return _next;
}

//----------------------------------------------------------------------------------------------
AiredEpisodeDetails SeriesProviderStub::lastAiredEpisode(const Serie & serie) const
{
    return _last;
}

//----------------------------------------------------------------------------------------------
void SeriesProviderStub::setAiredDetails (uint          lastEpisode,
                                          const QDate & lastDate,
                                          uint          nextEpisode,
                                          const QDate & nextDate)
{
    _last = AiredEpisodeDetails(lastEpisode, lastDate);
    _next = AiredEpisodeDetails(nextEpisode, nextDate);
}
