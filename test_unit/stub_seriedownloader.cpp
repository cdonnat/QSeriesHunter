#include "stub_seriedownloader.h"

SerieDownloaderStub::SerieDownloaderStub()
{
}

void SerieDownloaderStub::download (const QString & absoluteFileName)
{
    _absoluteFileName = absoluteFileName;
}
