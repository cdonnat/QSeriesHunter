#ifndef TORRENTDOWNLOADER_H
#define TORRENTDOWNLOADER_H

#include <QString>

class INetworkAccess;
class IDefaultExternalAppRunner;

class Downloader
{
public:

    //----------------------------------------------------------------------------------------------
    // REQ [Inputs are not null.]
    // ENS [.]
    explicit Downloader(INetworkAccess            * const networkAccess,
                        IDefaultExternalAppRunner * const defaultAppRunner);

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent file located at torrentUrl is downloaded.]
    void downloadTorrent (const QString & torrentUrl);

    //----------------------------------------------------------------------------------------------
    // REQ [downloadIsSuccessful.]
    // ENS [The torrent is run with the default external application associated to .torrent.]
    void runTorrentWithExternalDefaultApp ();

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent located at torrentUrl is downloaded.]
    bool downloadIsSuccessful () const;

private:

    //----------------------------------------------------------------------------------------------
    // REQ [downloadIsSuccessful.]
    // ENS [Torrent located at torrentUrl is downloaded.]
    void captureDownloadInTorrentFile();

private:
    INetworkAccess            * const _networkAccess;
    IDefaultExternalAppRunner * const _defaultAppRunner;
    QString                           _lastDownloadedFile;
};

#endif // TORRENTDOWNLOADER_H
