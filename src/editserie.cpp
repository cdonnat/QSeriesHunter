#include "editserie.h"

#include <QObject>
#include <QString>
#include <QStringList>
#include "ieditseriedialog.h"
#include "iseriescontroller.h"
#include "imessagebox.h"
#include "serie.h"

//----------------------------------------------------------------------------------------------
EditSerie::EditSerie(IEditSerieDialog  * const dialog,
                     ISeriesController * const series,
                     IMessageBox       * const messageBox):
    _dialog(dialog), _series(series), _messageBox(messageBox)
{
    Q_ASSERT (dialog);
    Q_ASSERT (series);
    Q_ASSERT (messageBox);
}

//----------------------------------------------------------------------------------------------
// REQ [None.]
// ENS [Capitalize string is returned (ex: "dr house" => "Dr House").]
QString toCapitalize (const QString & name)
{
    QStringList  list = name.simplified ().split (' ');
    QStringList  res;
    foreach (QString item , list)
    {
        item    = item.toLower ();
        item[0] = item[0].toUpper ();
        res << item;
    }
    return res.join (QChar(' '));
}

//----------------------------------------------------------------------------------------------
bool EditSerie::inputsAreValid() const
{
    return (!_dialog->name ().isEmpty () && !_dialog->season ().isEmpty () &&
            !_dialog->lastEpisodeDl ().isEmpty ());
}

//----------------------------------------------------------------------------------------------
void EditSerie::addSerieIfNotAlreadyFollowed ()
{
    Q_ASSERT (inputsAreValid ());
    Serie  serie(toCapitalize(_dialog->name ()), _dialog->season ().toUInt ());
    if (!_series->contains (serie))
    {
        _series->addSerie (serie, _dialog->lastEpisodeDl ().toUInt());
    }
    else
    {
        _messageBox->displayWarning (QObject::tr("Warning"),
                                     QObject::tr("You are already following this serie!"));
    }
}

//----------------------------------------------------------------------------------------------
void EditSerie::add ()
{
    if (_dialog->exec ())
    {
        if (inputsAreValid())
        {
            addSerieIfNotAlreadyFollowed();
        }
        else
        {
            _messageBox->displayWarning (QObject::tr("Warning"),
                                         QObject::tr("Inputs are not valid!"));
        }
    }
}

