#ifndef ISOHUNT_H
#define ISOHUNT_H

#include "itorrentfinder.h"

class INetworkAccess;
class QVariant;

class Isohunt : public ITorrentFinder
{
public:
    //----------------------------------------------------------------------------------------------
    explicit Isohunt(INetworkAccess * const networkAccess);

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
  // REQ [None.]
  // ENS [A request is sent to isoHunt server.]
  void startRequest (const QString & serieTitle);

  //------------------------------------------------------------------------------------------------
  // REQ [None.]
  // ENS [Item is added to request results.]
  void addItemToResults (const QVariant & item);

  //------------------------------------------------------------------------------------------------
  // REQ [Request is successful.]
  // ENS [Results are filled.]
  void retrieveResults ();
};

#endif // ISOHUNT_H
