#include "adddialog.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent)
{
    _nameLabel = new QLabel(tr("Name"));
    _nameEdit  = new QLineEdit();

    _seasonLabel = new QLabel(tr("Season"));
    _seasonEdit  = new QLineEdit();

    _lastEpisodeDownloadedLabel = new QLabel(tr("Last Episoded Downloaded"));
    _lastEpisodeDownloadedEdit  = new QLineEdit();

    _okButton = new QPushButton(tr("Ok"));
    _cancelButton = new QPushButton(tr("Cancel"));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(_okButton);
    buttonLayout->addWidget(_cancelButton);

    QGridLayout * gLayout = new QGridLayout;
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
    setLayout(mainLayout);

    connect(_okButton, SIGNAL(clicked()),
            this, SLOT(accept()));

    connect(_cancelButton, SIGNAL(clicked()),
            this, SLOT(reject()));

    setWindowTitle(tr("Add a Serie"));
}

//----------------------------------------------------------------------------------------------
QString AddDialog::name() const
{
    return _nameEdit->text ();
}

//----------------------------------------------------------------------------------------------
uint AddDialog::season () const
{
    return _seasonEdit->text ().toUInt ();
}

//----------------------------------------------------------------------------------------------
uint AddDialog::lastEpisodeDl () const
{
    return _lastEpisodeDownloadedEdit->text ().toUInt ();
}
