#include "mainwindow.h"

#include "serieswidget.h"

#include <QAction>
#include <QCloseEvent>
#include <QToolBar>

MainWindow::MainWindow():QMainWindow(),_settings("DocDoc", "QSeriesHunter")
{
    _seriesWidget = new SeriesWidget(this);

    _toolBar = new QToolBar(this);
    _add     = new QAction(QIcon(":images/add"), tr("Add"), _toolBar);
    _remove  = new QAction(QIcon(":images/remove.png"), tr("Remove"), _toolBar);
    _edit    = new QAction(QIcon(":images/edit.png"), tr("Edit"), _toolBar);
    _update  = new QAction(QIcon(":images/update.png"), tr("Update"), _toolBar);

    _toolBar->addAction (_add);
    _toolBar->addAction (_remove);
    _toolBar->addAction (_edit);
    _toolBar->addAction (_update);

    connect(_add, SIGNAL(triggered()), _seriesWidget, SLOT(add()));
    connect(_update, SIGNAL(triggered()), _seriesWidget, SLOT(update()));
    connect(_edit, SIGNAL(triggered()), _seriesWidget, SLOT(edit()));
    connect(_remove, SIGNAL(triggered()), _seriesWidget, SLOT(remove()));

    this->addToolBar (_toolBar);
    this->setCentralWidget (_seriesWidget);
    this->setWindowTitle ("QSeriesHunter");

    loadSettings();
}

void MainWindow::loadSettings()
{
    move (_settings.value ("position").toPoint ());
    resize (_settings.value ("size").toRect ());
}

void MainWindow::saveSettings()
{
    _settings.setValue ("position", pos ());
    _settings.setValue ("size", size ());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    saveSettings();
    event->accept ();
}
