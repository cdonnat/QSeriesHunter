#ifndef SERIESPROVIDER_H
#define SERIESPROVIDER_H

#include <QMap>

class INetworkAccess;
class QStringList;

class SeriesProvider
{
public:

    //----------------------------------------------------------------------------------------------
    SeriesProvider(INetworkAccess * network);

    // Commands:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [A request to find all available series is sent.]
    void searchAllSeries();
    
    // Queries:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [All available series found are returned.]
    QStringList getAllSeries() const;
    
private:
    
    void retrieveResults();
    
    INetworkAccess          * _network;
    QMap<QString, QString>    _series;
};

#endif // SERIESPROVIDER_H
