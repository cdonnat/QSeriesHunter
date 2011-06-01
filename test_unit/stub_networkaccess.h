#ifndef STUB_NETWORKACCESS_H
#define STUB_NETWORKACCESS_H

#include "inetworkaccess.h"

#include <QString>
#include <QByteArray>

class NetworkAccessStub : public INetworkAccess
{
public:
    NetworkAccessStub();

    // Commands:

    virtual void read(const QString &url);

    virtual void setIsReady (bool isReady);
    virtual void setContent (const QString & content);

    // Queries:
    virtual bool contentIsReady()        const;
    virtual const QByteArray & content() const;
    virtual const QString    & url()     const;

private:
    QString     urlRead;
    QByteArray  buffer;
    bool        isReady;
};

#endif // STUB_NETWORKACCESS_H
