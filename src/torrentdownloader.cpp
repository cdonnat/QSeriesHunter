#include "torrentdownloader.h"

#include <QDesktopServices>
#include <QFile>
#include <QUrl>
#include "inetworkaccess.h"

TorrentDownloader::TorrentDownloader(INetworkAccess * const networkAccess, QObject *parent) :
    QObject(parent), _networkAccess(networkAccess)
{
    _tmpFile.open ();
    _tmpFile.setAutoRemove (true);
}

void TorrentDownloader::download(const QString & torrentUrl)
{     
    _networkAccess->read(torrentUrl);

    if (_networkAccess->contentIsReady())
    {
        _tmpFile.write(_networkAccess->content());
    }
}


