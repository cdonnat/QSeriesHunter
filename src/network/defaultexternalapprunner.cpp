#include "defaultexternalapprunner.h"

#include <QUrl>
#include <QString>
#include <QDesktopServices>

//----------------------------------------------------------------------------------------------
DefaultExternalAppRunner::DefaultExternalAppRunner()
{
}

//----------------------------------------------------------------------------------------------
void DefaultExternalAppRunner::open (const QString &absoluteFileName)
{
    QDesktopServices::openUrl (QUrl::fromLocalFile(absoluteFileName));
}
