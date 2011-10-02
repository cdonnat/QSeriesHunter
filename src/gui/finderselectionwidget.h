#ifndef FINDERSELECTIONWIDGET_H
#define FINDERSELECTIONWIDGET_H

#include "ifinderselectionwidget.h"

#include <QWidget>

class QCheckBox;

class FinderSelectionWidget : public QWidget, public IFinderSelectionWidget
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    FinderSelectionWidget();
    
    ~FinderSelectionWidget() {}
    
    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void enableTorrent(bool isEnable);
    
    //----------------------------------------------------------------------------------------------
    virtual void enableDirectDownload(bool isEnable);
    
signals:
    void torrentChecked (bool isChecked);
    void directDownloadChecked (bool isChecked);
    
private:
    QCheckBox  * _torrentCheckBox;
    QCheckBox  * _ddlCheckBox;    
};

#endif // FINDERSELECTIONWIDGET_H
