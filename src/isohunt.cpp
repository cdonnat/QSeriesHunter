#include "isohunt.h"
#include "networkaccess.h"

#include <QStringList>
#include <QObject>
#include <QVariantMap>

#include <qjson/parser.h>

//-------------------------------------------------------------------------------------------------
Isohunt::Isohunt(INetworkAccess * networkAccess)
{
    _networkAccess = networkAccess;
}

//-------------------------------------------------------------------------------------------------
void Isohunt::startRequest(const QString & name)
{
    QString          convert = name;
    QString          request = "http://ca.isohunt.com/js/json.php?ihq=" +
                                convert.replace(" ","+");
    _networkAccess->read(request);
}

//-------------------------------------------------------------------------------------------------
void Isohunt::retrieveResults ()
{
    bool           ok;
    QJson::Parser  parser;
    QVariantMap    jsonResult = parser.parse(_networkAccess->content(), &ok).toMap();
    QVariantList   list       = jsonResult["items"].toMap()["list"].toList();

    foreach (const QVariant &each, list)
    {
        QVariantMap  item = each.toMap();
        _results.append(TorrentFinderResult(
                            item["title"].toString(),
                            item["enclosure_url"].toString(),
                            item["Seeds"].toUInt()));
    }
}

//-------------------------------------------------------------------------------------------------
void Isohunt::search (const QString & name)
{
    this->startRequest(name);
    if(_networkAccess->contentIsReady())
    {       
        this->retrieveResults();
    }
}

//-------------------------------------------------------------------------------------------------
const TorrentFinderResults & Isohunt::getResults () const
{
   return _results;
}
