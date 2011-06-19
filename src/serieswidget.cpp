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

#include <QItemSelectionModel>
#include <QTextEdit>
#include <QHeaderView>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

//----------------------------------------------------------------------------------------------
SeriesWidget::SeriesWidget(QWidget *parent) :
    QWidget(parent)
{
    buildAttributes();
    buildAndConfigureLayouts ();
    configureView ();
    doConnections ();
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

    _scheduler = new Scheduler(_model, findersController,
                               new Downloader(networkAccess, new SerieDownloader()),
                               _logger);

    _addButton    = new QPushButton(tr("Add"), this);
    _editButton   = new QPushButton(tr("Edit"), this);
    _removeButton = new QPushButton(tr("Remove"), this);
    _updateButton = new QPushButton(tr("Update"), this);
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::buildAndConfigureLayouts ()
{
    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget (_addButton);
    buttonLayout->addWidget (_editButton);
    buttonLayout->addWidget (_removeButton);
    buttonLayout->addWidget (_updateButton);

    QGridLayout * mainLayout = new QGridLayout;
    mainLayout->addLayout (buttonLayout, 0, 0);
    mainLayout->addWidget (&_view, 1, 0);
    mainLayout->addWidget (_logger->getTextEdit (), 2, 0);
    setLayout (mainLayout);
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
void SeriesWidget::doConnections ()
{
    connect (_addButton, SIGNAL(clicked()), this, SLOT(add()));
    connect (_removeButton, SIGNAL(clicked()), this, SLOT(remove()));
    connect (_updateButton, SIGNAL(clicked()), this, SLOT(update()));
    connect (_editButton, SIGNAL(clicked()), this, SLOT(edit()));
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::add()
{
    _editSerie->add ();
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
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::update ()
{
    _addButton->setEnabled (false);
    _scheduler->update ();
    _addButton->setEnabled (true);
}
