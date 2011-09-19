#ifndef ISOHUNT_H
#define ISOHUNT_H

#include "abstractfinder.h"

class INetworkAccess;
class QVariant;

class Isohunt : public AbstractFinder
{
public:
    //----------------------------------------------------------------------------------------------
    explicit Isohunt(INetworkAccess * const networkAccess);

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void find (const QString & name);

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual const FinderResults & getResults  () const;

    
private :
    INetworkAccess  * const _networkAccess;
    FinderResults           _results;

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
