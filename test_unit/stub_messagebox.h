#ifndef STUB_MESSAGEBOX_H
#define STUB_MESSAGEBOX_H

#include "imessagebox.h"

class MessageBoxStub : public IMessageBox
{
public:
    MessageBoxStub();

    virtual void displayWarning(const QString & title, const QString & message);
    bool displayWarningIsCalled() const;
    void clear();

private:
    bool _displayWarningCalled;
};

#endif // STUB_MESSAGEBOX_H
