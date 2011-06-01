#ifndef TORRENTDOWNLOADER_H
#define TORRENTDOWNLOADER_H

#include <QObject>
#include <QTemporaryFile>

class QString;
class INetworkAccess;

class TorrentDownloader : public QObject
{
    Q_OBJECT
public:

    //----------------------------------------------------------------------------------------------
    // REQ [NetworkAccess is not null.]
    // ENS [.]
    explicit TorrentDownloader(INetworkAccess * const networkAccess, QObject *parent = 0);

    // Commands :

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent located at torrentUrl is downloaded.]
    void download(const QString & torrentUrl);

private:
    INetworkAccess * const _networkAccess;
    QTemporaryFile         _tmpFile;
};

#endif // TORRENTDOWNLOADER_H
