#ifndef SERIESWIDGET_H
#define SERIESWIDGET_H

#include <QWidget>
#include <QTableView>

class EditSerie;
class IMessageBox;
class Scheduler;
class LoggerWidget;
class SeriesModel;
class MementoController;

class SeriesWidget : public QWidget
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    explicit SeriesWidget(QWidget *parent = 0);

public slots:

    //----------------------------------------------------------------------------------------------
    void add();

    //----------------------------------------------------------------------------------------------
    void remove();

    //----------------------------------------------------------------------------------------------
    void edit();

    //----------------------------------------------------------------------------------------------
    void update();


private:

    //----------------------------------------------------------------------------------------------
    void buildAttributes();

    //----------------------------------------------------------------------------------------------
    void buildAndConfigureLayouts();

    //----------------------------------------------------------------------------------------------
    void configureView();

    //----------------------------------------------------------------------------------------------
    QModelIndex getModelIndexSelected() const;

private:
    QTableView          _view;
    IMessageBox       * _messageBox;
    LoggerWidget      * _logger;
    EditSerie         * _editSerie;
    SeriesModel       * _model;
    Scheduler         * _scheduler;
    MementoController * _mementoController;
};

#endif // SERIESWIDGET_H
