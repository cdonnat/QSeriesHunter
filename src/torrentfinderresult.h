#ifndef TORRENTFINDERRESULT_H
#define TORRENTFINDERRESULT_H

#include <QString>

class TorrentFinderResult
{
public:
    explicit TorrentFinderResult (const QString & name,
                                  const QString & url ,
                                  uint            seed);

    // Queries:
    const QString &    name() const;
    const QString &    url()  const;
    const uint         seed() const;

private :
    QString       _name;
    QString       _url;
    uint          _seed;
};

#endif // TORRENTFINDERRESULT_H
