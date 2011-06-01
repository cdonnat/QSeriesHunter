#ifndef SERIE_H
#define SERIE_H

#include <QString>

class Serie
{
public:
    // Constructors:
    explicit Serie(const QString & name, uint season, uint nbEpisodes, uint lastEpisodeSeen);

    // Commands:

    //----------------------------------------------------------------------------------------------
    // REQ [Season is not finished.]
    // ENS [Last episode seen is incremented.]
    void nextEpisode();

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
    // REQ [None.]
    // ENS [Last episode seen is returned.]
    uint lastEpisodeSeen() const;

private:
    QString    _name;
    uint       _season;
    uint       _nbEpisodes;
    uint       _lastEpisodeSeen;
};

#endif // SERIE_H
