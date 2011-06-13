#ifndef TST_TORRENTDOWNLOADER_H
#define TST_TORRENTDOWNLOADER_H

#include <QObject>

class NetworkAccessStub;
class SerieDownloaderStub;
class Downloader;

class TestDownloader : public QObject
{
    Q_OBJECT

public:
    TestDownloader();
    virtual ~TestDownloader();

private Q_SLOTS:
    void testNominalCase();
    void testFailCase();

private :
    NetworkAccessStub    * _networkAccess;
    SerieDownloaderStub  * _serieDownloader;
    Downloader           * _sut;
};

#endif // TST_TORRENTDOWNLOADER_H
