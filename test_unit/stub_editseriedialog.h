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
               const QString & season = "",
               const QString & lastEpisodeDl = "");

    //----------------------------------------------------------------------------------------------
    virtual bool exec(const QString & name          = "",
                      const QString & season        = "",
                      const QString & lastEpisodeDl = "");

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual QString name() const;

    //----------------------------------------------------------------------------------------------
    virtual QString season() const;

    //----------------------------------------------------------------------------------------------
    virtual QString lastEpisodeDl() const;

private:
    bool      _execIsOk;
    QString   _name;
    QString   _season;
    QString   _lastEpisodeDl;
};

#endif // STUB_EDITSERIEDIALOG_H
