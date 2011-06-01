#ifndef ITORRENFINDER_H
#define ITORRENFINDER_H

#include "torrentfinderresult.h"
#include <QList>

class  TorrentFinderResults : public QList<TorrentFinderResult>
{};

class ITorrentFinder
{
public:
    virtual ~ITorrentFinder () {}

    virtual void search(const QString & name) = 0;
    virtual const TorrentFinderResults & getResults() const = 0;
};

#endif // ITORRENFINDER_H
