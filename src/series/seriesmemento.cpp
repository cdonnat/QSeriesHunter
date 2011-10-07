#include "seriesmemento.h"

#include <QDataStream>
#include <QFile>
#include <QDir>
#include <QString>

#include <string>
#include "yaml-cpp/yaml.h"

//----------------------------------------------------------------------------------------------
SeriesMemento::SeriesMemento(const QList<Serie> & series): _save(series)
{
}

//----------------------------------------------------------------------------------------------
const QList<Serie> & SeriesMemento::get () const
{
    return _save;
}

//----------------------------------------------------------------------------------------------
QDataStream & operator>> (QDataStream & dataStream, Serie & serie)
{
    QString name;
    uint    season;
    uint    episode;
    dataStream >> name;
    dataStream >> season;
    dataStream >> episode;
    serie = Serie(name, season, episode);
    return dataStream;
}

//----------------------------------------------------------------------------------------------
SeriesMemento SeriesMemento::loadFromStream(QDataStream & dataStream)
{
    QList<Serie>  series;
    dataStream >> series;
    return SeriesMemento(series);
}

void operator >> (const YAML::Node & node, Serie & serie)
{
    std::string    name;
    uint           season, episode;
    bool           isEnable;
    node["Name"]    >> name;
    node["Season"]  >> season;
    node["Episode"] >> episode;
    node["Enable"]  >> isEnable;
    //
    serie = Serie(name.c_str(), season, episode, isEnable);
}

//----------------------------------------------------------------------------------------------
SeriesMemento SeriesMemento::loadFromNode(const YAML::Node & node)
{
    QList<Serie>        series;
    const YAML::Node  & seriesSeq = node["Series"];
    
    for (unsigned i = 0; i < seriesSeq.size(); ++i)
    {
       Serie serie;
       seriesSeq[i] >> serie;
       series << serie;
    }         
    return SeriesMemento(series);
}


//----------------------------------------------------------------------------------------------
YAML::Emitter & operator<< (YAML::Emitter& out, const Serie& serie)
{
    out << YAML::BeginMap;
    out << YAML::Key << "Name" << YAML::Value << serie.name().toStdString();
    out << YAML::Key << "Season" << YAML::Value << serie.season();
    out << YAML::Key << "Episode" << YAML::Value << serie.lastEpisode();
    out << YAML::Key << "Enable" << YAML::Value << serie.isEnable();
    out << YAML::EndMap;
    return out;
}

//----------------------------------------------------------------------------------------------
YAML::Emitter & operator<< (YAML::Emitter& out, const SeriesMemento memento)
{
    out << YAML::BeginMap;
    out << YAML::Key << "Series";
    out << YAML::Value << memento._save.toStdList();
    out << YAML::EndMap;
    return out;
}
