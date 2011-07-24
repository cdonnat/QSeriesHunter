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
#include "torrentfindercontroller.h"

#include <QDir>
#include <QTableView>
#include <QHeaderView>


//----------------------------------------------------------------------------------------------
Builder::Builder(ILogger * logger, const QString & initFile):_logger(logger)
{
    Q_ASSERT(logger != NULL);
    buildNetwork ();
    buildMessageBox ();
    buildModel();
    buildEditSerie ();
    buildMementoController (initFile);
    buildScheduler ();
    buildView();
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
    _mementoController = new MementoController(_model, initFile);
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
    _networkAccess           = new NetworkAccess();
    _torrentFinderController = new TorrentFinderController();
    _torrentFinderController->addTorrentFinder (new Isohunt(_networkAccess));

}

//----------------------------------------------------------------------------------------------
void Builder::buildScheduler()
{
    Q_ASSERT (_logger != NULL);
    Q_ASSERT (_model != NULL);
    Q_ASSERT (_networkAccess != NULL);
    Q_ASSERT (_torrentFinderController != NULL);
    _scheduler = new Scheduler(_model, _torrentFinderController,
                               new Downloader(_networkAccess, new DefaultExternalAppRunner()),
                               _logger);
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
