#ifndef IEDITFINDERWIDGET_H
#define IEDITFINDERWIDGET_H

class IEditFinderWidget
{
public:
    //----------------------------------------------------------------------------------------------
    virtual ~IEditFinderWidget () {}

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent finder are selected.]
    virtual void enableTorrent (bool isEnable) = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [DirectDownload finder are selected.]
    virtual void enableDirectDownload (bool isEnable) = 0;
};

#endif // IEDITFINDERWIDGET_H
