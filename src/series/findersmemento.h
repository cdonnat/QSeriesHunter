#ifndef FINDERSMEMENTO_H
#define FINDERSMEMENTO_H

namespace YAML {
    class Emitter;
    class Node;
}

class FindersMemento
{
public:        
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last save memento is returned.]
    static FindersMemento loadFromNode(const YAML::Node & node);

    //----------------------------------------------------------------------------------------------
    friend YAML::Emitter & operator<<(YAML::Emitter & out, const FindersMemento & memento);
    
private:
  
    //----------------------------------------------------------------------------------------------
    FindersMemento(bool torrentIsEnable, bool ddlIsEnable);

    bool isTorrentEnable() const;
    bool isDirectDownloadEnable() const;
   
    friend class FinderController;

    bool _torrentIsEnable, _ddlIsEnable;
};


#endif // FINDERSMEMENTO_H
