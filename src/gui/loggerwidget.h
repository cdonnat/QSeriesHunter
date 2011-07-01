#ifndef LOGGERWIDGET_H
#define LOGGERWIDGET_H

#include "ilogger.h"

class QTextEdit;
class QString;

class LoggerWidget : public ILogger
{
public:
    //----------------------------------------------------------------------------------------------
    explicit LoggerWidget ();

    //----------------------------------------------------------------------------------------------
    virtual ~LoggerWidget();

    //----------------------------------------------------------------------------------------------
    virtual void logSuccess (const QString & success);

    //----------------------------------------------------------------------------------------------
    virtual void logInfo (const QString & info);

    //----------------------------------------------------------------------------------------------
    virtual void logWarning (const QString & warning);

    //----------------------------------------------------------------------------------------------
    QTextEdit * const getTextEdit() const;

private:
    void display(const QString & text);

private:
    QTextEdit  * _textEdit;
};

#endif // LOGGERWIDGET_H
