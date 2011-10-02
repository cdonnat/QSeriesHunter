#include "mainwindow.h"

#include "config.h"
#include "loggerwidget.h"
#include "serieswidget.h"
#include "builder.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDockWidget>
#include <QAction>
#include <QCloseEvent>
#include <QDir>
#include <QMenuBar>
#include <QMessageBox>
#include <QPointF>
#include <QProgressBar>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>
#include "finderselectionwidget.h"

const QString initFile = QDir::homePath() + QDir::separator() + ".QSeriesHunter.ini";

//----------------------------------------------------------------------------------------------
MainWindow::MainWindow():QMainWindow(),_settings("DocDoc", "QSeriesHunter")
{
    createWidgets();
    createStatusBar();
    createToolbar();
    createMenus();
    loadSettings();
}

//----------------------------------------------------------------------------------------------
void MainWindow::createWidgets()
{
    Builder   builder(initFile);
    
    _loggerWidget = builder.getLoggerWidget();
    _seriesWidget = builder.getSeriesWidget();

    _dockLog      = new QDockWidget(tr("Console Log"), this);
    _dockLog->setWidget(_loggerWidget);
    _dockLog->setVisible(false);
    this->addDockWidget(Qt::BottomDockWidgetArea, _dockLog);

    QWidget     * centralWidget = new QWidget;
    QVBoxLayout * centralLayout = new QVBoxLayout;
    
    centralLayout->addWidget(builder.getFinderSelection());
    centralLayout->addWidget(_seriesWidget);
    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralWidget->setLayout(centralLayout);
    
    this->setCentralWidget (centralWidget);
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
void MainWindow::setActionsEnabled (bool areEnabled)
{
    this->_add->setEnabled(areEnabled);
    this->_update->setEnabled(areEnabled);
    this->_edit->setEnabled(areEnabled);
    this->_remove->setEnabled(areEnabled);
}


//----------------------------------------------------------------------------------------------
void MainWindow::updateBegin()
{
    _progressBar->setVisible(true);
    setActionsEnabled(false);
}

//----------------------------------------------------------------------------------------------
void MainWindow::updateEnd()
{
    _progressBar->setVisible(false);
    setActionsEnabled(true);
}


//----------------------------------------------------------------------------------------------
void MainWindow::about()
{
	const int     major        = QSERIESHUNTER_MAJOR;
	const int     minor        = QSERIESHUNTER_MINOR;
	const int     patch        = QSERIESHUNTER_PATCH;
    
    QMessageBox::about(this, 
                       tr("About QSeriesHunter"),
                       tr("QSeriesHunter Version %1.%2.%3 by Charles")
                       .arg(major)
                       .arg(minor)
                       .arg(patch));
}

//----------------------------------------------------------------------------------------------
void MainWindow::createStatusBar()
{
    QStatusBar * statusBar = this->statusBar();
    
    _progressBar = new QProgressBar(this);
    _progressBar->setMinimum(0);
    _progressBar->setMaximum(0);
    _progressBar->setVisible(false);
    statusBar->addPermanentWidget(_progressBar);
    statusBar->showMessage(tr("Ready"), 2000);  
    
    connect (_seriesWidget, SIGNAL(updateBegin()), this, SLOT(updateBegin()));
    connect (_seriesWidget, SIGNAL(updateEnd()), this, SLOT(updateEnd()));
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
    _dockLog->toggleViewAction()->setIcon(QIcon(":images/log.png"));
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
        _dockLog->setVisible(_settings.value("consoleIsVisible").toBool());
	}
	move (widgetPosition.x(), widgetPosition.y());	
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
