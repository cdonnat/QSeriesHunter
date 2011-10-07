#ifndef SERIE_H
#define SERIE_H

#include <QString>

class Serie
{
public:

    //----------------------------------------------------------------------------------------------
    // Constructors:
    Serie() {}; // Provided for convenience.

    //----------------------------------------------------------------------------------------------
    Serie(const QString & name, uint season, uint lastEpisode = 0, bool isEnable = true);

    //----------------------------------------------------------------------------------------------
    Serie (const Serie & serie);

    // Commands:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Increment the last episode.]
    void inc ();
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Enable/Disable serie.]
    void enable (bool isEnable);
    
    // Queries:

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
    // ENS [The last episode is returned.]
    uint lastEpisode() const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if the serie is enable.]
    bool isEnable() const;
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if l and r have the same name and the same season.]
    bool operator==(const Serie & r) const;

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if l and r have don't have the same name and the same season.]
    bool operator!=(const Serie & r) const;

private:
    QString    _name;
    uint       _season;
    uint       _lastEpisode;
    bool       _isEnable;
};

// Operators:

//----------------------------------------------------------------------------------------------
// REQ [None.]
// ENS [True is returned if l.name < r.name and l.season < r.season.]
bool operator<(const Serie & l, const Serie & r);


#endif // SERIE_H
