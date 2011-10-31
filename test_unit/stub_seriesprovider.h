#ifndef STUB_SERIESPROVIDER_H
#define STUB_SERIESPROVIDER_H

#include "seriesprovider.h"
#include <QStringList>

class SeriesProviderStub : public SeriesProvider
{
public:
    SeriesProviderStub();

    //----------------------------------------------------------------------------------------------
    virtual void searchAllSeries () {}

    //----------------------------------------------------------------------------------------------
    virtual QStringList getAllSeries () const;
    
    //----------------------------------------------------------------------------------------------
    virtual AiredEpisodeDetails nextAiredEpisode(const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual AiredEpisodeDetails lastAiredEpisode(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    void setAiredDetails (uint          lastEpisode,
                          const QDate & lastDate,
                          uint          nextEpisode,
                          const QDate & nextDate);
    
    AiredEpisodeDetails _next, _last;

};

#endif // STUB_SERIESPROVIDER_H
