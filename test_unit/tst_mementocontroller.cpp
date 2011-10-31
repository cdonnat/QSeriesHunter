#include "tst_mementocontroller.h"

#include "findercontroller.h"
#include "editfinderwidget.h"
#include "stub_seriesprovider.h"

#include <QString>
#include <QDate>
#include <QDir>
#include <QFile>
#include <QList>
#include <QTest>

#include "shared.h"

const QString configFile = "test";


TestMementoController::TestMementoController(QObject *parent) :
QObject(parent), _series(new SeriesProviderStub, QDate::currentDate())
{
    _finderController = new FinderController;
    _editFinder       = new EditFinder(_finderController, 
                                       new EditFinderWidget);
    _sut = new MementoController(&_series, _editFinder, configFile);
}

//----------------------------------------------------------------------------------------------
void clean()
{
    QFile::remove (configFile + ".ini");
    QFile::remove (configFile + ".yml");
}


//----------------------------------------------------------------------------------------------
void TestMementoController::initTestCase()
{
    clean();
}

//----------------------------------------------------------------------------------------------
void TestMementoController::cleanUpTestCase()
{
    clean();
}

//----------------------------------------------------------------------------------------------
QDataStream & operator<< (QDataStream & dataStream, const Serie & serie)
{
    dataStream << serie.name ();
    dataStream << serie.season ();
    dataStream << serie.lastEpisode();
    return dataStream;
}

//----------------------------------------------------------------------------------------------
void writeIniFile (const QString & fileName)
{
    QFile  iniFile(fileName);
    iniFile.open(QIODevice::WriteOnly);
      
    QDataStream in(&iniFile);       
    in.setVersion (QDataStream::Qt_4_7);
    
    QList<Serie> series;
    series << houseSeason1 << dexterSeason10;
    in << series;

    iniFile.close ();
}

//----------------------------------------------------------------------------------------------
void TestMementoController::testIniFileReading ()
{
    writeIniFile(configFile + ".ini");
    QVERIFY2(QFile::exists(configFile + ".ini"), "ini file exists");
    
    TestMementoController fixture;
    fixture._sut->loadMemento();
    
    QVERIFY2(fixture._series.nbSeries() == 2, "Expected series number");
    QVERIFY2(fixture._series.at(0) == dexterSeason10, "Expected first serie");
    QVERIFY2(fixture._series.at(1) == houseSeason1, "Expected second serie");
    QVERIFY2(!QFile::exists(configFile + ".ini"), "ini file deleted");
    QVERIFY2(QFile::exists(configFile + ".yml"), "yaml file created");
}


//----------------------------------------------------------------------------------------------
void TestMementoController::testCase ()
{
    
    TestMementoController fixture;

    fixture._series.addSerie (houseSeason1);
    fixture._series.addSerie (houseSeason2);
    fixture._series.addSerie (himymSeason3);
    fixture._finderController->enable("Torrent", false);
    fixture._finderController->enable("DirectDownload", true);
    
    fixture._sut->saveMemento();
    
    QVERIFY2(QFile::exists(configFile + ".yml"), "yml file created");
    
    fixture._series.removeSerie(houseSeason1);
    fixture._series.removeSerie(houseSeason2);
    fixture._series.removeSerie(himymSeason3);
    fixture._finderController->enable("Torrent", true);
    
    fixture._sut->loadMemento();
    
    QVERIFY2(fixture._series.at(0) == houseSeason1, "First serie should be loaded");
    QVERIFY2(fixture._finderController->isEnabled("Torrent") == false, 
             "Torrent should not be enable");
    QVERIFY2(fixture._finderController->isEnabled("DirectDownload") == true, 
             "DDL should be enable");
}
