#include "serie.h"
#include "serieswidget.h"
#include "seriesmodel.h"
#include "editseriedialog.h"
#include "loggerwidget.h"
#include "scheduler.h"
#include "torrentfindercontroller.h"
#include "isohunt.h"
#include "downloader.h"
#include "networkaccess.h"
#include "seriedownloader.h"
#include "editserie.h"
#include "messagebox.h"
#include "mementocontroller.h"

#include <QItemSelectionModel>
#include <QTextEdit>
#include <QHeaderView>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSplitter>
#include <QDockWidget>

//----------------------------------------------------------------------------------------------
SeriesWidget::SeriesWidget(QWidget *parent) :
    QWidget(parent)
{
    buildAttributes();
    buildAndConfigureLayouts ();
    configureView ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::buildAttributes ()
{
    _logger     = new LoggerWidget();
    _model      = new SeriesModel(this);
    _messageBox = new MessageBox();
    _editSerie  = new EditSerie(new EditSerieDialog(),
                               _model,
                               _messageBox);

    NetworkAccess            * networkAccess     = new NetworkAccess();
    TorrentFinderController  * findersController = new TorrentFinderController();
    findersController->addTorrentFinder (new Isohunt(networkAccess));

    _mementoController = new MementoController(_model);
    _mementoController->loadMemento ();

    _scheduler = new Scheduler(_model, findersController,
                               new Downloader(networkAccess, new SerieDownloader()),
                               _logger);
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::buildAndConfigureLayouts ()
{
    QSplitter    * splitter = new QSplitter(Qt::Vertical, this);
    splitter->addWidget (&_view);
    splitter->addWidget (_logger->getTextEdit ());

    QVBoxLayout  * layout = new QVBoxLayout(this);
    layout->addWidget (splitter);
    setLayout (layout);
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::configureView ()
{
    _view.setModel (_model);
    _view.verticalHeader ()->hide ();
    _view.horizontalHeader()->setStretchLastSection(true);
    _view.setSelectionBehavior(QAbstractItemView::SelectRows);
    _view.setEditTriggers(QAbstractItemView::NoEditTriggers);
    _view.setSelectionMode(QAbstractItemView::SingleSelection);
    _view.setAlternatingRowColors (true);
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::add()
{
    _editSerie->add ();
    _mementoController->saveMemento ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::edit()
{
    QModelIndexList  selectedRows = _view.selectionModel ()->selectedRows ();
    QModelIndex      index;
    if (!selectedRows.isEmpty ())
    {
        index = selectedRows.front ();
    }
    _editSerie->edit(index);
    _mementoController->saveMemento ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::remove()
{
    QModelIndexList  selectedRows = _view.selectionModel ()->selectedRows ();
    QModelIndex      indexToRemove;
    if (!selectedRows.isEmpty ())
    {
        indexToRemove = selectedRows.front ();
    }
    _editSerie->remove (indexToRemove);
    _mementoController->saveMemento ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::update ()
{
    _scheduler->update ();
    _mementoController->saveMemento ();
}
