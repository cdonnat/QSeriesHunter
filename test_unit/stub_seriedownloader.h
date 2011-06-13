#ifndef STUB_SERIEDOWNLOADER_H
#define STUB_SERIEDOWNLOADER_H

#include "iseriedownloader.h"

#include <QString>

class SerieDownloaderStub : public ISerieDownloader
{
public:
    SerieDownloaderStub();

    virtual void download (const QString & absoluteFileName);

    QString  _absoluteFileName;

};

#endif // STUB_SERIEDOWNLOADER_H
