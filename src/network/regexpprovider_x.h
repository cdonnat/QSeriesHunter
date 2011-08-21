#ifndef REGEXPPROVIDER_X_H
#define REGEXPPROVIDER_X_H

#include <QString>

#include "regexpprovider.h"

class Serie;

class RegExpProvider_X : public RegExpProvider
{
    
public:
    // Constructors & Destructors
    
    //----------------------------------------------------------------------------------------------
    explicit RegExpProvider_X();
    
    //----------------------------------------------------------------------------------------------
    virtual ~RegExpProvider_X();
    
    // Queries:
    
    //----------------------------------------------------------------------------------------------
    virtual QString  getFindRegExp(const Serie & serie, uint episode) const;
    
};

#endif // REGEXPPROVIDER_X_H