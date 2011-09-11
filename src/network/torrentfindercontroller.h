#ifndef TORRENTFINDERCONTROLLER_H
#define TORRENTFINDERCONTROLLER_H

#include <QList>
#include <QSet>
#include <QString>

#include "itorrentfinder.h"

class RegExpProvider;
class Serie;

class TorrentFinderController
{
public:

    //----------------------------------------------------------------------------------------------
    // Constuctors
    explicit TorrentFinderController();

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A new torrent finder is added.]
    void addTorrentFinder (ITorrentFinder * torrentFinder);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A request to find the next episode of the serie is returned.]
    void findNextEpisode (const Serie & serie);

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if the episode is found.]
    bool episodeIsFound () const;

    //----------------------------------------------------------------------------------------------
    // REQ [Next episode has been found.]
    // ENS [The url of the episode is returned as a string.]
    const QString & getEpisodeUrl () const;

private:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Internal variable are reset.]
    void reset ();

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Results are ready and sorted by seed.]
    void findNextEpisodeInAllFinders(const Serie & serie);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [The best url is stored.]
    void findBestMatch (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Results are sorted by seed.]
    void sortResultsBySeed ();

private:
    
    QSet<ITorrentFinder *>     _finders;
    QList<RegExpProvider *>    _regExpProviders;
    FinderResults              _results;
    bool                       _episodeIsFound;
    QString                    _url;
};

#endif // TORRENTFINDERCONTROLLER_H
