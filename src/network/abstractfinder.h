#ifndef ABSTRACTFINDER_H
#define ABSTRACTFINDER_H

#include "finderresult.h"
#include <QList>
#include <QString>

typedef QList<FinderResult> FinderResults;

class AbstractFinder
{
public:

    //----------------------------------------------------------------------------------------------
    AbstractFinder (const QString & type);

    
    //----------------------------------------------------------------------------------------------
    virtual ~AbstractFinder () {}

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A request is sent to a specific server.]
    virtual void find(const QString & name) = 0;

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Results are returned.]
    virtual const FinderResults & getResults() const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [The type of finder is returned "Torrent" or "DirectDownload".]
    virtual const QString & getType () const;
    
private :
    QString  _type;
};

#endif // ABSTRACTFINDER_H
