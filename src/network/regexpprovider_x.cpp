#include "regexpprovider_x.h"

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
    .arg (QString::number (episode).rightJustified (2, '0')); 
}

//----------------------------------------------------------------------------------------------
bool RegExpProvider_X::resultIsMatching(const Serie & serie, uint episode, const QString & result) const
{
    QRegExp regExp;
    regExp.setCaseSensitivity (Qt::CaseInsensitive);
    regExp.setPattern (QString(".*%1.*%2x%3.*")
                       .arg (QRegExp::escape (serie.name ()).replace (' ', ".*"))
                       .arg (serie.season ())
                       .arg (episode));
    return regExp.exactMatch(result);
}