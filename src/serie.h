#ifndef SERIE_H
#define SERIE_H

#include <QString>

class Serie
{
public:
    // Constructors:
    explicit Serie(const QString & name, uint season, uint nbEpisodes, uint lastEpisodeDownloaded);

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [Season is not finished.]
    // ENS [Last episode seen is incremented.]
    void inc();

    // Queries:

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if season is finished (ie lastEpisodeSeen = nbEpisodes).]
    bool isFinished() const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Name of the serie is returned.]
    const QString & name() const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Season number of the serie is retured.]
    uint season() const;

    //----------------------------------------------------------------------------------------------
    // REQ [Season is not finished.]
    // ENS [Next episode to download is returned.]
    uint nextEpisode () const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last episode seen is returned.]
    uint lastEpisodeDownloaded() const;

private:
    QString    _name;
    uint       _season;
    uint       _nbEpisodes;
    uint       _lastEpisodeDownloaded;
};

// Operators:

//----------------------------------------------------------------------------------------------
// REQ [None.]
// ENS [True is returned if l and r have the same name and the same season.]
bool operator==(const Serie & l, const Serie & r);

//----------------------------------------------------------------------------------------------
// REQ [None.]
// ENS [True is returned if l and r have don't have the same name and the same season.]
bool operator!=(const Serie & l, const Serie & r);

#endif // SERIE_H
