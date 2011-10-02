#ifndef FINDERRESULT_H
#define FINDERRESULT_H

#include <QString>

class FinderResult
{
public:

    //----------------------------------------------------------------------------------------------
    explicit FinderResult (const QString & name,
                           const QString & url ,
                           bool            isTorrent,
                           uint            seed);

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Name is returned.]
    const QString & name() const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Url where torrent is located is returned.]
    const QString & url()  const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if current result is torrent.]
    bool isTorrent() const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Number of seed is returned.]
    const uint  seed() const;

private :
    QString       _name;
    QString       _url;
    uint          _seed;
    bool          _isTorrent;
};

#endif // FINDERRESULT_H
