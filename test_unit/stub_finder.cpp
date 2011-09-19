#include "stub_finder.h"

#include <QList>

//----------------------------------------------------------------------------------------------
FinderStub::FinderStub(const QString & type) : AbstractFinder(type)
{
}

//----------------------------------------------------------------------------------------------
void FinderStub::reset()
{
    _request.clear();
}


//----------------------------------------------------------------------------------------------
void FinderStub::find(const QString & name)
{
    _request.append("|" + name);
}

void FinderStub::setResults (const FinderResults & results)
{
    _results = results;
}

//----------------------------------------------------------------------------------------------
const FinderResults & FinderStub::getResults() const
{
    return _results;
}

const QString & FinderStub::getRequest() const
{
    return _request;
}
