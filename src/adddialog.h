#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;

class AddDialog : public QDialog
{
    Q_OBJECT
public:
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [.]
    explicit AddDialog(QWidget *parent = 0);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Name of the serie is returned.]
    QString  name()           const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Serie's season is returned.]
    uint     season ()        const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last episode downloaded is returned.]
    uint     lastEpisodeDl () const;

private:
    QLabel      * _nameLabel;    
    QLabel      * _seasonLabel;
    QLabel      * _lastEpisodeDownloadedLabel;

    QPushButton * _okButton;
    QPushButton * _cancelButton;   

    QLineEdit   * _seasonEdit;
    QLineEdit   * _nameEdit;
    QLineEdit   * _lastEpisodeDownloadedEdit;
};

#endif // ADDDIALOG_H
