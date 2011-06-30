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
    QUrl    url("file://" + absoluteFileName);
    QDesktopServices::openUrl (url);
}
