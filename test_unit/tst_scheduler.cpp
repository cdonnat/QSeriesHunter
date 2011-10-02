#include "tst_scheduler.h"

#include "shared.h"
#include "log.h"
#include "scheduler.h"
#include "serie.h"
#include "seriesmodel.h"
#include "downloader.h"
#include "findercontroller.h"

#include "stub_logger.h"
#include "stub_networkaccess.h"
#include "stub_finder.h"
#include "stub_defaultapprunner.h"

#include <QFile>
#include <QTest>

TestScheduler::TestScheduler(QObject *parent) :
    QObject(parent)
{
    _series          = new SeriesModel();
    _finders         = new FinderController();
    _finder          = new FinderStub();
    _network         = new NetworkAccessStub;
    _serieDownloader = new DefaultAppRunnerStub;
    _downloader      = new Downloader(_network, _serieDownloader);
    _logger          = new LoggerStub;
    _sut             = new Scheduler(_series, _finders, _downloader, _logger);

    _finders->addFinder (_finder);
}

 void TestScheduler::testNoSeries()
 {
    TestScheduler  fixture;
    fixture._sut->update ();
    QVERIFY2 (fixture._logger->warning () == noSeriesFollowed, "Warning no series");
 }

 void TestScheduler::testNominalTorrent ()
 {
     TestScheduler fixture;

     fixture._series->addSerie (houseSeason1);
     fixture._finder->setResults (FinderResults () <<
                                  FinderResult("House.S01.E01", "house_torrent", true, 10));
     fixture._network->setIsReady (true);

     fixture._sut->update ();

     QVERIFY2 (fixture._finder->getRequest () == "|House S01E01|House 1x01", "Nominal request");
     QVERIFY2 (fixture._network->url () == "house_torrent", "Nominal url");
     QVERIFY2 (fixture._series->at(0).lastEpisode () == 1, "Nominal inc");
     QVERIFY2 (fixture._logger->success ().contains ("Season 1 Episode 1"), "info display");
     QVERIFY2 (QFile::exists (fixture._serieDownloader->_absoluteFileName),
               "Torrent downloaded");
}

void TestScheduler::testNominalDdl ()
{
    TestScheduler fixture;
    
    fixture._series->addSerie (houseSeason1);
    fixture._finder->setResults (FinderResults () <<
                                 FinderResult("House.S01.E01", "house_ddl_url", false, 10));
    fixture._network->setIsReady (true);
    
    fixture._sut->update ();
    
    QVERIFY2 (fixture._finder->getRequest () == "|House S01E01|House 1x01", "Nominal request");
    QVERIFY2 (fixture._series->at(0).lastEpisode () == 1, "Nominal inc");
    QVERIFY2 (fixture._logger->success ().contains ("Season 1 Episode 1"), "info display");
    QVERIFY2 (fixture._logger->info ().contains ("house_ddl_url"), "url displayed");
}

void TestScheduler::testFail()
{
    TestScheduler fixture;

    fixture._series->addSerie (houseSeason1);
    fixture._network->setIsReady (true);

    fixture._sut->update ();

    QVERIFY2 (fixture._finder->getRequest () == "|House S01E01|House 1x01", "Fail request");
    QVERIFY2 (fixture._series->at(0).lastEpisode () == 0, "not inc");
}
