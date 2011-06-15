#ifndef SERIE_H
#define SERIE_H

#include <QString>

class Serie
{
public:

    //----------------------------------------------------------------------------------------------
    // Constructors:
    Serie(const QString & name, uint season);

    //----------------------------------------------------------------------------------------------
    Serie (const Serie & serie);

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
    // ENS [True is returned if l and r have the same name and the same season.]
    bool operator==(const Serie & r);

    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [True is returned if l and r have don't have the same name and the same season.]
    bool operator!=(const Serie & r);

private:
    QString    _name;
    uint       _season;
};

// Operators:

//----------------------------------------------------------------------------------------------
// REQ [None.]
// ENS [True is returned if l.name < r.name and l.season < r.season.]
bool operator<(const Serie & l, const Serie & r);



#endif // SERIE_H
