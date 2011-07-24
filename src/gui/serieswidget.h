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

class SeriesWidget : public QWidget
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    explicit SeriesWidget(ILogger * logger, const QString & initFile, QWidget *parent = 0);

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

private:

    //----------------------------------------------------------------------------------------------
    void createAttributes(ILogger * logger, const QString & initFile);

    //----------------------------------------------------------------------------------------------
    void createLayouts();

    //----------------------------------------------------------------------------------------------
    QModelIndex getModelIndexSelected() const;

private:
    QTableView        * _view;
    EditSerie         * _editSerie;
    Scheduler         * _scheduler;
    MementoController * _mementoController;
};

#endif // SERIESWIDGET_H
