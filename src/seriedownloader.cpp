#include "seriedownloader.h"

#include <QUrl>
#include <QString>
#include <QDesktopServices>

//----------------------------------------------------------------------------------------------
SerieDownloader::SerieDownloader()
{
}

//----------------------------------------------------------------------------------------------
void SerieDownloader::download (const QString &absoluteFileName)
{
    QUrl    url("file://" + absoluteFileName);
    QDesktopServices::openUrl (url);
}
