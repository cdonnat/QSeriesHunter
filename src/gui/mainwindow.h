#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

class QAction;
class QCloseEvent;
class QDockWidget;
class QToolBar;
class LoggerWidget;
class SeriesWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //----------------------------------------------------------------------------------------------
    explicit MainWindow();

    //----------------------------------------------------------------------------------------------
    virtual ~MainWindow() {}

    //----------------------------------------------------------------------------------------------
    virtual void closeEvent(QCloseEvent *event);

private slots:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Display the about dialog box.]
    void about();

    
private:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Create widget series and log.]
    void createWidgets();
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Create the toolbar.]
    void createToolbar();
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Create menus.]
    void createMenus ();
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Load last position and geometry of the main window.]
    void loadSettings();

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Save last position and geometry of the main window.]
    void saveSettings();

private:
    QDockWidget   * _dockLog;
    QToolBar      * _toolBar;
    SeriesWidget  * _seriesWidget;
    LoggerWidget  * _loggerWidget;

    QAction       * _add;
    QAction       * _remove;
    QAction       * _update;
    QAction       * _edit;
    QAction       * _about;
    QAction       * _aboutQt;

    QSettings       _settings;
};

#endif // MAINWINDOW_H
