#ifndef BUILDER_H
#define BUILDER_H

class EditSerie;
class IMessageBox;
class LoggerWidget;
class MementoController;
class NetworkAccess;
class Scheduler;
class SeriesModel;
class TorrentFinderController;

class QTableView;

class Builder
{
public:
    //----------------------------------------------------------------------------------------------
    explicit Builder();

    //----------------------------------------------------------------------------------------------
    Scheduler * const getScheduler() const;

    //----------------------------------------------------------------------------------------------
    MementoController * const getMementoController() const;

    //----------------------------------------------------------------------------------------------
    EditSerie * const getEditSerie() const;

    //----------------------------------------------------------------------------------------------
    LoggerWidget * const getLogger() const;

    //----------------------------------------------------------------------------------------------
    QTableView * const getView() const;

private:

    void buildEditSerie();
    void buildLogger();
    void buildMementoController();
    void buildMessageBox();
    void buildModel();
    void buildNetwork();
    void buildScheduler();
    void buildView();

    QTableView              * _view;
    EditSerie               * _editSerie;
    IMessageBox             * _messageBox;
    LoggerWidget            * _logger;
    MementoController       * _mementoController;
    NetworkAccess           * _networkAccess;
    SeriesModel             * _model;
    Scheduler               * _scheduler;
    TorrentFinderController * _torrentFinderController;
};

#endif // BUILDER_H
