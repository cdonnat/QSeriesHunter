#ifndef IFINDERSELECTIONWIDGET_H
#define IFINDERSELECTIONWIDGET_H

class IFinderSelectionWidget
{
public:
    //----------------------------------------------------------------------------------------------
    virtual ~IFinderSelectionWidget () {}

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Torrent finder are selected.]
    virtual void enableTorrent (bool isEnable) = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [DirectDownload finder are selected.]
    virtual void enableDirectDownload (bool isEnable) = 0;
};

#endif // IFINDERSELECTIONWIDGET_H
