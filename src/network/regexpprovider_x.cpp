#include "regexpprovider_x.h"
#include "regexp_tools.h"

#include "serie.h"

//----------------------------------------------------------------------------------------------
RegExpProvider_X::RegExpProvider_X()
{}

//----------------------------------------------------------------------------------------------
RegExpProvider_X::~RegExpProvider_X()
{}

//----------------------------------------------------------------------------------------------
QString  RegExpProvider_X::getFindRegExp(const Serie & serie, uint episode) const
{
    return QString("%1 %2x%3") // Season ??x??
    .arg (serie.name ())
    .arg (serie.season ())
    .arg (toTwoDigits(episode)); 
}

//----------------------------------------------------------------------------------------------
bool RegExpProvider_X::resultIsMatching(const Serie & serie, uint episode, const QString & result) const
{
    QRegExp regExp;
    regExp.setCaseSensitivity (Qt::CaseInsensitive);
    regExp.setPattern (QString(".*%1.*%2x%3.*")
                       .arg (getSeriesNameForRegExp(serie))
                       .arg (serie.season ())
                       .arg (toTwoDigits(episode)));
    return regExp.exactMatch(result);
}