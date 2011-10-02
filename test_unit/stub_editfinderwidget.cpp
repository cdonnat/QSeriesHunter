#include "stub_editfinderwidget.h"

EditFinderWidgetStub::EditFinderWidgetStub():_torrentIsEnable(false),_ddlIsEnable(false)
{}

//----------------------------------------------------------------------------------------------
void EditFinderWidgetStub::enableTorrent (bool isEnable)
{
    _torrentIsEnable = isEnable;
}

//----------------------------------------------------------------------------------------------
void EditFinderWidgetStub::enableDirectDownload (bool isEnable)
{
    _ddlIsEnable = isEnable;
}

//----------------------------------------------------------------------------------------------
bool EditFinderWidgetStub::torrentIsEnable () const
{
    return _torrentIsEnable;
}

//----------------------------------------------------------------------------------------------
bool EditFinderWidgetStub::ddlIsEnable () const
{
    return _ddlIsEnable;
}
