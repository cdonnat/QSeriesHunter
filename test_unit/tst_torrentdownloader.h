#ifndef TST_TORRENTDOWNLOADER_H
#define TST_TORRENTDOWNLOADER_H

#include <QObject>

class NetworkAccessStub;
class TorrentDownloader;

class TestTorrentDownloader : public QObject
{
    Q_OBJECT

public:
    TestTorrentDownloader();
    virtual ~TestTorrentDownloader();

private Q_SLOTS:
    void testNominalCase();

private :
    NetworkAccessStub    * networkAccess;
    TorrentDownloader    * sut;
};

#endif // TST_TORRENTDOWNLOADER_H
