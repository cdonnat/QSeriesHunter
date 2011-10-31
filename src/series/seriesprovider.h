#ifndef SERIESPROVIDER_H
#define SERIESPROVIDER_H

#include <QDate>
#include <QMap>

class INetworkAccess;
class QStringList;
class Serie;

class AiredEpisodeDetails
{
public:
    AiredEpisodeDetails(uint episode = 0, QDate date = QDate());
    
    uint          episode() const;
    const QDate & date()    const;
    
private:
    uint   _episode;
    QDate  _date;
};

class SeriesProvider
{
public:

    //----------------------------------------------------------------------------------------------
    SeriesProvider(INetworkAccess * network, const QDateTime & currentDate);

    // Commands:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A request to find all available series is sent.]
    virtual void searchAllSeries();
    
    // Queries:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [All available series found are returned.]
    virtual QStringList getAllSeries() const;
  
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Next aired episode details are returned. A null date is returned when not found.]
    virtual AiredEpisodeDetails nextAiredEpisode(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last aired episode details are returned. A null date is returned when not found.]
    virtual AiredEpisodeDetails lastAiredEpisode(const Serie & serie) const;
    
private:
    
    //----------------------------------------------------------------------------------------------
    void retrieveAllSeries();
    
    //----------------------------------------------------------------------------------------------
    QString getEpisodesDetailsUrl (const Serie & serie) const;
    
    INetworkAccess          * _network;
    QDateTime                 _currentDate;
    QMap<QString, QString>    _series;
};

#endif // SERIESPROVIDER_H
