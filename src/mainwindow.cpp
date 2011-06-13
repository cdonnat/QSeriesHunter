#include "mainwindow.h"

#include "serieswidget.h"

MainWindow::MainWindow():QMainWindow()
{
    _seriesWidget = new SeriesWidget(this);

    this->setCentralWidget (_seriesWidget);
    this->setWindowTitle ("QSeriesHunter");
}
