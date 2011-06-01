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
    explicit TorrentDownloader(INetworkAccess * const networkAccess, QObject *parent = 0);

    // Commands :

    void download(const QString & torrentUrl);

private:
    INetworkAccess * const _networkAccess;
    QTemporaryFile         _tmpFile;
};

#endif // TORRENTDOWNLOADER_H
