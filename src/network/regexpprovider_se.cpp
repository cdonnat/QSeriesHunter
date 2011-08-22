#include "regexpprovider_se.h"
#include "regexp_tools.h"

#include "serie.h"

//----------------------------------------------------------------------------------------------
RegExpProvider_Se::RegExpProvider_Se():RegExpProvider()
{
}

//----------------------------------------------------------------------------------------------
RegExpProvider_Se::~RegExpProvider_Se()
{}

//----------------------------------------------------------------------------------------------
QString  RegExpProvider_Se::getFindRegExp(const Serie & serie, uint episode) const
{
    return QString("%1 S%2E%3") // Season S??E??
                  .arg (serie.name ())
                  .arg (toTwoDigits (serie.season ()))
                  .arg (toTwoDigits (episode));
}

//----------------------------------------------------------------------------------------------
bool RegExpProvider_Se::resultIsMatching(const Serie & serie, uint episode, const QString & result) const
{
    QRegExp regExp;
    regExp.setCaseSensitivity (Qt::CaseInsensitive);
    regExp.setPattern (QString(".*%1.*S%2.*E%3.*")
                        .arg (getSeriesNameForRegExp(serie))
                        .arg (toTwoDigits(serie.season ()))
                        .arg (toTwoDigits(episode)));
    return regExp.exactMatch(result);
}
