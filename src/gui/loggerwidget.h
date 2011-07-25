#ifndef LOGGERWIDGET_H
#define LOGGERWIDGET_H

#include <QObject>

#include "ilogger.h"

class QString;
class QTextBrowser;
class QWidget;

class LoggerWidget : public QObject, public ILogger
{
    Q_OBJECT
    
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
    QWidget * const getLogConsole() const;
    
private:
    void display(const QString & text);

private:
    QTextBrowser  * _logConsole;
};

#endif // LOGGERWIDGET_H
