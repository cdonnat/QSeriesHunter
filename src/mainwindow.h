#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SeriesWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

private:
    SeriesWidget  * _seriesWidget;
};

#endif // MAINWINDOW_H
