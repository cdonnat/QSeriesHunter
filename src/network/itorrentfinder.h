#ifndef ITORRENFINDER_H
#define ITORRENFINDER_H

#include "finderresult.h"
#include <QList>

typedef QList<FinderResult> FinderResults;

class ITorrentFinder
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~ITorrentFinder () {}

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
};

#endif // ITORRENFINDER_H
