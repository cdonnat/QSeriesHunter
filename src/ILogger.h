#ifndef ILOGGER_H
#define ILOGGER_H

class QString;

class ILogger
{
public:
    //----------------------------------------------------------------------------------------------
    ILogger () {}
    virtual ~ILogger () {}

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Success is displayed to user.]
    virtual void logSuccess (const QString & success) = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Info is displayed to user.]
    virtual void logInfo (const QString & info) = 0;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Warning is displayed to user.]
    virtual void logWarning (const QString & warning) = 0;
};

#endif // ILOGGER_H
