#ifndef TORRENTDOWNLOADER_H
#define TORRENTDOWNLOADER_H

#include <QObject>
#include <QTemporaryFile>

class QString;
class INetworkAccess;
class ISerieDownloader;

class Downloader
{
public:

    //----------------------------------------------------------------------------------------------
    // REQ [Inputs are not null.]
    // ENS [.]
    explicit Downloader(INetworkAccess   * const networkAccess,
                        ISerieDownloader * const serieDownloader);

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent file located at torrentUrl is downloaded.]
    void downloadTorrent (const QString & torrentUrl);

    //----------------------------------------------------------------------------------------------
    // REQ [downloadIsSuccessful.]
    // ENS [The serie is downloaded.]
    void downloadSerie ();

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent located at torrentUrl is downloaded.]
    bool downloadIsSuccessful () const;

private:
    INetworkAccess   * const _networkAccess;
    ISerieDownloader * const _serieDownloader;
    QTemporaryFile           _tmpFile;
};

#endif // TORRENTDOWNLOADER_H