#include "finderresult.h"

//----------------------------------------------------------------------------------------------
FinderResult::FinderResult(const QString &name,
                           const QString &url,
                           bool           isTorrent,
                           uint           seed)
    :_name(name), _url(url), _seed(seed), _isTorrent (isTorrent)
{}

//----------------------------------------------------------------------------------------------
const QString & FinderResult::name() const
{
    return _name;
}

//----------------------------------------------------------------------------------------------
const QString & FinderResult::url()  const
{
    return _url;
}

//----------------------------------------------------------------------------------------------
const uint FinderResult::seed() const
{
    return _seed;
}


//----------------------------------------------------------------------------------------------
bool FinderResult::isTorrent() const
{
    return _isTorrent;
}