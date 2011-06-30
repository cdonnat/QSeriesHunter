#ifndef TORRENTFINDERRESULT_H
#define TORRENTFINDERRESULT_H

#include <QString>

class TorrentFinderResult
{
public:

    //----------------------------------------------------------------------------------------------
    explicit TorrentFinderResult (const QString & name,
                                  const QString & url ,
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
    // ENS [Number of seed is returned.]
    const uint  seed() const;

private :
    QString       _name;
    QString       _url;
    uint          _seed;
};

#endif // TORRENTFINDERRESULT_H
