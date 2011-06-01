#include "isohunt.h"
#include "networkaccess.h"

#include <QStringList>
#include <QObject>
#include <QVariantMap>

#include <qjson/parser.h>

//--------------------------------------------------------------------------------------------------
Isohunt::Isohunt(INetworkAccess * const networkAccess)
{
    _networkAccess = networkAccess;
}

//--------------------------------------------------------------------------------------------------
void Isohunt::startRequest(const QString & name)
{
    QString          convert = name;
    QString          request = "http://ca.isohunt.com/js/json.php?ihq=" +
                                convert.replace(" ","+");
    _networkAccess->read(request);
}

//--------------------------------------------------------------------------------------------------
void Isohunt::addItemToResults(const QVariant & item)
{
    QVariantMap  map = item.toMap();
    _results.append(TorrentFinderResult(
                        map["title"].toString(),
                        map["enclosure_url"].toString(),
                        map["Seeds"].toUInt()));
}

//--------------------------------------------------------------------------------------------------
void Isohunt::retrieveResults ()
{
    bool           parsingIsOk;
    QJson::Parser  parser;
    QVariantMap    jsonResult = parser.parse(_networkAccess->content(), &parsingIsOk).toMap();

     _results.clear ();

     if (parsingIsOk)
     {
        QVariantList   list       = jsonResult["items"].toMap()["list"].toList();
        foreach (const QVariant & item, list)
        {
            this->addItemToResults (item);
        }
     }
}

//--------------------------------------------------------------------------------------------------
void Isohunt::search (const QString & name)
{
    this->startRequest(name);
    if(_networkAccess->contentIsReady())
    {       
        this->retrieveResults();
    }
}

//--------------------------------------------------------------------------------------------------
const TorrentFinderResults & Isohunt::getResults () const
{
   return _results;
}
