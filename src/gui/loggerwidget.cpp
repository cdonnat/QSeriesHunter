#include "loggerwidget.h"

#include <QDateTime>
#include <QString>
#include <QTextEdit>

LoggerWidget::LoggerWidget() : _textEdit (new QTextEdit())
{
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::logSuccess (const QString & info)
{
    _textEdit->setTextColor (Qt::green);
    display (info);
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::logInfo (const QString & info)
{
    _textEdit->setTextColor (Qt::black);
    display (info);
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::logWarning (const QString & warning)
{
    _textEdit->setTextColor (Qt::red);
    display (warning);
}

//----------------------------------------------------------------------------------------------
QTextEdit * LoggerWidget::getTextEdit() const
{
    return _textEdit;
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::display(const QString & text)
{
    QString toDisplay = QString("[%1] %2").arg(QDateTime::currentDateTime ().toString ("hh:mm:ss"))
                                          .arg(text);

    _textEdit->append (toDisplay);
}
