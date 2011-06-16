#ifndef IMESSAGEBOX_H
#define IMESSAGEBOX_H

class QString;

class IMessageBox
{
public:

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void displayWarning(const QString & title, const QString & message) = 0;
};

#endif // IMESSAGEBOX_H
