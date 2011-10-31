#include "builder.h"

#include "defaultexternalapprunner.h"
#include "downloader.h"
#include "editserie.h"
#include "editseriedialog.h"
#include "isohunt.h"
#include "filestube.h"
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
#include "finderswidget.h"
#include "seriesprovider.h"

#include <QDir>
#include <QDateTime>
#include <QTableView>
#include <QHeaderView>


//----------------------------------------------------------------------------------------------
Builder::Builder(const QString & initFile)
{
    _loggerWidget = new LoggerWidget;
    
    buildNetwork ();
    buildModel();
    buildEditSerie ();
    buildScheduler ();
    buildMementoController (initFile);
    buildView();
}

//----------------------------------------------------------------------------------------------
void Builder::buildNetwork()
{
    _networkAccess    = new NetworkAccess();
    _finderController = new FinderController();
    _finderController->addFinder (new Isohunt(_networkAccess));
    _finderController->addFinder (new FilesTube(_networkAccess));
}


//----------------------------------------------------------------------------------------------
void Builder::buildModel ()
{
    _seriesProvider = new SeriesProvider(_networkAccess, 
                                         QDateTime::currentDateTime());
    _seriesProvider->searchAllSeries();
    _model          = new SeriesModel(_seriesProvider, QDate::currentDate());
}

//----------------------------------------------------------------------------------------------
void Builder::buildEditSerie ()
{
    Q_ASSERT (_model != NULL);
    _messageBox = new MessageBox();
    _editSerie  = new EditSerie(new EditSerieDialog(_seriesProvider), _model, _messageBox);
}

//----------------------------------------------------------------------------------------------
void Builder::buildScheduler()
{
    Q_ASSERT (_loggerWidget     != NULL);
    Q_ASSERT (_model            != NULL);
    Q_ASSERT (_networkAccess    != NULL);
    Q_ASSERT (_finderController != NULL);
    _scheduler = new Scheduler(_model,
                               _finderController,
                               new Downloader(_networkAccess, new DefaultExternalAppRunner()),
                               _loggerWidget);
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
    //
    _seriesWidget = new SeriesWidget(_loggerWidget, _view, _editSerie, _scheduler, _mementoController);
    _findersWidget = new FindersWidget(_editFinder, _editFinderWidget, _mementoController);
    
    QObject::connect (_model, SIGNAL(seriesChanged()), _seriesWidget, SLOT(saveMemento()));
}

//----------------------------------------------------------------------------------------------
QWidget * const Builder::getFindersWidget () const
{
    return _findersWidget->getWidget();
}

//----------------------------------------------------------------------------------------------
LoggerWidget * const Builder::getLoggerWidget() const
{
    return _loggerWidget;
}

//----------------------------------------------------------------------------------------------
SeriesWidget * const Builder::getSeriesWidget() const
{
    return _seriesWidget;
}

