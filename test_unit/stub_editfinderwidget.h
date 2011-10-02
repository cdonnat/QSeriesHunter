#ifndef STUB_FINDERSELECTIONWIDGET_H
#define STUB_FINDERSELECTIONWIDGET_H

#include "ieditfinderwidget.h"

class EditFinderWidgetStub : public IEditFinderWidget
{
public:
    EditFinderWidgetStub();

    //----------------------------------------------------------------------------------------------
    virtual void enableTorrent (bool isEnable);

    //----------------------------------------------------------------------------------------------
    virtual void enableDirectDownload (bool isEnable);

    //----------------------------------------------------------------------------------------------
    bool torrentIsEnable () const;

    //----------------------------------------------------------------------------------------------
    bool ddlIsEnable () const;

private :
    bool _torrentIsEnable, _ddlIsEnable;

};

#endif // STUB_FINDERSELECTIONWIDGET_H
