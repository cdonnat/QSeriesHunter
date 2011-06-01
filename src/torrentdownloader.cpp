#include "torrentdownloader.h"

#include <QFile>
#include "inetworkaccess.h"

TorrentDownloader::TorrentDownloader(INetworkAccess * networkAccess, QObject *parent) :
    QObject(parent), _networkAccess(networkAccess)
{
}

void TorrentDownloader::download(const QString & fileToDownload, const QString & absolutePathToFile)
{     
    _networkAccess->read(fileToDownload);

    if (_networkAccess->contentIsReady())
    {
        QFile output(absolutePathToFile);
        output.open(QIODevice::WriteOnly);
        output.write(_networkAccess->content());
        output.close();
    }
}


