#ifndef IEDITSERIEDIALOG_H
#define IEDITSERIEDIALOG_H

#include <QString>

class IEditSerieDialog
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~IEditSerieDialog() {}

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Display the dialog box.]
    virtual bool exec(const QString & title             ,
					  const QString & name          = "",
                      uint            season        = 0 ,
                      uint            lastEpisodeDl = 0 ) = 0;

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Name of the serie is returned.]
    virtual QString name() const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Season of the serie is returned.]
    virtual uint season() const = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last episode downloaded of the serie is returned.]
    virtual uint lastEpisodeDl() const = 0;
};

#endif // IEDITSERIEDIALOG_H
