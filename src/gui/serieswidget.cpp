#include "serieswidget.h"

#include "builder.h"
#include "editserie.h"
#include "loggerwidget.h"
#include "mementocontroller.h"
#include "scheduler.h"

#include <QTableView>
#include <QTextEdit>
#include <QSplitter>
#include <QVBoxLayout>

//----------------------------------------------------------------------------------------------
SeriesWidget::SeriesWidget(ILogger           * logger, 
                           QTableView        * view,
                           EditSerie         * editSerie,
                           Scheduler         * scheduler,
                           MementoController * mementoController) :
_view(view), _editSerie(editSerie), _scheduler(scheduler),  _mementoController(mementoController)
{
    connect(_view, SIGNAL(doubleClicked(const QModelIndex & )),
            this , SLOT(editSerieAt(const QModelIndex &)));
}

//----------------------------------------------------------------------------------------------
QModelIndex SeriesWidget::getModelIndexSelected() const
{
    QModelIndexList  selectedRows = _view->selectionModel ()->selectedRows ();
    QModelIndex      index;
    if (!selectedRows.isEmpty ())
    {
        index = selectedRows.front ();
    }
    return index;
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::saveMemento()
{
    _mementoController->saveMemento ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::add()
{
    _editSerie->add ();
    saveMemento();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::editSerieAt (const QModelIndex & index)
{
    _editSerie->edit(index);
    saveMemento();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::edit()
{
    _editSerie->edit(getModelIndexSelected());
    saveMemento();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::remove()
{
    _editSerie->remove (getModelIndexSelected ());
    saveMemento();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::update ()
{
    emit updateBegin();
    _scheduler->update ();
    saveMemento();
    emit updateEnd();
}

//----------------------------------------------------------------------------------------------
QWidget * const SeriesWidget::getWidget() const
{
    return _view;
}
