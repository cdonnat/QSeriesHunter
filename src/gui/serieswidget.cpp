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
    QWidget(), _view(view), _editSerie(editSerie), _scheduler(scheduler),  _mementoController(mementoController)
{
    QVBoxLayout  * layout = new QVBoxLayout(this);
    layout->addWidget(_view);
    setLayout (layout);
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
void SeriesWidget::add()
{
    _editSerie->add ();
    _mementoController->saveMemento ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::edit()
{
    _editSerie->edit(getModelIndexSelected());
    _mementoController->saveMemento ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::remove()
{
    _editSerie->remove (getModelIndexSelected ());
    _mementoController->saveMemento ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::update ()
{
    emit updateBegin();
    _scheduler->update ();
    _mementoController->saveMemento ();
    emit updateEnd();
}
