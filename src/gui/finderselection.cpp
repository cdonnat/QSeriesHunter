#include "finderselection.h"

#include "findercontroller.h"
#include "ifinderselectionwidget.h"

#include <QtGlobal>

//----------------------------------------------------------------------------------------------
FinderSelection::FinderSelection(FinderController       * const finderController,
                                 IFinderSelectionWidget * const finderSelectionWidget):
_finderSelectionWidget(finderSelectionWidget), _finderController(finderController)
{
    Q_ASSERT(_finderController != NULL);
    Q_ASSERT(_finderSelectionWidget != NULL);
}


//----------------------------------------------------------------------------------------------
void FinderSelection::enableTorrent (bool isEnable)
{
    _finderSelectionWidget->enableTorrent(isEnable);
    _finderController->enable("Torrent", isEnable);
}

//----------------------------------------------------------------------------------------------
void FinderSelection::enableDirectDownload (bool isEnable)
{
    _finderSelectionWidget->enableDirectDownload(isEnable);
    _finderController->enable("DirectDownload", isEnable);
}


FindersMemento FinderSelection::createMemento() const
{
    return _finderController->createMemento();
}

void FinderSelection::loadFrom(const FindersMemento & memento)
{
    _finderController->loadFrom(memento);
    _finderSelectionWidget->enableTorrent(_finderController->isEnabled("Torrent"));
    _finderSelectionWidget->enableDirectDownload(_finderController->isEnabled("DirectDownload"));
}