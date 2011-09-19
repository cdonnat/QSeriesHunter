#ifndef FINDERCONTROLLER_H
#define FINDERCONTROLLER_H

#include <QList>
#include <QMap>
#include <QSet>
#include <QString>

#include "abstractfinder.h"

class RegExpProvider;
class Serie;

class FinderController
{
public:

    //----------------------------------------------------------------------------------------------
    // Constuctors
    explicit FinderController();

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A new finder is added.]
    void addFinder (AbstractFinder * finder);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A request to find the next episode of the serie is returned.]
    void findNextEpisode (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    // REQ [finderType is "Torrent" or "DirectDownload".]
    // ENS [A finder type is enabled or not.]
    void enable (const QString & finderType, bool isEnable);
    
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
    
    QSet<AbstractFinder *>     _finders;
    QList<RegExpProvider *>    _regExpProviders;
    FinderResults              _results;
    bool                       _episodeIsFound;
    QString                    _url;
    QMap<QString, bool>        _typeAuthorized;
};

#endif // FINDERCONTROLLER_H
