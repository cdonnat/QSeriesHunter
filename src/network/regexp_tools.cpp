#include "regexp_tools.h"

#include <QRegExp>

QString getSeriesNameForRegExp(const Serie & serie)
{
    return QRegExp::escape (serie.name ()).replace (' ', ".*");
}

QString toTwoDigits (uint number)
{
    return QString::number (number).rightJustified (2, '0');
}