#include "abstractfinder.h"


AbstractFinder::AbstractFinder (const QString & type): _type (type)
{
    Q_ASSERT(type == "Torrent" || type == "DirectDownload");
}

const QString & AbstractFinder::getType() const 
{
    return _type;
}