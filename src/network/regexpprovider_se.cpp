#include "regexpprovider_se.h"

#include "serie.h"

//----------------------------------------------------------------------------------------------
RegExpProvider_Se::RegExpProvider_Se()
{}

//----------------------------------------------------------------------------------------------
RegExpProvider_Se::~RegExpProvider_Se()
{}

//----------------------------------------------------------------------------------------------
QString  RegExpProvider_Se::getFindRegExp(const Serie & serie, uint episode) const
{
    return QString("%1 S%2E%3") // Season S??E??
                  .arg (serie.name ())
                  .arg (QString::number (serie.season ()).rightJustified (2, '0'))
                  .arg (QString::number (episode).rightJustified (2, '0'));
}
