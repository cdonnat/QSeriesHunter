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
SeriesWidget::SeriesWidget(ILogger * logger, QWidget *parent) :
    QWidget(parent)
{
    createAttributes(logger);
    createLayouts ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::createAttributes (ILogger * logger)
{
    Builder   builder(logger);
    _view              = builder.getView();
    _scheduler         = builder.getScheduler ();
    _mementoController = builder.getMementoController ();
    _editSerie         = builder.getEditSerie ();
}

//----------------------------------------------------------------------------------------------
void SeriesWidget::createLayouts ()
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
    _scheduler->update ();
    _mementoController->saveMemento ();
}
