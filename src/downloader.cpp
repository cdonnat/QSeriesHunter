#include "downloader.h"

#include <QFile>
#include <QFileInfo>
#include <QTemporaryFile>
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
}

//----------------------------------------------------------------------------------------------
void Downloader::downloadTorrent (const QString & torrentUrl)
{     
    _networkAccess->read(torrentUrl);
    if (_networkAccess->contentIsReady())
    {
        captureDownloadInTorrentFile ();
    }
}

void Downloader::captureDownloadInTorrentFile ()
{
    Q_ASSERT(downloadIsSuccessful ());
    QTemporaryFile tmpFile;
    tmpFile.open ();
    tmpFile.write(_networkAccess->content());
    tmpFile.close ();
    //
    QFileInfo             fileInfo (tmpFile);
    _lastDownloadedFile = fileInfo.absoluteFilePath ().append (".torrent");
    QFile::copy (fileInfo.absoluteFilePath (), _lastDownloadedFile);
}

//----------------------------------------------------------------------------------------------
void Downloader::downloadSerie ()
{
    Q_ASSERT(downloadIsSuccessful ());
    _serieDownloader->download (_lastDownloadedFile);
}

//----------------------------------------------------------------------------------------------
bool Downloader::downloadIsSuccessful () const
{
    return _networkAccess->contentIsReady();
}

