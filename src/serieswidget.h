#ifndef SERIESWIDGET_H
#define SERIESWIDGET_H

#include <QWidget>
#include <QTableView>

class EditSerie;
class IMessageBox;
class Scheduler;
class LoggerWidget;
class SeriesModel;
class QPushButton;

class SeriesWidget : public QWidget
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    explicit SeriesWidget(QWidget *parent = 0);

private slots:

    //----------------------------------------------------------------------------------------------
    void add();

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
    void doConnections();

private:
    QTableView     _view;
    IMessageBox  * _messageBox;
    LoggerWidget * _logger;
    EditSerie    * _editSerie;
    SeriesModel  * _model;
    Scheduler    * _scheduler;

    QPushButton  * _addButton;
    QPushButton  * _updateButton;
};

#endif // SERIESWIDGET_H
