#ifndef BUILDER_H
#define BUILDER_H

class EditSerie;
class IMessageBox;
class LoggerWidget;
class MementoController;
class NetworkAccess;
class Scheduler;
class SeriesModel;
class FinderController;
class FinderSelection;
class FinderSelectionWidget;
class SeriesWidget;

class QString;
class QTableView;
class QWidget;

class Builder
{
public:
    //----------------------------------------------------------------------------------------------
    explicit Builder(const QString & initFile);

    //----------------------------------------------------------------------------------------------
    Scheduler * const getScheduler() const;

    //----------------------------------------------------------------------------------------------
    MementoController * const getMementoController() const;

    //----------------------------------------------------------------------------------------------
    EditSerie * const getEditSerie() const;

    //----------------------------------------------------------------------------------------------
    QTableView * const getView() const;
    
    //----------------------------------------------------------------------------------------------
    QWidget    * const getFinderSelection() const;

    //----------------------------------------------------------------------------------------------
    LoggerWidget * const getLoggerWidget() const;
    
    //----------------------------------------------------------------------------------------------
    SeriesWidget * const getSeriesWidget() const;
    
private:

    void buildEditSerie();
    void buildMementoController(const QString & initFile);
    void buildMessageBox();
    void buildModel();
    void buildNetwork();
    void buildScheduler();
    void buildView();

    QTableView              * _view;
    EditSerie               * _editSerie;
    IMessageBox             * _messageBox;
    MementoController       * _mementoController;
    NetworkAccess           * _networkAccess;
    SeriesModel             * _model;
    Scheduler               * _scheduler;
    FinderController        * _finderController;
    FinderSelectionWidget   * _finderSelectionWidget;
    FinderSelection         * _finderSelection;
    SeriesWidget            * _seriesWidget;
    LoggerWidget            * _loggerWidget;
};

#endif // BUILDER_H
