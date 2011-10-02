#include "stub_finderselection.h"

FinderSelectionWidgetStub::FinderSelectionWidgetStub():_torrentIsEnable(false),_ddlIsEnable(false)
{}

//----------------------------------------------------------------------------------------------
void FinderSelectionWidgetStub::enableTorrent (bool isEnable)
{
    _torrentIsEnable = isEnable;
}

//----------------------------------------------------------------------------------------------
void FinderSelectionWidgetStub::enableDirectDownload (bool isEnable)
{
    _ddlIsEnable = isEnable;
}

//----------------------------------------------------------------------------------------------
bool FinderSelectionWidgetStub::torrentIsEnable () const
{
    return _torrentIsEnable;
}

//----------------------------------------------------------------------------------------------
bool FinderSelectionWidgetStub::ddlIsEnable () const
{
    return _ddlIsEnable;
}
