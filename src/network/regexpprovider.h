#ifndef REGEXPPROVIDER_H
#define REGEXPPROVIDER_H

#include <QString>

class Serie;

class RegExpProvider {
    
public:
    // Constructors & Destructors
    
    //----------------------------------------------------------------------------------------------
    virtual ~RegExpProvider() {};
       
    // Queries:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Return the regxp corresponding to the serie and episode.]
    virtual QString  getFindRegExp(const Serie & serie, uint episode) const = 0;

};

#endif // REGEXPPROVIDER_H