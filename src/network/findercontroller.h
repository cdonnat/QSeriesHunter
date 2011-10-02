#ifndef FINDERCONTROLLER_H
#define FINDERCONTROLLER_H

#include <QList>
#include <QMap>
#include <QSet>
#include <QString>

#include "abstractfinder.h"
#include "findersmemento.h"

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
    // REQ [At least one finderType is enabled.]
    // ENS [A request to find the next episode of the serie is returned.]
    void findNextEpisode (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    // REQ [finderType is "Torrent" or "DirectDownload".]
    // ENS [A finder type is enabled or not.]
    void enable (const QString & finderType, bool isEnable);
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [finderType are initialized according to memento.]
    void loadFrom (const FindersMemento & memento);
    
    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [finderType is "Torrent" or "DirectDownload".]
    // ENS [True is returned if the specified finderType is enabled, false otherwise.]
    bool isEnabled (const QString & finderType) const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if the episode is found.]
    bool episodeIsFound () const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [Episode is found.]
    // ENS [True is returned if the episode found is on a torrent.]
    bool episodeFoundIsFromTorrent () const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [Next episode has been found.]
    // ENS [The url of the episode is returned as a string.]
    const QString & getEpisodeUrl () const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Memento of finderType is returned.]
    FindersMemento createMemento() const;
    
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
    FinderResult               _lastResult;
    QMap<QString, bool>        _typeAuthorized;
};

#endif // FINDERCONTROLLER_H
