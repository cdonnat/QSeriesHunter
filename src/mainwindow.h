#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QToolBar;
class SeriesWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

private:
    QToolBar      * _toolBar;
    SeriesWidget  * _seriesWidget;

    QAction       * _add;
    QAction       * _remove;
    QAction       * _update;
    QAction       * _edit;
};

#endif // MAINWINDOW_H
