#ifndef SERIESWIDGET_H
#define SERIESWIDGET_H

#include <QWidget>

class EditSerie;
class ILogger;
class MementoController;
class Scheduler;

class QTableView;
class QModelIndex;
class QString;

class SeriesWidget : public QObject
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    explicit SeriesWidget(ILogger           * logger, 
                          QTableView        * view,
                          EditSerie         * editSerie,
                          Scheduler         * scheduler,
                          MementoController * mementoController);

    QWidget * const getWidget() const;
    
signals:
    
    //----------------------------------------------------------------------------------------------
    void updateBegin();

    //----------------------------------------------------------------------------------------------
    void updateEnd();

    
public slots:

    //----------------------------------------------------------------------------------------------
    void add();

    //----------------------------------------------------------------------------------------------
    void remove();

    //----------------------------------------------------------------------------------------------
    void edit();

    //----------------------------------------------------------------------------------------------
    void update();

private slots:

    //----------------------------------------------------------------------------------------------
    void editSerieAt (const QModelIndex & index);
    
private:

    //----------------------------------------------------------------------------------------------
    QModelIndex getModelIndexSelected() const;

private:
    QTableView        * _view;
    EditSerie         * _editSerie;
    Scheduler         * _scheduler;
    MementoController * _mementoController;
};

#endif // SERIESWIDGET_H
