#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "imessagebox.h"

class MessageBox : public IMessageBox
{
public:
    //----------------------------------------------------------------------------------------------
    MessageBox();

    //----------------------------------------------------------------------------------------------
    virtual void displayWarning (const QString &title, const QString &message);
};

#endif // MESSAGEBOX_H
