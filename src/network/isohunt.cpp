#include "isohunt.h"
#include "networkaccess.h"

#include <QObject>
#include <QStringList>
#include <QVariantMap>

#include <qjson/parser.h>

//--------------------------------------------------------------------------------------------------
Isohunt::Isohunt(INetworkAccess * const networkAccess) : AbstractFinder("Torrent"),
_networkAccess(networkAccess)
{
    Q_ASSERT (_networkAccess != NULL);
}

//--------------------------------------------------------------------------------------------------
void Isohunt::startRequest(const QString & serieTitle)
{
    QString          convertedTitle = serieTitle;
    QString          request        =
            "http://ca.isohunt.com/js/json.php?ihq=" +
            convertedTitle.replace(" ","+");
    _networkAccess->read(request);
}

//--------------------------------------------------------------------------------------------------
void Isohunt::addItemToResults(const QVariant & item)
{
    QVariantMap  map = item.toMap();
    _results.append(FinderResult(map["title"].toString(),
                                 map["enclosure_url"].toString(),
                                 true,
                                 map["Seeds"].toUInt()));
}

//--------------------------------------------------------------------------------------------------
void Isohunt::retrieveResults ()
{
    Q_ASSERT (_networkAccess->contentIsReady ());
    bool           parsingIsOk;
    QJson::Parser  parser;
    QVariantMap    jsonResult = parser.parse(_networkAccess->content(),
                                             &parsingIsOk).toMap();

     if (parsingIsOk)
     {
        QVariantList   list = jsonResult["items"].toMap()["list"].toList();
        foreach (const QVariant & item, list)
        {
            this->addItemToResults (item);
        }
     }
}

//--------------------------------------------------------------------------------------------------
void Isohunt::find (const QString & name)
{
    _results.clear ();
    this->startRequest(name);
    if(_networkAccess->contentIsReady())
    {       
        this->retrieveResults();
    }
}

//--------------------------------------------------------------------------------------------------
const FinderResults & Isohunt::getResults () const
{
   return _results;
}
