#ifndef REGEXPPROVIDER_H
#define REGEXPPROVIDER_H

#include <QRegExp>
#include <QString>

class Serie;

class RegExpProvider {
    
public:
    
    //----------------------------------------------------------------------------------------------
    virtual ~RegExpProvider() {};
       
    // Queries:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Return the regxp corresponding to the serie and episode.]
    virtual QString  getFindRegExp(const Serie & serie, uint episode) const = 0;

    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Return true is the given result match the regexp.]
    virtual bool resultIsMatching(const Serie & serie, uint episode, const QString & result) const = 0;

};

#endif // REGEXPPROVIDER_H