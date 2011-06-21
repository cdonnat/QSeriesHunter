#ifndef ISERIEDOWNLOADER_H
#define ISERIEDOWNLOADER_H

class QString;

class ISerieDownloader
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~ISerieDownloader() {}

    //----------------------------------------------------------------------------------------------
    // REQ [absoluteFileName exists]
    // ENS [The file pointed by given filename is downloaded with default software.]
    virtual void download (const QString & absoluteFileName) = 0;
};

#endif // ISERIEDOWNLOADER_H
