#include "editseriedialog.h"

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

EditSerieDialog::EditSerieDialog()
{
    _dialog    = new QDialog();
    _nameLabel = new QLabel(QObject::tr("Name"), _dialog);
    _nameEdit  = new QLineEdit(_dialog);

    _seasonLabel = new QLabel(QObject::tr("Season"), _dialog);
    _seasonEdit  = new QLineEdit(_dialog);

    _lastEpisodeDownloadedLabel = new QLabel(QObject::tr("Last Episoded Downloaded"), _dialog);
    _lastEpisodeDownloadedEdit  = new QLineEdit(_dialog);

    _okButton = new QPushButton(QObject::tr("Ok"), _dialog);
    _cancelButton = new QPushButton(QObject::tr("Cancel"), _dialog);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(_okButton);
    buttonLayout->addWidget(_cancelButton);

    QGridLayout * gLayout = new QGridLayout();
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(_nameLabel, 0, 0);
    gLayout->addWidget(_nameEdit, 0, 1);
    gLayout->addWidget(_seasonLabel, 1, 0);
    gLayout->addWidget(_seasonEdit, 1, 1);
    gLayout->addWidget(_lastEpisodeDownloadedLabel, 2, 0);
    gLayout->addWidget(_lastEpisodeDownloadedEdit, 2, 1);
    gLayout->addLayout(buttonLayout, 3, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    _dialog->setLayout(mainLayout);

    QObject::connect(_okButton, SIGNAL(clicked()),
                     _dialog, SLOT(accept()));

    QObject::connect(_cancelButton, SIGNAL(clicked()),
                     _dialog, SLOT(reject()));
}

//----------------------------------------------------------------------------------------------
bool EditSerieDialog::exec (const QString & title        ,
							const QString & name         ,
                            const QString & season       ,
                            const QString & lastEpisodeDl)
{
	_dialog->setWindowTitle(title);
    _nameEdit->setText (name);
    _seasonEdit->setText (season);
    _lastEpisodeDownloadedEdit->setText (lastEpisodeDl);
    _nameEdit->setFocus ();
    return _dialog->exec ();
}

//----------------------------------------------------------------------------------------------
QString EditSerieDialog::name() const
{
    return _nameEdit->text ();
}

//----------------------------------------------------------------------------------------------
QString EditSerieDialog::season () const
{
    return _seasonEdit->text ();
}

//----------------------------------------------------------------------------------------------
QString EditSerieDialog::lastEpisodeDl () const
{
    return _lastEpisodeDownloadedEdit->text ();
}
