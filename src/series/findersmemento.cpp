#include "findersmemento.h"

#include "yaml-cpp/yaml.h"

//----------------------------------------------------------------------------------------------
FindersMemento::FindersMemento(bool torrentIsEnable, bool ddlIsEnable):
_torrentIsEnable(torrentIsEnable), _ddlIsEnable(ddlIsEnable)
{
}

//----------------------------------------------------------------------------------------------
bool FindersMemento::isTorrentEnable() const
{
    return _torrentIsEnable;
}

//----------------------------------------------------------------------------------------------
bool FindersMemento::isDirectDownloadEnable() const
{
    
    return _ddlIsEnable;
}

//----------------------------------------------------------------------------------------------
FindersMemento FindersMemento::loadFromNode(const YAML::Node & node)
{
    const YAML::Node & findersNode = node["Finders"];
    bool  torrentIsEnable, ddlIsEnable;
    findersNode["Torrent"]        >> torrentIsEnable;
    findersNode["DirectDownload"] >> ddlIsEnable;
    return FindersMemento(torrentIsEnable, ddlIsEnable);
 }

//----------------------------------------------------------------------------------------------
YAML::Emitter & operator<<(YAML::Emitter & out, const FindersMemento & memento)
{
    out << YAML::BeginMap;
    out << YAML::Key << "Finders";
    out << YAML::Value;
    out << YAML::BeginMap;
    out << YAML::Key << "Torrent";
    out << YAML::Value << memento.isTorrentEnable();
    out << YAML::Key << "DirectDownload";
    out << YAML::Value << memento.isDirectDownloadEnable();
    out << YAML::EndMap;
    return out;
}
