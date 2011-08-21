#include "editseriedialog.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>

//----------------------------------------------------------------------------------------------
EditSerieDialog::EditSerieDialog()
{
    createForm();
    createLayout();
    createConnection();
}

//----------------------------------------------------------------------------------------------
void EditSerieDialog::createForm()
{
    _dialog    = new QDialog();
    _nameLabel = new QLabel(QObject::tr("Name:"), _dialog);
    _nameEdit  = new QLineEdit(_dialog);
    
    _seasonLabel = new QLabel(QObject::tr("Season:"), _dialog);
    _seasonEdit  = new QSpinBox(_dialog);
    _seasonEdit->setRange(1, 100);
    
    _lastEpisodeDownloadedLabel = new QLabel(QObject::tr("Last Episode Downloaded:"), _dialog);
    _lastEpisodeDownloadedEdit  = new QSpinBox(_dialog);
    _lastEpisodeDownloadedEdit->setRange(0, 100);
    _lastEpisodeDownloadedEdit->setSpecialValueText(QObject::tr("None"));
    
    _okButton = new QPushButton(QObject::tr("Ok"), _dialog);
    _cancelButton = new QPushButton(QObject::tr("Cancel"), _dialog);
}

//----------------------------------------------------------------------------------------------
void EditSerieDialog::createConnection()
{
    QObject::connect(_okButton, SIGNAL(clicked()),
                     _dialog, SLOT(accept()));
    
    QObject::connect(_cancelButton, SIGNAL(clicked()),
                     _dialog, SLOT(reject()));
}

//----------------------------------------------------------------------------------------------
void EditSerieDialog::createLayout()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(_okButton);
    buttonLayout->addWidget(_cancelButton);
    
    QGridLayout * gLayout = new QGridLayout();
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(_nameLabel, 0, 0, Qt::AlignRight);
    gLayout->addWidget(_nameEdit, 0, 1);
    gLayout->addWidget(_seasonLabel, 1, 0, Qt::AlignRight);
    gLayout->addWidget(_seasonEdit, 1, 1);
    gLayout->addWidget(_lastEpisodeDownloadedLabel, 2, 0, Qt::AlignRight);
    gLayout->addWidget(_lastEpisodeDownloadedEdit, 2, 1);
    gLayout->addLayout(buttonLayout, 3, 1, Qt::AlignRight);
    
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    _dialog->setLayout(mainLayout);
}

//----------------------------------------------------------------------------------------------
bool EditSerieDialog::exec (const QString & title        ,
							const QString & name         ,
                            uint            season       ,
                            uint            lastEpisodeDl)
{
	_dialog->setWindowTitle(title);
    _nameEdit->setText (name);
    _seasonEdit->setValue (season);
    _lastEpisodeDownloadedEdit->setValue (lastEpisodeDl);
    _nameEdit->setFocus ();
    return _dialog->exec ();
}

//----------------------------------------------------------------------------------------------
QString EditSerieDialog::name() const
{
    return _nameEdit->text ();
}

//----------------------------------------------------------------------------------------------
uint EditSerieDialog::season () const
{
    return _seasonEdit->value ();
}

//----------------------------------------------------------------------------------------------
uint EditSerieDialog::lastEpisodeDl () const
{
    return _lastEpisodeDownloadedEdit->value();
}
