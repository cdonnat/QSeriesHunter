#include "mementocontroller.h"
#include "iseriescontroller.h"
#include "seriesmemento.h"

//----------------------------------------------------------------------------------------------
MementoController::MementoController(ISeriesController * const series,
                                     const QString &           absoluteFilePath):
    _series(series), _initFile(absoluteFilePath)
{
    Q_ASSERT(_series != NULL);
}

//----------------------------------------------------------------------------------------------
void MementoController::loadMemento ()
{
    _series->loadFrom (SeriesMemento::loadFromInitFile (_initFile));
}

//----------------------------------------------------------------------------------------------
void MementoController::saveMemento ()
{
    SeriesMemento  memento = _series->createMemento ();
    memento.saveInInitFile (_initFile);
}
