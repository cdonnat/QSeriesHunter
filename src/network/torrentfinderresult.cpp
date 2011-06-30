#include "TorrentFinderResult.h"


//----------------------------------------------------------------------------------------------
TorrentFinderResult::TorrentFinderResult(const QString &name,
                                         const QString &url,
                                         uint           seed)
    :_name(name), _url(url), _seed(seed)
{}

//----------------------------------------------------------------------------------------------
const QString &    TorrentFinderResult::name() const
{
    return _name;
}

//----------------------------------------------------------------------------------------------
const QString &    TorrentFinderResult::url()  const
{
    return _url;
}

//----------------------------------------------------------------------------------------------
const uint TorrentFinderResult::seed() const
{
    return _seed;
}
