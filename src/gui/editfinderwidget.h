#ifndef EDITFINDERWIDGET_H
#define EDITFINDERWIDGET_H

#include "ieditfinderwidget.h"

#include <QWidget>

class QCheckBox;

class EditFinderWidget : public QWidget, public IEditFinderWidget
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    EditFinderWidget();
    
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

#endif // EDITFINDERWIDGET_H
