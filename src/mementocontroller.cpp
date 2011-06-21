#include "mementocontroller.h"
#include "iseriescontroller.h"
#include "seriesmemento.h"

//----------------------------------------------------------------------------------------------
MementoController::MementoController(ISeriesController * series):_series(series)
{
}

//----------------------------------------------------------------------------------------------
void MementoController::loadMemento ()
{
    _series->loadFrom (SeriesMemento::loadFromInitFile ());
}

//----------------------------------------------------------------------------------------------
void MementoController::saveMemento ()
{
    SeriesMemento  memento = _series->createMemento ();
    memento.saveInInitFile ();
}
