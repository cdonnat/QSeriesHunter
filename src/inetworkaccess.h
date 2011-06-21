#ifndef INETWORKACCESS_H
#define INETWORKACCESS_H

class QString;
class QByteArray;

class INetworkAccess
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~INetworkAccess() {}

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Content located at specified url is returned.]
    virtual void read (const QString & url) = 0;

    // Queries:


    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if content is ready.]
    virtual bool contentIsReady() const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [contentIsReady]
    // ENS [Url content read is returned.]
    virtual const QByteArray & content() const = 0;
};

#endif // INETWORKACCESS_H
