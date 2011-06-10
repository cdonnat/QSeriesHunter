#include "networkaccess.h"

#include <QtGlobal>
#include <QObject>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>

const int timeoutInMs = 3000;

//----------------------------------------------------------------------------------------------
NetworkAccess::NetworkAccess():
    _networkAccessReply(NULL), _networkAccessManager(new QNetworkAccessManager()) {}

//----------------------------------------------------------------------------------------------
NetworkAccess::~NetworkAccess()
{
    _networkAccessManager->deleteLater();
}

//----------------------------------------------------------------------------------------------
void NetworkAccess::read (const QString & url)
{
    QNetworkRequest  networkRequest(url);
    QEventLoop       loop;
    QTimer           timer;

    timer.start(timeoutInMs);

    _networkAccessReply = _networkAccessManager->get(networkRequest);

    QObject::connect (_networkAccessReply, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));

    loop.exec();

    if (this->contentIsReady())
    {
        _contentRead = _networkAccessReply->readAll();
        _networkAccessReply->deleteLater();
    }
}

//----------------------------------------------------------------------------------------------
bool NetworkAccess::contentIsReady() const
{
    return (_networkAccessReply != NULL) &&
            (_networkAccessReply->error() == QNetworkReply::NoError);
}

//----------------------------------------------------------------------------------------------
const QByteArray & NetworkAccess::content() const
{
    Q_ASSERT(this->contentIsReady());
    return _contentRead;
}
