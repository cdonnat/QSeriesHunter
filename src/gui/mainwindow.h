#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

class QAction;
class QCloseEvent;
class QToolBar;
class SeriesWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    virtual ~MainWindow() {}

    virtual void closeEvent(QCloseEvent *event);

private:
    void loadSettings();
    void saveSettings();

private:
    QToolBar      * _toolBar;
    SeriesWidget  * _seriesWidget;

    QAction       * _add;
    QAction       * _remove;
    QAction       * _update;
    QAction       * _edit;

    QSettings       _settings;
};

#endif // MAINWINDOW_H
