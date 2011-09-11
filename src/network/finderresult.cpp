#include "finderresult.h"

//----------------------------------------------------------------------------------------------
FinderResult::FinderResult(const QString &name,
                           const QString &url,
                           uint           seed)
    :_name(name), _url(url), _seed(seed)
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
