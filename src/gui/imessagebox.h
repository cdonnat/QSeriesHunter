#ifndef IMESSAGEBOX_H
#define IMESSAGEBOX_H

class QString;

class IMessageBox
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~IMessageBox() {}

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Display a warning in message box popup.]
    virtual void displayWarning(const QString & title, const QString & message) = 0;
};

#endif // IMESSAGEBOX_H
