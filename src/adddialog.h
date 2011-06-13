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
    explicit AddDialog(QWidget *parent = 0);

    QString  name() const;
    uint     season () const;
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
