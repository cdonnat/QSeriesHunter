#include "stub_torrentfinder.h"

#include <QList>

//----------------------------------------------------------------------------------------------
TorrentFinderStub::TorrentFinderStub()
{
}

//----------------------------------------------------------------------------------------------
void TorrentFinderStub::search(const QString & name)
{
    _request = name;
}

void TorrentFinderStub::setResults (const TorrentFinderResults & results)
{
    _results = results;
}

//----------------------------------------------------------------------------------------------
const TorrentFinderResults & TorrentFinderStub::getResults() const
{
    return _results;
}

const QString & TorrentFinderStub::getRequest() const
{
    return _request;
}
