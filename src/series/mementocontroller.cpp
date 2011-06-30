#include "mementocontroller.h"
#include "iseriescontroller.h"
#include "seriesmemento.h"

//----------------------------------------------------------------------------------------------
MementoController::MementoController(ISeriesController * series,
                                     const QString &     absoluteFilePath):
    _series(series), _initFile(absoluteFilePath)
{
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
