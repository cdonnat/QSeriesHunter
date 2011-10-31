#include "seriesprovider.h"

#include "inetworkaccess.h"
#include "serie.h"

#include <QtAlgorithms>
#include <QtGlobal>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QDebug>

#include "qjson/parser.h"

const QString allSeriesUrl = "http://api.betaseries.com/shows/display/all.json?key=ce26d57deee0";

//----------------------------------------------------------------------------------------------
AiredEpisodeDetails::AiredEpisodeDetails(uint episode, QDate date):
_episode(episode), _date(date)
{
}

//----------------------------------------------------------------------------------------------
uint AiredEpisodeDetails::episode() const
{
    return _episode;
}

//----------------------------------------------------------------------------------------------
const QDate & AiredEpisodeDetails::date()    const
{
    return _date;
}


//----------------------------------------------------------------------------------------------
QString SeriesProvider::getEpisodesDetailsUrl (const Serie & serie) const
{
    return QString("http://api.betaseries.com/shows/episodes/%1.json?key=ce26d57deee0&season=%2")
    .arg(_series[serie.name()]).arg(serie.season());
}

//----------------------------------------------------------------------------------------------
SeriesProvider::SeriesProvider(INetworkAccess  * network, const QDateTime & currentDate):
_network(network), _currentDate(currentDate)
{
    Q_ASSERT (_network);
}

//----------------------------------------------------------------------------------------------
void SeriesProvider::searchAllSeries()
{
    _series.clear();
    _network->read(allSeriesUrl);
   
    if (_network->contentIsReady())
    {
        retrieveAllSeries();
    }
}

//--------------------------------------------------------------------------------------------------
void SeriesProvider::retrieveAllSeries ()
{
    Q_ASSERT (_network->contentIsReady ());
    bool           parsingIsOk;
    QJson::Parser  parser;
    QVariantMap    jsonResult = parser.parse(_network->content(),
                                             &parsingIsOk).toMap();
    
    if (parsingIsOk)
    {
        QVariantMap   map = jsonResult["root"].toMap()["shows"].toMap();
        foreach (const QVariant & serie, map)
        {          
            const QString url   =  serie.toMap()["url"].toString().remove('"');
            const QString title =  serie.toMap()["title"].toString().remove('"');           
            _series.insert(title, url);
        }
    }
}

//--------------------------------------------------------------------------------------------------
bool operator<(const QVariant & l, const QVariant & r)
{
    return l.toMap()["date"].toUInt() < r.toMap()["date"].toUInt();
}

//--------------------------------------------------------------------------------------------------
AiredEpisodeDetails SeriesProvider::nextAiredEpisode(const Serie & serie) const 
{
    AiredEpisodeDetails details;

    _network->read(getEpisodesDetailsUrl(serie));
    if (_network->contentIsReady())
    {
        bool           parsingIsOk;
        QJson::Parser  parser;
        QVariantMap    jsonResult = parser.parse(_network->content(),
                                                 &parsingIsOk).toMap();
        
        if (parsingIsOk)
        {
            QVariantMap   seasons  = jsonResult["root"].toMap()["seasons"].toMap();
            QVariantMap   episodes = seasons["0"].toMap()["episodes"].toMap();
            
            QList<QVariant> episodeList = episodes.values();
            qSort(episodeList.begin(), episodeList.end());
            
            foreach (const QVariant & episode, episodeList)
            {          
                const QDateTime episodeDate =  
                                  QDateTime::fromTime_t(episode.toMap()["date"].toUInt());  
                
                if (episodeDate > _currentDate)
                {
                    return AiredEpisodeDetails(episode.toMap()["episode"].toUInt(),
                                               episodeDate.date());
                }                               
            }
        }
    }
    return details;
}

//--------------------------------------------------------------------------------------------------
AiredEpisodeDetails SeriesProvider::lastAiredEpisode(const Serie & serie) const
{
    AiredEpisodeDetails details;
    
    _network->read(getEpisodesDetailsUrl(serie));
    if (_network->contentIsReady())
    {
        bool           parsingIsOk;
        QJson::Parser  parser;
        QVariantMap    jsonResult = parser.parse(_network->content(),
                                                 &parsingIsOk).toMap();
        
        if (parsingIsOk)
        {
            QVariantMap   seasons  = jsonResult["root"].toMap()["seasons"].toMap();
            QVariantMap   episodes = seasons["0"].toMap()["episodes"].toMap();
            
            QList<QVariant> episodeList = episodes.values();
            qSort(episodeList.begin(), episodeList.end());
            
            foreach (const QVariant & episode, episodeList)
            {          
                const QDateTime episodeDate =  
                QDateTime::fromTime_t(episode.toMap()["date"].toUInt());  
                
                if (episodeDate > _currentDate)
                    break;
                details = AiredEpisodeDetails(episode.toMap()["episode"].toUInt(),
                                              episodeDate.date());
            }
        }
    }
    return details;
}


//--------------------------------------------------------------------------------------------------
QStringList SeriesProvider::getAllSeries() const
{
    return _series.keys();
}