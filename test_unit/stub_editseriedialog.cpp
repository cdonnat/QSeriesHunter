#include "stub_editseriedialog.h"

//----------------------------------------------------------------------------------------------
EditSerieDialogStub::EditSerieDialogStub()
{
}

//----------------------------------------------------------------------------------------------
void EditSerieDialogStub::setup(bool execIsOk,
           const QString & name,
           const QString & season,
           const QString & lastEpisodeDl)
{
    _execIsOk      = execIsOk;
    _name          = name;
    _season        = season;
    _lastEpisodeDl = lastEpisodeDl;
}

//----------------------------------------------------------------------------------------------
bool EditSerieDialogStub::exec(const QString & name         ,
                               const QString & season       ,
                               const QString & lastEpisodeDl)
{
    return _execIsOk;
}

//----------------------------------------------------------------------------------------------
QString EditSerieDialogStub::name() const { return _name; }

//----------------------------------------------------------------------------------------------
QString EditSerieDialogStub::season() const { return _season; }

//----------------------------------------------------------------------------------------------
QString EditSerieDialogStub::lastEpisodeDl() const {return _lastEpisodeDl; }
