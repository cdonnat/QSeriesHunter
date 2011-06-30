#ifndef IEDITSERIEDIALOG_H
#define IEDITSERIEDIALOG_H

#include <QString>

class IEditSerieDialog
{
public:

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Display the dialog box.]
    virtual bool exec(const QString & name          = "",
                      const QString & season        = "",
                      const QString & lastEpisodeDl = "") = 0;

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Name of the serie is returned.]
    virtual QString name() const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Season of the serie is returned.]
    virtual QString season() const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last episode downloaded of the serie is returned.]
    virtual QString lastEpisodeDl() const = 0;
};

#endif // IEDITSERIEDIALOG_H
