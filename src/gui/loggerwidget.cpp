#include "loggerwidget.h"

#include <QDateTime>
#include <QPushButton>
#include <QString>
#include <QTextBrowser>

//----------------------------------------------------------------------------------------------
LoggerWidget::LoggerWidget() : QObject(),_logConsole (new QTextBrowser())
{
}

//----------------------------------------------------------------------------------------------
LoggerWidget::~LoggerWidget()
{
    _logConsole->deleteLater ();
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::logSuccess (const QString & info)
{
    _logConsole->setTextColor (Qt::green);
    display (info);
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::logInfo (const QString & info)
{
    _logConsole->setTextColor (Qt::black);
    display (info);
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::logWarning (const QString & warning)
{
    _logConsole->setTextColor (Qt::red);
    display (warning);
}

//----------------------------------------------------------------------------------------------
QWidget * const LoggerWidget::getLogConsole() const
{
    return _logConsole;
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::display(const QString & text)
{
    QString currentDate = QDateTime::currentDateTime ().toString ("hh:mm:ss");
    QString toDisplay   = QString("[%1] %2").arg(currentDate)
                                            .arg(text);

    _logConsole->append (toDisplay);
}
