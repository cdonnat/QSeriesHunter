#include "stub_messagebox.h"

#include <QtGlobal>

MessageBoxStub::MessageBoxStub()
{
    clear();
}

void MessageBoxStub::displayWarning(const QString & title, const QString & message)
{
    Q_UNUSED(title);
    Q_UNUSED(message);
    _displayWarningCalled = true;
}

bool MessageBoxStub::displayWarningIsCalled() const
{
    return _displayWarningCalled;
}

void MessageBoxStub::clear()
{
    _displayWarningCalled = false;
}
