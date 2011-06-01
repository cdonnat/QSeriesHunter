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
    NetworkAccess();
    ~NetworkAccess();

    // Commands:

    virtual void read (const QString & url);

    // Queries:

    virtual bool               contentIsReady() const;
    virtual const QByteArray & content()        const;

private:
  QByteArray               contentRead;
  QNetworkReply          * networkAccessReply;
  QNetworkAccessManager  * networkAccessManager;
};

#endif // NETWORKACCESS_H
