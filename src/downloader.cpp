#include "downloader.h"

#include <QFile>
#include <QFileInfo>
#include <QUrl>

#include "inetworkaccess.h"
#include "iseriedownloader.h"

//----------------------------------------------------------------------------------------------
Downloader::Downloader(INetworkAccess   * const networkAccess,
                       ISerieDownloader * const serieDownloader) :
    _networkAccess(networkAccess), _serieDownloader(serieDownloader)
{
    Q_ASSERT (_networkAccess != NULL);
    Q_ASSERT (_serieDownloader != NULL);
    _tmpFile.setAutoRemove (true);
}

//----------------------------------------------------------------------------------------------
void Downloader::downloadTorrent (const QString & torrentUrl)
{     
    _networkAccess->read(torrentUrl);
    if (_networkAccess->contentIsReady())
    {
        _tmpFile.open ();
        _tmpFile.write(_networkAccess->content());
        _tmpFile.close ();
    }
}

//----------------------------------------------------------------------------------------------
void Downloader::downloadSerie ()
{
    QFileInfo   fileInfo (_tmpFile);
    QString     torrentFile(fileInfo.absoluteFilePath ().append (".torrent"));
    QFile::copy (fileInfo.absoluteFilePath (), torrentFile);
    _serieDownloader->download (torrentFile);
}

//----------------------------------------------------------------------------------------------
bool Downloader::downloadIsSuccessful () const
{
    return _networkAccess->contentIsReady();
}

