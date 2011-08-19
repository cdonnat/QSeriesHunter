#include "stub_torrentfinder.h"

#include <QList>

//----------------------------------------------------------------------------------------------
TorrentFinderStub::TorrentFinderStub()
{
}

//----------------------------------------------------------------------------------------------
void TorrentFinderStub::reset()
{
    _request.clear();
}


//----------------------------------------------------------------------------------------------
void TorrentFinderStub::find(const QString & name)
{
    _request.append("|" + name);
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
