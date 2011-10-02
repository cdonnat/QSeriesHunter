#include "finderswidget.h"

#include "editfinder.h"
#include "editfinderwidget.h"
#include "mementocontroller.h"

//----------------------------------------------------------------------------------------------
FindersWidget::FindersWidget(EditFinder        * editFinder,
                             EditFinderWidget  * editFinderWidget,
                             MementoController * mementoController):
_editFinder(editFinder), _editFinderWidget(editFinderWidget), _mementoController(mementoController)
{
    Q_ASSERT(_editFinder);
    Q_ASSERT(_editFinderWidget);
    Q_ASSERT(_mementoController);

    connect (_editFinderWidget, SIGNAL(torrentChecked(bool)),
             this             , SLOT(enableTorrent(bool)));
    connect (_editFinderWidget, SIGNAL(directDownloadChecked(bool)), 
             this             , SLOT(enableDirectDownload(bool)));
}

//----------------------------------------------------------------------------------------------
void FindersWidget::enableTorrent(bool isEnable)
{
    _editFinder->enableTorrent(isEnable);
    _mementoController->saveMemento();
}

//----------------------------------------------------------------------------------------------
void FindersWidget::enableDirectDownload(bool isEnable)
{
    _editFinder->enableDirectDownload(isEnable);
    _mementoController->saveMemento();
}

//----------------------------------------------------------------------------------------------
QWidget * const FindersWidget::getWidget() const
{
    return _editFinderWidget;
}