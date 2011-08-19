#include "editserie.h"

#include <QObject>
#include <QModelIndex>
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
    Q_ASSERT (_dialog);
    Q_ASSERT (_series);
    Q_ASSERT (_messageBox);
}

//----------------------------------------------------------------------------------------------
// REQ [None.]
// ENS [Capitalize string is returned (ex: "dr house" => "Dr House").]
QString toCapitalize (const QString & name)
{
    QStringList  list = name.simplified ().split (' ');
    QStringList  res;
    foreach (QString item , list) {
        item    = item.toLower ();
        item[0] = item[0].toUpper ();
        res << item;
    }
    return res.join (QChar(' '));
}

//----------------------------------------------------------------------------------------------
bool EditSerie::inputsAreValid() const
{
    return (!_dialog->name ().isEmpty () && _dialog->season() > 0);
}

//----------------------------------------------------------------------------------------------
Serie EditSerie::seriesFromDialog () const
{
    Q_ASSERT(inputsAreValid ());
    return Serie(toCapitalize(_dialog->name ()), _dialog->season ());
}

//----------------------------------------------------------------------------------------------
void EditSerie::addSerieIfNotAlreadyFollowed ()
{
    Q_ASSERT (inputsAreValid ());

    if (!_series->contains (seriesFromDialog()))  {
        _series->addSerie (seriesFromDialog(), _dialog->lastEpisodeDl ());
    }
    else {
        _messageBox->displayWarning (QObject::tr("Warning"),
                                     QObject::tr("You are already following this serie!"));
    }
}

//----------------------------------------------------------------------------------------------
void EditSerie::add ()
{
    if (_dialog->exec (QObject::tr("Add a new serie"))) {
        if (inputsAreValid()) {
            addSerieIfNotAlreadyFollowed();
        }
        else  {
            _messageBox->displayWarning (QObject::tr("Warning"),
                                         QObject::tr("Inputs are not valid!"));
        }
    }
}

//----------------------------------------------------------------------------------------------
void EditSerie::remove (const QModelIndex & selection)
{
    if (selection.isValid ()) {
        _series->removeSerie (_series->at (selection.row ()));
    }
    else {
        _messageBox->displayWarning
                (QObject::tr("Warning"),
                 QObject::tr("You have to select a serie if you want to remove one"));
    }
}

//----------------------------------------------------------------------------------------------
void EditSerie::edit (const QModelIndex & selection)
{
    if (selection.isValid ()) {
        runEditSerieDialog (selection);
    }
    else {
        _messageBox->displayWarning
                (QObject::tr("Warning"),
                 QObject::tr("You have to select a serie if you want to edit one"));
    }
}

//----------------------------------------------------------------------------------------------
void EditSerie::runEditSerieDialog (const QModelIndex & selection)
{
    Q_ASSERT (selection.isValid ());

    Serie serieEdited = _series->at (selection.row ());
    uint  lastEpisode = _series->lastEpisodeDl (serieEdited);
	
    if (_dialog->exec (QObject::tr("Edit a serie"),
					   serieEdited.name (),
                       serieEdited.season (),
                       lastEpisode)) {
        if (inputsAreValid ())  {
            // FIXME : find a better way of editing
            remove (selection);
            if (!_series->contains (seriesFromDialog ())) {
                _series->addSerie (seriesFromDialog(), _dialog->lastEpisodeDl ());
            }
            else {
                _series->addSerie (serieEdited, lastEpisode);
                _messageBox->displayWarning (QObject::tr("Warning"),
                                             QObject::tr("You are already following this serie!"));
            }
        }
        else {
            _messageBox->displayWarning (QObject::tr("Warning"),
                                         QObject::tr("Inputs are not valid!"));
        }
    }
}
