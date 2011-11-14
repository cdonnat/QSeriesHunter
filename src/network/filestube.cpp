#include "filestube.h"
#include "networkaccess.h"

#include <QObject>
#include <QStringList>
#include <QVariantMap>
#include <QXmlStreamReader>

const QString key = "ff5286516f86965dadfeb44bc87d4c36&sort=dd&extension=avi&phrase=";

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
    QString request = "http://api.filestube.com/?key=" +
                       key
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
        _results << FinderResult(name, url, false, 0);
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
