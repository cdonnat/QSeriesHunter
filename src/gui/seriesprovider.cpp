#include "seriesprovider.h"

#include "inetworkaccess.h"
#include <QtGlobal>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QDebug>

#include "qjson/parser.h"

const QString allSeriesUrl = "http://api.betaseries.com/shows/display/all.json?key=ce26d57deee0";

//----------------------------------------------------------------------------------------------
SeriesProvider::SeriesProvider(INetworkAccess  * network):_network(network)
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
        retrieveResults();
    }
}

//--------------------------------------------------------------------------------------------------
void SeriesProvider::retrieveResults ()
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
            _series.insert(url, title);
        }
    }
}

//----------------------------------------------------------------------------------------------
QStringList SeriesProvider::getAllSeries() const
{
    return _series.values();
}