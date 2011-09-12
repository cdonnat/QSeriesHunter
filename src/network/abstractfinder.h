#ifndef ABSTRACTFINDER_H
#define ABSTRACTFINDER_H

#include "finderresult.h"
#include <QList>

typedef QList<FinderResult> FinderResults;

class AbstractFinder
{
public:

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
};

#endif // ABSTRACTFINDER_H
