#include "tst_scheduler.h"

#include "shared.h"
#include "log.h"
#include "scheduler.h"
#include "serie.h"
#include "seriesmodel.h"
#include "downloader.h"
#include "torrentfindercontroller.h"

#include "stub_logger.h"
#include "stub_networkaccess.h"
#include "stub_torrentfinder.h"
#include "stub_defaultapprunner.h"

#include <QFile>
#include <QTest>

TestScheduler::TestScheduler(QObject *parent) :
    QObject(parent)
{
    _series          = new SeriesModel();
    _finders         = new TorrentFinderController();
    _finder          = new TorrentFinderStub();
    _network         = new NetworkAccessStub;
    _serieDownloader = new DefaultAppRunnerStub;
    _downloader      = new Downloader(_network, _serieDownloader);
    _logger          = new LoggerStub;
    _sut             = new Scheduler(_series, _finders, _downloader, _logger);

    _finders->addTorrentFinder (_finder);
}

 void TestScheduler::testNoSeries()
 {
    TestScheduler  fixture;
    fixture._sut->update ();
    QVERIFY2 (fixture._logger->warning () == noSeriesFollowed, "Warning no series");
 }

 void TestScheduler::testNominal ()
 {
     TestScheduler fixture;

     fixture._series->addSerie (houseSeason1, 1);
     fixture._finder->setResults (TorrentFinderResults () <<
                                  TorrentFinderResult("House.S01.E02", "house_torrent", 10));
     fixture._network->setIsReady (true);

     fixture._sut->update ();

     QVERIFY2 (fixture._finder->getRequest () == "House S01E02", "Nominal request");
     QVERIFY2 (fixture._network->url () == "house_torrent", "Nominal url");
     QVERIFY2 (fixture._series->lastEpisodeDl (houseSeason1) == 2, "Nominal inc");
     QVERIFY2 (QFile::exists (fixture._serieDownloader->_absoluteFileName),
               "Torrent downloaded");
}

void TestScheduler::testFail()
{
    TestScheduler fixture;

    fixture._series->addSerie (houseSeason1, 1);
    fixture._network->setIsReady (true);

    fixture._sut->update ();

    QVERIFY2 (fixture._finder->getRequest () == "House S01E02", "Fail request");
    QVERIFY2 (fixture._series->lastEpisodeDl (houseSeason1) == 1, "not inc");
}
