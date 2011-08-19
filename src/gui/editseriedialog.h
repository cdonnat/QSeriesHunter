#ifndef EDITSERIEDIALOG_H
#define EDITSERIEDIALOG_H

#include "ieditseriedialog.h"

class QDialog;
class QLabel;
class QLineEdit;
class QPushButton;
class QSpinBox;

class EditSerieDialog : public IEditSerieDialog
{
public:
    //----------------------------------------------------------------------------------------------
    explicit EditSerieDialog();

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual bool exec(const QString & title             ,
					  const QString & name          = "",
                      uint            season        = 0 ,
                      uint            lastEpisodeDl = 0);

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual QString name() const;

    //----------------------------------------------------------------------------------------------
    virtual uint season () const;

    //----------------------------------------------------------------------------------------------
    virtual uint lastEpisodeDl () const;

private:
    
    void createForm();
    void createConnection();
    void createLayout();
    
    
    QDialog     * _dialog;
    QLabel      * _nameLabel;    
    QLabel      * _seasonLabel;
    QLabel      * _lastEpisodeDownloadedLabel;

    QPushButton * _okButton;
    QPushButton * _cancelButton;   

    QLineEdit   * _nameEdit;
    QSpinBox    * _seasonEdit;
    QSpinBox    * _lastEpisodeDownloadedEdit;
};

#endif // EDITSERIEDIALOG_H
