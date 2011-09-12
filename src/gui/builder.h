#ifndef BUILDER_H
#define BUILDER_H

class EditSerie;
class IMessageBox;
class ILogger;
class MementoController;
class NetworkAccess;
class Scheduler;
class SeriesModel;
class FinderController;

class QString;
class QTableView;

class Builder
{
public:
    //----------------------------------------------------------------------------------------------
    explicit Builder(ILogger * logger, const QString & initFile);

    //----------------------------------------------------------------------------------------------
    Scheduler * const getScheduler() const;

    //----------------------------------------------------------------------------------------------
    MementoController * const getMementoController() const;

    //----------------------------------------------------------------------------------------------
    EditSerie * const getEditSerie() const;

    //----------------------------------------------------------------------------------------------
    QTableView * const getView() const;

private:

    void buildEditSerie();
    void buildMementoController(const QString & initFile);
    void buildMessageBox();
    void buildModel();
    void buildNetwork();
    void buildScheduler();
    void buildView();

    ILogger                 * _logger;
    QTableView              * _view;
    EditSerie               * _editSerie;
    IMessageBox             * _messageBox;
    MementoController       * _mementoController;
    NetworkAccess           * _networkAccess;
    SeriesModel             * _model;
    Scheduler               * _scheduler;
    FinderController        * _finderController;
};

#endif // BUILDER_H
