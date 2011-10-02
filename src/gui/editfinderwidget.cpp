#include "editfinderwidget.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>

//----------------------------------------------------------------------------------------------
EditFinderWidget::EditFinderWidget():QWidget()
{
    QLabel * finderLabel = new QLabel(tr("Finder selection:"));
    _torrentCheckBox     = new QCheckBox(tr("Torrent"));
    _ddlCheckBox         = new QCheckBox(tr("Direct Download"));
    
    QHBoxLayout * layout = new QHBoxLayout(this);
    layout->addWidget(finderLabel);
    layout->addWidget(_torrentCheckBox);
    layout->addWidget(_ddlCheckBox);
    layout->addStretch();
    
    setLayout(layout);
        
    connect (_torrentCheckBox, SIGNAL(toggled(bool)), this, SIGNAL(torrentChecked(bool)));
    connect (_ddlCheckBox, SIGNAL(toggled(bool)), this, SIGNAL(directDownloadChecked(bool)));
}

//----------------------------------------------------------------------------------------------
void EditFinderWidget::enableTorrent(bool isEnable)
{
    _torrentCheckBox->setChecked(isEnable);
}

//----------------------------------------------------------------------------------------------
void EditFinderWidget::enableDirectDownload(bool isEnable)
{
    _ddlCheckBox->setChecked(isEnable);
}