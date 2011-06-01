#include "stub_networkaccess.h"

NetworkAccessStub::NetworkAccessStub() : isReady(false)
{
}

void NetworkAccessStub::read(const QString &url)
{
    this->urlRead = url;
}

void NetworkAccessStub::setIsReady (bool isReady)
{
    this->isReady = isReady;
}

void NetworkAccessStub::setContent (const QString & content)
{
    this->buffer = content.toStdString().c_str();
}

bool NetworkAccessStub::contentIsReady() const
{
    return this->isReady;
}

const QByteArray & NetworkAccessStub::content() const
{
    return this->buffer;
}

const QString & NetworkAccessStub::url() const
{
    return this->urlRead;
}
