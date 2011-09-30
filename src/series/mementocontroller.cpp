#include "mementocontroller.h"
#include "iseriescontroller.h"
#include "findercontroller.h"
#include "seriesmemento.h"
#include "findersmemento.h"

#include <QFile>
#include <QDataStream>

//----------------------------------------------------------------------------------------------
MementoController::MementoController(ISeriesController * const series,
                                     FinderController  * const finders,
                                     const QString &           absoluteFilePath):
    _series(series),_finders(finders), _initFile(absoluteFilePath)
{
    Q_ASSERT(_series != NULL && _finders != NULL);
}

//----------------------------------------------------------------------------------------------
void MementoController::loadMemento ()
{
    QFile  initFile(_initFile);
    if (initFile.exists())
    {
        initFile.open(QIODevice::ReadOnly);
    
        QDataStream in(&initFile);       
        in.setVersion (QDataStream::Qt_4_7);
    
        _series->loadFrom (SeriesMemento::loadFromStream (in));
        _finders->loadFrom (FindersMemento::loadFromStream (in));
        initFile.close ();
    }
}

//----------------------------------------------------------------------------------------------
void MementoController::saveMemento ()
{
    QFile  initFile(_initFile);
    initFile.open(QIODevice::WriteOnly);
    
    QDataStream out(&initFile);
    out.setVersion (QDataStream::Qt_4_7);
    
    out << _series->createMemento ();
    out << _finders->createMemento ();
    
    initFile.close ();
}
