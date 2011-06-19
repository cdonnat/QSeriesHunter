#ifndef EDITSERIEDIALOG_H
#define EDITSERIEDIALOG_H

#include "ieditseriedialog.h"

class QDialog;
class QLabel;
class QLineEdit;
class QPushButton;

class EditSerieDialog : public IEditSerieDialog
{
public:
    //----------------------------------------------------------------------------------------------
    explicit EditSerieDialog();

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual bool exec(const QString & name          = "",
                      const QString & season        = "",
                      const QString & lastEpisodeDl = "");

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual QString name() const;

    //----------------------------------------------------------------------------------------------
    virtual QString season () const;

    //----------------------------------------------------------------------------------------------
    virtual QString lastEpisodeDl () const;

private:
    QDialog     * _dialog;
    QLabel      * _nameLabel;    
    QLabel      * _seasonLabel;
    QLabel      * _lastEpisodeDownloadedLabel;

    QPushButton * _okButton;
    QPushButton * _cancelButton;   

    QLineEdit   * _seasonEdit;
    QLineEdit   * _nameEdit;
    QLineEdit   * _lastEpisodeDownloadedEdit;
};

#endif // EDITSERIEDIALOG_H
