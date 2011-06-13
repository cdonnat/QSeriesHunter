#ifndef STUB_LOGGER_H
#define STUB_LOGGER_H

#include "ilogger.h"

#include <QString>

class LoggerStub : public ILogger
{
public:
    LoggerStub();

    //----------------------------------------------------------------------------------------------
    virtual void logSuccess (const QString & success);

    //----------------------------------------------------------------------------------------------
    virtual void logInfo (const QString & info);

    //----------------------------------------------------------------------------------------------
    virtual void logWarning (const QString & warning);

    //----------------------------------------------------------------------------------------------
    const QString & info () const;

    //----------------------------------------------------------------------------------------------
    const QString & warning () const;

    //----------------------------------------------------------------------------------------------
    void clear ();

private :
    QString _success;
    QString _info;
    QString _warning;

};

#endif // STUB_LOGGER_H
