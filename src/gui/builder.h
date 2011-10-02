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
class EditFinder;
class EditFinderWidget;
class SeriesWidget;
class FindersWidget;

class QString;
class QTableView;
class QWidget;

class Builder
{
public:
    //----------------------------------------------------------------------------------------------
    explicit Builder(const QString & initFile);

    //----------------------------------------------------------------------------------------------
    QWidget      * const getFindersWidget() const;

    //----------------------------------------------------------------------------------------------
    LoggerWidget * const getLoggerWidget() const;
    
    //----------------------------------------------------------------------------------------------
    SeriesWidget * const getSeriesWidget() const;
    
private:

    void buildEditSerie();
    void buildMementoController(const QString & initFile);
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
    EditFinderWidget        * _editFinderWidget;
    EditFinder              * _editFinder;
    SeriesWidget            * _seriesWidget;
    LoggerWidget            * _loggerWidget;
    FindersWidget           * _findersWidget;
};

#endif // BUILDER_H
