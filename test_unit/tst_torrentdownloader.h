#ifndef TST_TORRENTDOWNLOADER_H
#define TST_TORRENTDOWNLOADER_H

#include <QObject>
#include <QString>

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
    void testFailCase();

private :
    QString              fileName;
    NetworkAccessStub  * networkAccess;
    TorrentDownloader    * sut;
};

#endif // TST_TORRENTDOWNLOADER_H
