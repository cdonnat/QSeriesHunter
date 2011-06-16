#ifndef EDITSERIE_H
#define EDITSERIE_H

class IEditSerieDialog;
class ISeriesController;
class IMessageBox;

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

private:

    //----------------------------------------------------------------------------------------------
    // REQ [InputsAreValid.]
    // ENS [The serie is added if not already followed.]
    void addSerieIfNotAlreadyFollowed ();

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if all inputs are not empty and valid.]
    bool inputsAreValid() const;

private:
    IEditSerieDialog   * const _dialog;
    ISeriesController  * const _series;
    IMessageBox        * const _messageBox;
};

#endif // EDITSERIE_H
