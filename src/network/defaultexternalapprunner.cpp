#include "defaultexternalapprunner.h"

#include <QUrl>
#include <QString>
#include <QDesktopServices>
#include <QMessageBox>

//----------------------------------------------------------------------------------------------
DefaultExternalAppRunner::DefaultExternalAppRunner()
{
}

//----------------------------------------------------------------------------------------------
void DefaultExternalAppRunner::open (const QString &absoluteFileName)
{
    QUrl    url(absoluteFileName);
	//QMessageBox::warning (NULL, "", "file://" + absoluteFileName);
    QDesktopServices::openUrl (url);
}
