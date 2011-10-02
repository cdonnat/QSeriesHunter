#include "editfinder.h"

#include "findercontroller.h"
#include "ieditfinderwidget.h"

#include <QtGlobal>

//----------------------------------------------------------------------------------------------
EditFinder::EditFinder(FinderController   * const finderController,
                       IEditFinderWidget  * const editFinderWidget):
_editFinderWidget(editFinderWidget), _finderController(finderController)
{
    Q_ASSERT(_finderController != NULL);
    Q_ASSERT(_editFinderWidget != NULL);
}


//----------------------------------------------------------------------------------------------
void EditFinder::enableTorrent (bool isEnable)
{
    _editFinderWidget->enableTorrent(isEnable);
    _finderController->enable("Torrent", isEnable);
}

//----------------------------------------------------------------------------------------------
void EditFinder::enableDirectDownload (bool isEnable)
{
    _editFinderWidget->enableDirectDownload(isEnable);
    _finderController->enable("DirectDownload", isEnable);
}

//----------------------------------------------------------------------------------------------
FindersMemento EditFinder::createMemento() const
{
    return _finderController->createMemento();
}

//----------------------------------------------------------------------------------------------
void EditFinder::loadFrom(const FindersMemento & memento)
{
    _finderController->loadFrom(memento);
    _editFinderWidget->enableTorrent(_finderController->isEnabled("Torrent"));
    _editFinderWidget->enableDirectDownload(_finderController->isEnabled("DirectDownload"));
}