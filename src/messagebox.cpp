#include "messagebox.h"

#include <QMessageBox>

//----------------------------------------------------------------------------------------------
MessageBox::MessageBox()
{
}


//----------------------------------------------------------------------------------------------
void MessageBox::displayWarning (const QString &title, const QString &message)
{
    QMessageBox::warning (NULL, title, message);
}
