#include "loggerwidget.h"

#include <QDateTime>
#include <QPushButton>
#include <QString>
#include <QTextBrowser>
#include <QVBoxLayout>

//----------------------------------------------------------------------------------------------
LoggerWidget::LoggerWidget() : QWidget(),
_logConsole (new QTextBrowser(this)), 
_clearButton(new QPushButton(QIcon(":images/clear.png"), tr("Clear"), this))
{
    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(_logConsole);
    layout->addWidget(_clearButton);
    setLayout(layout);
    
    connect(_clearButton, SIGNAL(clicked()), this, SLOT(clear()));
}

//----------------------------------------------------------------------------------------------
LoggerWidget::~LoggerWidget()
{
    _logConsole->deleteLater ();
}

//----------------------------------------------------------------------------------------------
void LoggerWidget::clear()
{
    _logConsole->clear();
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
void LoggerWidget::display(const QString & text)
{
    QString currentDate = QDateTime::currentDateTime ().toString ("hh:mm:ss");
    QString toDisplay   = QString("[%1] %2").arg(currentDate)
                                            .arg(text);

    _logConsole->append (toDisplay);
}
