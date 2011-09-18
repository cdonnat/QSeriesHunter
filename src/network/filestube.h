#ifndef FILESTUBE_H
#define FILESTUBE_H

#include "abstractfinder.h"

class INetworkAccess;
class QVariant;
class QXmlStreamReader;

class FilesTube : public AbstractFinder
{
public:
    //----------------------------------------------------------------------------------------------
    explicit FilesTube(INetworkAccess * const networkAccess);

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
  void addItemToResults (QXmlStreamReader & reader);

  //------------------------------------------------------------------------------------------------
  // REQ [Request is successful.]
  // ENS [Results are filled.]
  void retrieveResults ();
};

#endif // FILESTUBE_H
