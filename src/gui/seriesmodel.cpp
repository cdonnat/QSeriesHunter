#include "seriesmodel.h"
#include "seriescontroller.h"
#include <QIcon>

const int NB_COLUMNS     = 4;
const int COLUMN_ACTIVE  = 0;
const int COLUMN_NAME    = 1;
const int COLUMN_SEASON  = 2;
const int COLUMN_EPISODE = 3;

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
Qt::ItemFlags SeriesModel::flags (const QModelIndex & index) const
{
    if (index.column() == COLUMN_ACTIVE) {
        return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsUserCheckable;
    }
    else {
        return Qt::ItemIsEnabled|Qt::ItemIsSelectable;
    }
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::data (const QModelIndex &index, int role) const
{
    if (!index.isValid ()) return QVariant();

    Serie  current = _series->at (index.row ());
    switch (role)
    {
        case Qt::DisplayRole :
            switch (index.column ())
            {
                case COLUMN_NAME    : return current.name();
                case COLUMN_SEASON  : return current.season();
                case COLUMN_EPISODE : return current.lastEpisode();
                default             : break;
            }
            break;
        case Qt::CheckStateRole :
            if (index.column() == COLUMN_ACTIVE){
                return current.isEnable() ? Qt::Checked : Qt::Unchecked;
            }
        default : break;
    }
    return QVariant();
}

//----------------------------------------------------------------------------------------------
bool SeriesModel::setData(const QModelIndex & index,const QVariant & value, int role) 
{
    if (!index.isValid()) return false;
    
    if (role == Qt::CheckStateRole && index.column() == COLUMN_ACTIVE)
    {
        Serie current = at(index.row());
        enable(current, value.toBool());
        emit seriesChanged();
        return true;
    }
    return false;
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
            case COLUMN_ACTIVE  : return tr("State");
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
void SeriesModel::addSerie (const Serie & serie)
{
    beginResetModel ();
    _series->addSerie (serie);
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
    beginResetModel ();
    _series->inc (serie);
    endResetModel ();
}

//----------------------------------------------------------------------------------------------
void SeriesModel::enable (const Serie & serie, bool isEnable)
{
    beginResetModel ();
    _series->enable (serie, isEnable);
    endResetModel ();
}

//----------------------------------------------------------------------------------------------
void SeriesModel::loadFrom (const SeriesMemento &memento)
{
    _series->loadFrom (memento);
}
