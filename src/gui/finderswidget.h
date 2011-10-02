#ifndef FINDERSWIDGET_H
#define FINDERSWIDGET_H

#include <QWidget>

class EditFinder;
class EditFinderWidget;
class MementoController;

class FindersWidget : public QObject
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    explicit FindersWidget(EditFinder        * editFinder,
                           EditFinderWidget  * editFinderWidget,
                           MementoController * mementoController);

    QWidget * const getWidget() const;
    
private slots:

    //----------------------------------------------------------------------------------------------
    void enableTorrent (bool isEnable);

    //----------------------------------------------------------------------------------------------
    void enableDirectDownload (bool isEnable);

private:
    EditFinder        * _editFinder;
    EditFinderWidget  * _editFinderWidget;
    MementoController * _mementoController;
};

#endif // FINDERSWIDGET_H
