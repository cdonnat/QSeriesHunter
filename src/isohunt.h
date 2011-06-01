#ifndef ISOHUNT_H
#define ISOHUNT_H

#include "itorrentfinder.h"

class INetworkAccess;

class Isohunt : public ITorrentFinder
{
public:
    //-------------------------------------------------------------------------------------------------
    Isohunt(INetworkAccess * networkAccess);

    // Commands:

    //-------------------------------------------------------------------------------------------------
    virtual void search (const QString & name);

    // Queries:

    //-------------------------------------------------------------------------------------------------
    virtual const TorrentFinderResults & getResults  () const;

private :
    INetworkAccess         * _networkAccess;
    TorrentFinderResults     _results;

  // Commands:

  //-------------------------------------------------------------------------------------------------
  void startRequest(const QString & name);

  //-------------------------------------------------------------------------------------------------
  void retrieveResults ();
};

#endif // ISOHUNT_H
