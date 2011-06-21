#include "seriesmodel.h"
#include "seriescontroller.h"

const int NB_COLUMNS     = 3;
const int COLUMN_NAME    = 0;
const int COLUMN_SEASON  = 1;
const int COLUMN_EPISODE = 2;

//----------------------------------------------------------------------------------------------
SeriesModel::SeriesModel (QObject *parent) : QAbstractTableModel(parent)
{
    _series = new SeriesController();
}

//----------------------------------------------------------------------------------------------
int SeriesModel::rowCount (const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return nbSeries();
}

//----------------------------------------------------------------------------------------------
int SeriesModel::columnCount (const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return NB_COLUMNS;
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::data (const QModelIndex &index, int role) const
{
    if (!index.isValid ()) return QVariant();

    if (role == Qt::DisplayRole)
    {
        Serie  current = _series->at (index.row ());
        switch (index.column ())
        {
        case COLUMN_NAME    : return current.name();
        case COLUMN_SEASON  : return current.season();
        case COLUMN_EPISODE : return _series->lastEpisodeDl(current);
        default             : break;
        }
    }
    return QVariant();
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::headerData (int              section,
                                  Qt::Orientation  orientation,
                                  int              role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case COLUMN_NAME    : return tr("Name");
            case COLUMN_SEASON  : return tr("Season");
            case COLUMN_EPISODE : return tr("Last Episode Downloaded");
            default             : break;
        }
    }
    return QVariant();
}

//----------------------------------------------------------------------------------------------
bool SeriesModel::contains (const Serie & serie) const
{
    return _series->contains (serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesModel::nbSeries () const
{
    return _series->nbSeries ();
}

//----------------------------------------------------------------------------------------------
SeriesMemento SeriesModel::createMemento () const
{
    return _series->createMemento ();
}

//----------------------------------------------------------------------------------------------
const Serie & SeriesModel::at (uint index) const
{
    return _series->at (index);
}

//----------------------------------------------------------------------------------------------
uint SeriesModel::lastEpisodeDl (const Serie & serie) const
{
    return _series->lastEpisodeDl (serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesModel::nextEpisode (const Serie & serie) const
{
    return _series->nextEpisode (serie);
}

//----------------------------------------------------------------------------------------------
void SeriesModel::addSerie (const Serie & serie, uint episode)
{
    beginResetModel ();
    _series->addSerie (serie, episode);
    endResetModel ();
}

//----------------------------------------------------------------------------------------------
void SeriesModel::removeSerie (const Serie & serie)
{
    beginResetModel ();
    _series->removeSerie (serie);
    endResetModel ();
}

//----------------------------------------------------------------------------------------------
void SeriesModel::inc (const Serie & serie)
{
    _series->inc (serie);
}

//----------------------------------------------------------------------------------------------
void SeriesModel::loadFrom (const SeriesMemento &memento)
{
    _series->loadFrom (memento);
}
