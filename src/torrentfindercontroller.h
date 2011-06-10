#ifndef TORRENTFINDERCONTROLLER_H
#define TORRENTFINDERCONTROLLER_H

#include <QRegExp>
#include <QSet>
#include <QString>

#include "itorrentfinder.h"

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
    // REQ [Serie is not finished.]
    // ENS [A request to find the next episode of the serie is returned.]
    void searchNextEpisode (const Serie & serie);

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if the next episode is found.]
    bool nextEpisodeIsFound () const;

    //----------------------------------------------------------------------------------------------
    // REQ [Next episode has been found.]
    // ENS [The url of the next episode is returned as a string.]
    const QString & getNextEpisodeUrl () const;

private:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Internal variable are reset.]
    void reset ();

    //----------------------------------------------------------------------------------------------
    // REQ [Serie is not finished.]
    // ENS [Results are ready and sorted by seed.]
    void searchNextEpisodeInAllFinders(const Serie & serie);

    //----------------------------------------------------------------------------------------------
    // REQ [Serie is not finished.]
    // ENS [The url of the next episode is returned as a string.]
    void findBestMatch (const Serie & serie);

private:
    QSet<ITorrentFinder *>     _finders;
    TorrentFinderResults       _results;
    bool                       _nextEpisodeIsFound;
    QString                    _url;
    QRegExp                    _regExp;
};

#endif // TORRENTFINDERCONTROLLER_H
