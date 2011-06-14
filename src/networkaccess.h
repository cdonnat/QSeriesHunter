#ifndef NETWORKACCESS_H
#define NETWORKACCESS_H

#include <QByteArray>

#include "inetworkaccess.h"

class QString;
class QNetworkReply;
class QNetworkAccessManager;

class NetworkAccess : public INetworkAccess
{
public:
    // Constructors & Destructors

    //----------------------------------------------------------------------------------------------
    explicit NetworkAccess();

    //----------------------------------------------------------------------------------------------
    virtual ~NetworkAccess();

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void read (const QString & url);

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual bool  contentIsReady() const;

    //----------------------------------------------------------------------------------------------
    virtual const QByteArray & content()  const;

private:
  QByteArray               _contentRead;
  QNetworkReply          * _networkAccessReply;
  QNetworkAccessManager  * _networkAccessManager;
};

#endif // NETWORKACCESS_H
