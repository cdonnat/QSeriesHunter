#ifndef STUB_TORRENTFINDER_H
#define STUB_TORRENTFINDER_H

#include <QString>

#include "itorrentfinder.h"

class TorrentFinderStub : public ITorrentFinder
{
public:
    TorrentFinderStub();

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void find(const QString & name);

    //----------------------------------------------------------------------------------------------
    void setResults (const TorrentFinderResults & results);

    //----------------------------------------------------------------------------------------------
    void reset();
    
    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual const TorrentFinderResults & getResults() const;

    //----------------------------------------------------------------------------------------------
    const QString & getRequest() const;

private:
    QString               _request;
    TorrentFinderResults  _results;
};

#endif // STUB_TORRENTFINDER_H
