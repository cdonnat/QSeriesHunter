#include "stub_editseriedialog.h"

//----------------------------------------------------------------------------------------------
EditSerieDialogStub::EditSerieDialogStub()
{
}

//----------------------------------------------------------------------------------------------
void EditSerieDialogStub::setup(bool execIsOk,
           const QString & name,
           uint            season,
           uint            lastEpisodeDl)
{
    _execIsOk      = execIsOk;
    _name          = name;
    _season        = season;
    _lastEpisodeDl = lastEpisodeDl;
}

//----------------------------------------------------------------------------------------------
bool EditSerieDialogStub::exec(const QString & title        ,
							   const QString & name         ,
                               uint            season       ,
                               uint            lastEpisodeDl)
{
	_title = title;
    Q_UNUSED(name);
    Q_UNUSED(season);
    Q_UNUSED(lastEpisodeDl);
    return _execIsOk;
}

//----------------------------------------------------------------------------------------------
QString EditSerieDialogStub::title() const { return _title; }

//----------------------------------------------------------------------------------------------
QString EditSerieDialogStub::name() const { return _name; }

//----------------------------------------------------------------------------------------------
uint EditSerieDialogStub::season() const { return _season; }

//----------------------------------------------------------------------------------------------
uint EditSerieDialogStub::lastEpisodeDl() const {return _lastEpisodeDl; }
