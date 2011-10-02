#include "finderselectionwidget.h"

#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>

//----------------------------------------------------------------------------------------------
FinderSelectionWidget::FinderSelectionWidget():QWidget()
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
void FinderSelectionWidget::enableTorrent(bool isEnable)
{
    _torrentCheckBox->setChecked(isEnable);
}

//----------------------------------------------------------------------------------------------
void FinderSelectionWidget::enableDirectDownload(bool isEnable)
{
    _ddlCheckBox->setChecked(isEnable);
}