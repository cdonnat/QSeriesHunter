#ifndef ISOHUNT_H
#define ISOHUNT_H

#include "itorrentfinder.h"

class INetworkAccess;
class QVariant;

class Isohunt : public ITorrentFinder
{
public:
    //----------------------------------------------------------------------------------------------
    Isohunt(INetworkAccess * const networkAccess);

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void search (const QString & name);

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual const TorrentFinderResults & getResults  () const;

private :
    INetworkAccess         * _networkAccess;
    TorrentFinderResults     _results;

  // Commands:

  //------------------------------------------------------------------------------------------------
  void startRequest (const QString & name);

  //------------------------------------------------------------------------------------------------
  void addItemToResults (const QVariant & item);

  //------------------------------------------------------------------------------------------------
  void retrieveResults ();
};

#endif // ISOHUNT_H
