#ifndef REGEXPPROVIDER_SE_H
#define REGEXPPROVIDER_SE_H

#include <QString>

#include "regexpprovider.h"

class Serie;

class RegExpProvider_Se : public RegExpProvider
{
    
public:
    // Constructors & Destructors
    
    //----------------------------------------------------------------------------------------------
    explicit RegExpProvider_Se();
    
    //----------------------------------------------------------------------------------------------
    virtual ~RegExpProvider_Se();
    
    // Queries:
    
    //----------------------------------------------------------------------------------------------
    virtual QString  getFindRegExp(const Serie & serie, uint episode) const;
    
};

#endif // REGEXPPROVIDER_SE_H