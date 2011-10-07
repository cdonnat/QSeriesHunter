#include "mementocontroller.h"
#include "iseriescontroller.h"
#include "editfinder.h"
#include "seriesmemento.h"
#include "findersmemento.h"

#include <QFile>
#include <QDataStream>
#include <fstream>

#include "yaml-cpp/yaml.h"

//----------------------------------------------------------------------------------------------
MementoController::MementoController(ISeriesController * const series,
                                     EditFinder        * const finders,
                                     const QString &           absoluteFilePathWithoutExtension):
_series(series),
_finders(finders),
_yamlFile(absoluteFilePathWithoutExtension + ".yml"),
_iniFile(absoluteFilePathWithoutExtension + ".ini")
{
    Q_ASSERT(_series != NULL && _finders != NULL);
}

//----------------------------------------------------------------------------------------------
void MementoController::readOldIniFileAndDeleteIt(QFile & iniFile)
{
    iniFile.open(QIODevice::ReadOnly);
    
    QDataStream in(&iniFile);       
    in.setVersion (QDataStream::Qt_4_7);
    
    _series->loadFrom (SeriesMemento::loadFromStream (in));
    
    iniFile.close ();
    iniFile.remove();
}

//----------------------------------------------------------------------------------------------
void MementoController::loadMemento ()
{
    if (QFile::exists(_yamlFile))
    {
        std::ifstream fin(_yamlFile.toStdString().c_str());
        YAML::Parser  parser(fin);
        YAML::Node    node;
        parser.GetNextDocument(node);
        _series->loadFrom(SeriesMemento::loadFromNode(node));
        parser.GetNextDocument(node);
        _finders->loadFrom(FindersMemento::loadFromNode(node));        
    }
    else
    {
        QFile  iniFile(_iniFile);
        if (iniFile.exists())
        {
            readOldIniFileAndDeleteIt(iniFile);
            saveMemento();
        }
    }
}

//----------------------------------------------------------------------------------------------
void MementoController::saveMemento ()
{
    std::ofstream  yamlFile(_yamlFile.toStdString().c_str());
    
    YAML::Emitter out;
    
    out << _series->createMemento();
    out << _finders->createMemento();
    yamlFile << out.c_str();
    
    yamlFile.close();
}
