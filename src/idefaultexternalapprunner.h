#ifndef IDEFAULTEXTERNALAPPRUNNER_H
#define IDEFAULTEXTERNALAPPRUNNER_H

class QString;

class IDefaultExternalAppRunner
{
public:

    //----------------------------------------------------------------------------------------------
    virtual ~IDefaultExternalAppRunner() {}

    //----------------------------------------------------------------------------------------------
    // REQ [absoluteFileName exists]
    // ENS [The file pointed by given filename is opened with default external application.]
    virtual void open (const QString & absoluteFileName) = 0;
};

#endif // IDEFAULTEXTERNALAPPRUNNER_H
