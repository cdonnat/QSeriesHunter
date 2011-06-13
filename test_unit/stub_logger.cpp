#include "stub_logger.h"

//----------------------------------------------------------------------------------------------
LoggerStub::LoggerStub()
{
}

//----------------------------------------------------------------------------------------------
void LoggerStub::logSuccess (const QString & success)
{
    _success.append (success);
}

//----------------------------------------------------------------------------------------------
void LoggerStub::logInfo (const QString & info)
{
    _info.append (info);
}

//----------------------------------------------------------------------------------------------
void LoggerStub::logWarning (const QString & warning)
{
    _warning.append (warning);
}

//----------------------------------------------------------------------------------------------
const QString & LoggerStub::info () const
{
    return _info;
}

//----------------------------------------------------------------------------------------------
const QString & LoggerStub::warning () const
{
    return _warning;
}

//----------------------------------------------------------------------------------------------
void LoggerStub::clear ()
{
    _success.clear ();
    _info.clear ();
    _warning.clear ();
}
