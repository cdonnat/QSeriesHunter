#include "downloader.h"

#include <QFile>
#include <QFileInfo>
#include <QTemporaryFile>
#include <QUrl>

#include "inetworkaccess.h"
#include "idefaultexternalapprunner.h"


//----------------------------------------------------------------------------------------------
Downloader::Downloader(INetworkAccess            * const networkAccess,
                       IDefaultExternalAppRunner * const defaultAppRunner) :
    _networkAccess(networkAccess), _defaultAppRunner(defaultAppRunner)
{
    Q_ASSERT (_networkAccess != NULL);
    Q_ASSERT (_defaultAppRunner != NULL);
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

//----------------------------------------------------------------------------------------------
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
void Downloader::runTorrentWithExternalDefaultApp ()
{
    Q_ASSERT(downloadIsSuccessful ());
    _defaultAppRunner->open (_lastDownloadedFile);
}

//----------------------------------------------------------------------------------------------
bool Downloader::downloadIsSuccessful () const
{
    return _networkAccess->contentIsReady();
}

