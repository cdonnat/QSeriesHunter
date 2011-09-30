#include "findersmemento.h"

#include <QDataStream>

//----------------------------------------------------------------------------------------------
FindersMemento::FindersMemento(bool torrentIsEnable, bool ddlIsEnable):
_torrentIsEnable(torrentIsEnable), _ddlIsEnable(ddlIsEnable)
{
}

//----------------------------------------------------------------------------------------------
bool FindersMemento::isTorrentEnable() const
{
    return _torrentIsEnable;
}

//----------------------------------------------------------------------------------------------
bool FindersMemento::isDirectDownloadEnable() const
{
    
    return _ddlIsEnable;
}


//----------------------------------------------------------------------------------------------
FindersMemento FindersMemento::loadFromStream(QDataStream & dataStream)
{
    bool torrentIsEnable, ddlIsEnable;
    dataStream >> torrentIsEnable;
    dataStream >> ddlIsEnable;
    return FindersMemento(torrentIsEnable, ddlIsEnable);
}

QDataStream & operator<<(QDataStream & o, const FindersMemento & findersMemento)
{
    o << findersMemento._torrentIsEnable;
    o << findersMemento._ddlIsEnable;
    return o;
}
