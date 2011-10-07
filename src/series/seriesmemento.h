#ifndef SERIESMEMENTO_H
#define SERIESMEMENTO_H

#include <QList>
#include "serie.h"

class QDataStream;

namespace YAML {
    class Emitter;
    class Node;
}

class SeriesMemento
{
public:
    //----------------------------------------------------------------------------------------------
    // REQ [None.]
    // ENS [Last save memento is returned. An empty memento is returned if none are found.]
    static SeriesMemento loadFromStream(QDataStream & o);
    
    //----------------------------------------------------------------------------------------------
    static SeriesMemento loadFromNode(const YAML::Node & node);
    
    //----------------------------------------------------------------------------------------------
    friend YAML::Emitter & operator<< (YAML::Emitter& out, const SeriesMemento memento);
    
private:
    //----------------------------------------------------------------------------------------------
    SeriesMemento(const QList<Serie> & series);

    //----------------------------------------------------------------------------------------------
    const QList<Serie> & get () const;

    friend class SeriesController;

    QList<Serie>  _save;
};


#endif // SERIESMEMENTO_H
