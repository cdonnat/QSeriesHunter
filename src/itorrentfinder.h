#ifndef ITORRENFINDER_H
#define ITORRENFINDER_H

#include "torrentfinderresult.h"
#include <QList>

class  TorrentFinderResults : public QList<TorrentFinderResult>
{};

class ITorrentFinder
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~ITorrentFinder () {}

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A request is sent to a specific server.]
    virtual void search(const QString & name) = 0;

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent results are returned.]
    virtual const TorrentFinderResults & getResults() const = 0;
};

#endif // ITORRENFINDER_H
