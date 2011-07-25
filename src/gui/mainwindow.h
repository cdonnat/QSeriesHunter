#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

class QAction;
class QCloseEvent;
class QDockWidget;
class QProgressBar;
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

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Progress bar is visible and actions are disabled.]
    void updateBegin();
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Progress bar is hidden and actions are enabled.]
    void updateEnd();
    
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
    // ENS [Create the status bar.]
    void createStatusBar();
    
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

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Enables or disables actions.]    
    void setActionsEnabled (bool areEnabled);
    
private:
    QDockWidget   * _dockLog;
    QProgressBar  * _progressBar;
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
