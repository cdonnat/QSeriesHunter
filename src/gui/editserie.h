#ifndef EDITSERIE_H
#define EDITSERIE_H

#include "serie.h"

class IEditSerieDialog;
class ISeriesController;
class IMessageBox;
class QModelIndex;

class EditSerie
{
public:

    //----------------------------------------------------------------------------------------------
    explicit EditSerie(IEditSerieDialog  * const dialog,
                       ISeriesController * const series,
                       IMessageBox       * const messageBox);

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [A new serie is added if it does not already exists.]
    void add ();

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Given serie is removed if it exists.]
    void remove (const QModelIndex & selection);

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Serie is modified.]
    void edit (const QModelIndex & selection);

private:


    //----------------------------------------------------------------------------------------------
    // REQ [InputsAreValid.]
    // ENS [The serie from dialog is returned.]
    Serie fromDialog () const;

    //----------------------------------------------------------------------------------------------
    // REQ [InputsAreValid.]
    // ENS [The serie is added if not already followed.]
    void addSerieIfNotAlreadyFollowed ();

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if all inputs are not empty and valid.]
    bool inputsAreValid() const;

    //----------------------------------------------------------------------------------------------
    // REQ [Given selection is valid.]
    // ENS [Run the edit dialog in order to modify a serie.]
    void runEditSerieDialog(const QModelIndex & selection);

private:
    IEditSerieDialog   * const _dialog;
    ISeriesController  * const _series;
    IMessageBox        * const _messageBox;
};

#endif // EDITSERIE_H
