#include "builder.h"

#include "defaultexternalapprunner.h"
#include "downloader.h"
#include "editserie.h"
#include "editseriedialog.h"
#include "isohunt.h"
#include "loggerwidget.h"
#include "mementocontroller.h"
#include "messagebox.h"
#include "networkaccess.h"
#include "seriesmodel.h"
#include "scheduler.h"
#include "findercontroller.h"
#include "editfinder.h"
#include "editfinderwidget.h"
#include "serieswidget.h"
#include "finderswidget.h";

#include <QDir>
#include <QTableView>
#include <QHeaderView>


//----------------------------------------------------------------------------------------------
Builder::Builder(const QString & initFile)
{
    _loggerWidget = new LoggerWidget;
    
    buildNetwork ();
    buildMessageBox ();
    buildModel();
    buildEditSerie ();
    buildScheduler ();
    buildMementoController (initFile);
    buildView();
    
    _seriesWidget = new SeriesWidget(_loggerWidget, _view, _editSerie, _scheduler, _mementoController);
    _findersWidget = new FindersWidget(_editFinder, _editFinderWidget, _mementoController);
}

//----------------------------------------------------------------------------------------------
void Builder::buildEditSerie ()
{
    Q_ASSERT (_model != NULL);
    Q_ASSERT (_messageBox != NULL);
    _editSerie  = new EditSerie(new EditSerieDialog(), _model, _messageBox);
}

//----------------------------------------------------------------------------------------------
void Builder::buildMementoController (const QString & initFile)
{
    Q_ASSERT (_model != NULL);
    _editFinderWidget  = new EditFinderWidget; 
    _editFinder        = new EditFinder (_finderController, _editFinderWidget);
    _mementoController = new MementoController(_model, _editFinder, initFile);
    _mementoController->loadMemento ();
}

//----------------------------------------------------------------------------------------------
void Builder::buildMessageBox()
{
     _messageBox = new MessageBox();
}

//----------------------------------------------------------------------------------------------
void Builder::buildModel ()
{
    _model = new SeriesModel();
}

//----------------------------------------------------------------------------------------------
void Builder::buildNetwork()
{
    _networkAccess    = new NetworkAccess();
    _finderController = new FinderController();
    _finderController->addFinder (new Isohunt(_networkAccess));
}

//----------------------------------------------------------------------------------------------
void Builder::buildScheduler()
{
    Q_ASSERT (_loggerWidget != NULL);
    Q_ASSERT (_model != NULL);
    Q_ASSERT (_networkAccess != NULL);
    Q_ASSERT (_finderController != NULL);
    _scheduler = new Scheduler(_model, _finderController,
                               new Downloader(_networkAccess, new DefaultExternalAppRunner()),
                               _loggerWidget);
}

//----------------------------------------------------------------------------------------------
void Builder::buildView ()
{
    Q_ASSERT (_model != NULL);
    _view = new QTableView;
    _view->setModel (_model);
    _view->verticalHeader ()->hide ();
	_view->horizontalHeader()->setStretchLastSection(true);
    _view->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
	_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    _view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _view->setSelectionMode(QAbstractItemView::SingleSelection);
    _view->setAlternatingRowColors (true);
	_view->resizeColumnsToContents();
}

/*
//----------------------------------------------------------------------------------------------
Scheduler * const Builder::getScheduler() const
{
    return _scheduler;
}

//----------------------------------------------------------------------------------------------
MementoController * const Builder::getMementoController() const
{
    return _mementoController;
}

//----------------------------------------------------------------------------------------------
EditSerie * const Builder::getEditSerie() const
{
    return _editSerie;
}

//----------------------------------------------------------------------------------------------
QTableView * const Builder::getView() const
{
    return _view;
}


//----------------------------------------------------------------------------------------------
QWidget * const Builder::getEditFinderWidget() const
{
    return _editFinderWidget;
}
*/
QWidget * const Builder::getFindersWidget () const
{
    return _findersWidget->getWidget();
}

LoggerWidget * const Builder::getLoggerWidget() const
{
    return _loggerWidget;
}


SeriesWidget * const Builder::getSeriesWidget() const
{
    return _seriesWidget;
}

