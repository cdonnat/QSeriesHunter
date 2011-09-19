#include "filestube.h"
#include "networkaccess.h"

#include <QObject>
#include <QStringList>
#include <QVariantMap>
#include <QXmlStreamReader>

//--------------------------------------------------------------------------------------------------
FilesTube::FilesTube(INetworkAccess * const networkAccess) : AbstractFinder("DirectDownload"),
_networkAccess(networkAccess)
{
    Q_ASSERT (_networkAccess != NULL);
}

//--------------------------------------------------------------------------------------------------
void FilesTube::startRequest(const QString & serieTitle)
{
    QString convertedTitle = serieTitle;
    QString request = "http://api.filestube.com/?key=2c17a6258659780e0bc6d2ca41ab731e&sort=dd&phrase="
                      + convertedTitle.replace(' ', '+');
    _networkAccess->read(request);
}

//--------------------------------------------------------------------------------------------------
void FilesTube::addItemToResults(QXmlStreamReader & reader)
{
    QString name = "";
    QString url  = "";
    
    reader.readNext();
    while (!reader.atEnd()) 
    {
        if (reader.isEndElement() && reader.name() == "hits")
        {
            break;
        }
        
        if (reader.isStartElement())
        {
            if (reader.name() == "name")
            {
                name = reader.readElementText();
            }
            else if (reader.name() == "address")
            {
                url = reader.readElementText().simplified();
            }
        }
        reader.readNext();
    }
    
    const bool itemHasBeenCorrectlyRead = !(name.isEmpty() || url.isEmpty());
    if (itemHasBeenCorrectlyRead)
    {
        _results << FinderResult(name, url, 0);
    }
}

//--------------------------------------------------------------------------------------------------
void FilesTube::retrieveResults ()
{
    QXmlStreamReader reader(_networkAccess->content());
    reader.readNext();
    while (!reader.atEnd()) 
    {
        if (reader.isStartElement() && reader.name() == "hits") 
        {
            addItemToResults(reader);
        }
        reader.readNext();
    }
}

//--------------------------------------------------------------------------------------------------
void FilesTube::find (const QString & name)
{
    _results.clear ();
    startRequest(name);
    if (_networkAccess->contentIsReady())
    {
        retrieveResults();
    }
}

//--------------------------------------------------------------------------------------------------
const FinderResults & FilesTube::getResults () const
{
   return _results;
}
