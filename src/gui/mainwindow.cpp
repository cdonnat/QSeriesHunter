#include "mainwindow.h"

#include "config.h"
#include "loggerwidget.h"
#include "serieswidget.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDockWidget>
#include <QAction>
#include <QCloseEvent>
#include <QMenuBar>
#include <QMessageBox>
#include <QPointF>
#include <QToolBar>

//----------------------------------------------------------------------------------------------
MainWindow::MainWindow():QMainWindow(),_settings("DocDoc", "QSeriesHunter")
{
    createWidgets();
    createToolbar();
    createMenus();
    loadSettings();
}

//----------------------------------------------------------------------------------------------
void MainWindow::createWidgets()
{
    _loggerWidget = new LoggerWidget();
    _dockLog = new QDockWidget(tr("Console Log"), this);
    _dockLog->setWidget(_loggerWidget->getLogConsole());
    _dockLog->setVisible(false);
    this->addDockWidget(Qt::BottomDockWidgetArea, _dockLog);

    _seriesWidget = new SeriesWidget(_loggerWidget, this);
    this->setCentralWidget (_seriesWidget);
    this->setWindowTitle ("QSeriesHunter");
}

//----------------------------------------------------------------------------------------------
void MainWindow::createToolbar()
{
    _toolBar = new QToolBar(this);
    _add     = new QAction(QIcon(":images/add")       , tr("Add")   , _toolBar);
    _remove  = new QAction(QIcon(":images/remove.png"), tr("Remove"), _toolBar);
    _edit    = new QAction(QIcon(":images/edit.png")  , tr("Edit")  , _toolBar);
    _update  = new QAction(QIcon(":images/update.png"), tr("Update"), _toolBar);
    
    _toolBar->addAction (_add);
    _toolBar->addAction (_remove);
    _toolBar->addAction (_edit);
    _toolBar->addAction (_update);
    
    connect(_add   , SIGNAL(triggered()), _seriesWidget, SLOT(add()));
    connect(_update, SIGNAL(triggered()), _seriesWidget, SLOT(update()));
    connect(_edit  , SIGNAL(triggered()), _seriesWidget, SLOT(edit()));
    connect(_remove, SIGNAL(triggered()), _seriesWidget, SLOT(remove()));
    
    this->addToolBar (_toolBar);
}

//----------------------------------------------------------------------------------------------
void MainWindow::about()
{
	const int major = QSERIESHUNTER_MAJOR;
	const int minor = QSERIESHUNTER_MINOR;
	const int patch = QSERIESHUNTER_PATCH;
	
    QMessageBox::about(this, 
                       tr("About QSeriesHunter"),
                       tr("QSeriesHunter Version %1.%2.%3").arg(major).arg(minor).arg(patch));
}

//----------------------------------------------------------------------------------------------
void MainWindow::createMenus()
{
    _about = new QAction(tr("&About"), this);
    _about->setStatusTip(tr("Show the application's About box"));
    connect(_about, SIGNAL(triggered()), this, SLOT(about()));
    
    _aboutQt = new QAction(tr("About &Qt"), this);
    _aboutQt->setStatusTip(tr("Show the Qt library's About box"));
    connect(_aboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    
    QMenu * viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(_dockLog->toggleViewAction());
    
    QMenu * helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(_about);
    helpMenu->addAction(_aboutQt);
}

//----------------------------------------------------------------------------------------------
void MainWindow::loadSettings()
{
	this->adjustSize();
	QPointF widgetPosition = 
		QApplication::desktop()->screen()->rect().center() - this->rect().center();	
	if (_settings.contains("position")) {
		widgetPosition = _settings.value ("position").toPoint ();
		setGeometry (_settings.value ("size").toRect ());		
	}
	move (widgetPosition.x(), widgetPosition.y());	
    _dockLog->setVisible(_settings.value("consoleIsVisible").toBool());
}

//----------------------------------------------------------------------------------------------
void MainWindow::saveSettings()
{
    _settings.setValue ("position", pos ());
    _settings.setValue ("size", geometry ());
    _settings.setValue("consoleIsVisible", _dockLog->isVisible());
}

//----------------------------------------------------------------------------------------------
void MainWindow::closeEvent(QCloseEvent *event)
{
    saveSettings();
    event->accept ();
}
