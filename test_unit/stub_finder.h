#ifndef STUB_TORRENTFINDER_H
#define STUB_TORRENTFINDER_H

#include <QString>

#include "abstractfinder.h"

class FinderStub : public AbstractFinder
{
public:
    FinderStub();

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void find(const QString & name);

    //----------------------------------------------------------------------------------------------
    void setResults (const FinderResults & results);

    //----------------------------------------------------------------------------------------------
    void reset();
    
    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual const FinderResults & getResults() const;

    //----------------------------------------------------------------------------------------------
    const QString & getRequest() const;

private:
    QString        _request;
    FinderResults  _results;
};

#endif // STUB_TORRENTFINDER_H
