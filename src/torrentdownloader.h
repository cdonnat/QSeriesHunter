#ifndef TORRENTDOWNLOADER_H
#define TORRENTDOWNLOADER_H

#include <QObject>
#include <QString>

class INetworkAccess;

class TorrentDownloader : public QObject
{
    Q_OBJECT
public:
    explicit TorrentDownloader(INetworkAccess * networkAccess, QObject *parent = 0);

    // Commands :

    void download(const QString & fileToDownload, const QString & absolutePathToFile);

private:
    INetworkAccess * _networkAccess;

};

#endif // TORRENTDOWNLOADER_H
