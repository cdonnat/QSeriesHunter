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
    // REQ [None.]
    // ENS [A request to find the episode of the serie is returned.]
    void searchEpisode (const Serie & serie, uint episode);

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
    void searchEpisodeInAllFinders(const Serie & serie, uint episode);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [The best url is stored.]
    void findBestMatch (const Serie & serie, uint episode);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Results are sorted by seed.]
    void sortResultsBySeed ();

private:
    QSet<ITorrentFinder *>     _finders;
    TorrentFinderResults       _results;
    bool                       _episodeIsFound;
    QString                    _url;
    QRegExp                    _regExp;
};

#endif // TORRENTFINDERCONTROLLER_H
