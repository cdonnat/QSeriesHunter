#ifndef STUB_EDITSERIEDIALOG_H
#define STUB_EDITSERIEDIALOG_H

#include "ieditseriedialog.h"

#include <QString>

class EditSerieDialogStub : public IEditSerieDialog
{
public:
    EditSerieDialogStub();

    // Commands:

    //----------------------------------------------------------------------------------------------
    void setup(bool execIsOk,
               const QString & name = "",
               uint            season = 0,
               uint            lastEpisodeDl = 0);

    //----------------------------------------------------------------------------------------------
    virtual bool exec(const QString & title             ,
					  const QString & name          = "",
                      uint            season        = 0,
                      uint            lastEpisodeDl = 0);

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual QString name() const;

    //----------------------------------------------------------------------------------------------
    virtual uint season() const;

    //----------------------------------------------------------------------------------------------
    virtual uint lastEpisodeDl() const;

	//----------------------------------------------------------------------------------------------
	virtual QString title() const;
	
private:
    bool      _execIsOk;
	QString   _title;
    QString   _name;
    uint      _season;
    uint      _lastEpisodeDl;
};

#endif // STUB_EDITSERIEDIALOG_H
