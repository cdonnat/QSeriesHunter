#ifndef LOGGERWIDGET_H
#define LOGGERWIDGET_H

#include <QWidget>

#include "ilogger.h"

class QPushButton;
class QString;
class QTextBrowser;

class LoggerWidget : public QWidget, public ILogger
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
    
private slots:
    
    //----------------------------------------------------------------------------------------------
    void clear();
    
private:
    void display(const QString & text);

private:
    QTextBrowser  * _logConsole;
    QPushButton   * _clearButton;
};

#endif // LOGGERWIDGET_H
