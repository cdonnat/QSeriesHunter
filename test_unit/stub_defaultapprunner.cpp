#include "stub_defaultapprunner.h"

//----------------------------------------------------------------------------------------------
DefaultAppRunnerStub::DefaultAppRunnerStub()
{
}

//----------------------------------------------------------------------------------------------
void DefaultAppRunnerStub::open (const QString & absoluteFileName)
{
    _absoluteFileName = absoluteFileName;
}
