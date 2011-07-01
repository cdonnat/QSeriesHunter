#ifndef SERIESWIDGET_H
#define SERIESWIDGET_H

#include <QWidget>

class EditSerie;
class LoggerWidget;
class MementoController;
class Scheduler;

class QTableView;
class QModelIndex;

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
    void createAttributes();

    //----------------------------------------------------------------------------------------------
    void createLayouts();

    //----------------------------------------------------------------------------------------------
    QModelIndex getModelIndexSelected() const;

private:
    QTableView        * _view;
    LoggerWidget      * _logger;
    EditSerie         * _editSerie;
    Scheduler         * _scheduler;
    MementoController * _mementoController;
};

#endif // SERIESWIDGET_H
