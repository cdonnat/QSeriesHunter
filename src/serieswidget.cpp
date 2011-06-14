#include "serie.h"
#include "serieswidget.h"
#include "seriesmodel.h"
#include "adddialog.h"
#include "loggerwidget.h"
#include "scheduler.h"
#include "torrentfindercontroller.h"
#include "isohunt.h"
#include "downloader.h"
#include "networkaccess.h"
#include "seriedownloader.h"

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
    _logger = new LoggerWidget();
    _model  = new SeriesModel(this);

    NetworkAccess            * networkAccess     = new NetworkAccess();
    TorrentFinderController  * findersController = new TorrentFinderController();
    findersController->addTorrentFinder (new Isohunt(networkAccess));

    _scheduler = new Scheduler(_model, findersController,
                               new Downloader(networkAccess, new SerieDownloader()),
                               _logger);

    _addButton    = new QPushButton(tr("Add"), this);
    _updateButton = new QPushButton(tr("Update"), this);
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::buildAndConfigureLayouts ()
{
    QVBoxLayout * buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget (_addButton);
    buttonLayout->addWidget (_updateButton);

    QHBoxLayout * centralLayout = new QHBoxLayout;
    centralLayout->addWidget (&_view);
    centralLayout->addLayout (buttonLayout);

    QVBoxLayout * mainLayout = new QVBoxLayout;
    mainLayout->addLayout (centralLayout);
    mainLayout->addWidget (_logger->getTextEdit ());

    setLayout (mainLayout);
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::configureView ()
{
    _view.setModel (_model);
    _view.verticalHeader ()->hide ();
    _view.horizontalHeader()->setStretchLastSection(true);
    _view.horizontalHeader ()->setResizeMode (QHeaderView::ResizeToContents);
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::doConnections ()
{
    connect (_addButton, SIGNAL(clicked()), this, SLOT(add()));
    connect (_updateButton, SIGNAL(clicked()), this, SLOT(update()));
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::add()
{
    AddDialog  dialog;

    if (dialog.exec ())
    {
        Serie  serie(dialog.name (),
                     dialog.season (),
                     dialog.lastEpisodeDl());
        if (!_model->contains (serie))
        {
            _model->addSerie (serie);
        }
        else
        {
            QMessageBox::warning (this,
                                  tr("Warning"),
                                  tr("You are already following this serie!"));
        }
    }
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::update ()
{
    _scheduler->update ();
}
