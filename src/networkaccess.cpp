#include "networkaccess.h"

#include <QtGlobal>
#include <QObject>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>

const int timeoutInMs = 3000;

NetworkAccess::NetworkAccess():
    networkAccessReply(NULL), networkAccessManager(new QNetworkAccessManager()) {}

NetworkAccess::~NetworkAccess()
{
    this->networkAccessManager->deleteLater();
}

void NetworkAccess::read (const QString & url)
{
    QNetworkRequest  networkRequest(url);
    QEventLoop       loop;
    QTimer           timer;

    timer.setInterval(timeoutInMs);
    this->networkAccessReply = this->networkAccessManager->get(networkRequest);

    QObject::connect (this->networkAccessReply, SIGNAL(finished()), &loop, SLOT(quit()));
    QObject::connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));

    loop.exec();

    if (this->contentIsReady())
    {
        this->contentRead = this->networkAccessReply->readAll();
        this->networkAccessReply->deleteLater();
    }
}

bool NetworkAccess::contentIsReady() const
{
    return (this->networkAccessReply != NULL) &&
            (this->networkAccessReply->error() == QNetworkReply::NoError);
}

const QByteArray & NetworkAccess::content() const
{
    Q_ASSERT(this->contentIsReady());
    return this->contentRead;
}
