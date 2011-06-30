#ifndef STUB_DEFAULTAPPRUNNER_H
#define STUB_DEFAULTAPPRUNNER_H

#include "idefaultexternalapprunner.h"

#include <QString>

class DefaultAppRunnerStub : public IDefaultExternalAppRunner
{
public:
    //----------------------------------------------------------------------------------------------
    DefaultAppRunnerStub();
    virtual ~DefaultAppRunnerStub() {}

    //----------------------------------------------------------------------------------------------
    virtual void open (const QString & absoluteFileName);

    QString  _absoluteFileName;

};

#endif // STUB_DEFAULTAPPRUNNER_H
