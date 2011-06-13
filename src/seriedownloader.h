#ifndef SERIEDOWNLOADER_H
#define SERIEDOWNLOADER_H

#include "iseriedownloader.h"

class SerieDownloader : public ISerieDownloader
{
public:
    //----------------------------------------------------------------------------------------------
    SerieDownloader();

    //----------------------------------------------------------------------------------------------
    virtual void download (const QString &absoluteFileName);
};

#endif // SERIEDOWNLOADER_H
