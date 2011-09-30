#ifndef FINDERSMEMENTO_H
#define FINDERSMEMENTO_H

class QDataStream;

class FindersMemento
{
public:        
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last save memento is returned. An empty memento is returned if none are found.]
    static FindersMemento loadFromStream(QDataStream & o);

    friend QDataStream & operator<<(QDataStream & o, const FindersMemento & findersMemento);
    
private:
  
    //----------------------------------------------------------------------------------------------
    FindersMemento(bool torrentIsEnable, bool ddlIsEnable);

    bool isTorrentEnable() const;
    bool isDirectDownloadEnable() const;
   
    friend class FinderController;

    bool _torrentIsEnable, _ddlIsEnable;
};


#endif // FINDERSMEMENTO_H
