#ifndef DEFAULTEXTERNALAPPRUNNER_H
#define DEFAULTEXTERNALAPPRUNNER_H

#include "idefaultexternalapprunner.h"

class DefaultExternalAppRunner : public IDefaultExternalAppRunner
{
public:
    //----------------------------------------------------------------------------------------------
    DefaultExternalAppRunner();

    //----------------------------------------------------------------------------------------------
    virtual void open (const QString &absoluteFileName);
};

#endif // DEFAULTEXTERNALAPPRUNNER_H
