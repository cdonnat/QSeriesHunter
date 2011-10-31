#include "seriesmodel.h"
#include "seriescontroller.h"
#include <QDate>

const int NB_COLUMNS               = 8;
const int COLUMN_ACTIVE            = 0;
const int COLUMN_NAME              = 1;
const int COLUMN_SEASON            = 2;
const int COLUMN_EPISODE           = 3;
const int COLUMN_LAST_EPISODE      = 4;
const int COLUMN_LAST_EPISODE_DATE = 5;
const int COLUMN_NEXT_EPISODE      = 6;
const int COLUMN_NEXT_EPISODE_DATE = 7;

//----------------------------------------------------------------------------------------------
SeriesModel::SeriesModel (SeriesProvider * seriesProvider, 
                          const QDate &    currentDate,          
                          QObject        * parent) : QAbstractTableModel(parent)
{
    Q_ASSERT(seriesProvider);
    _series = new SeriesController(seriesProvider, currentDate);
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

    Serie  current = at (index.row ());
    switch (role)
    {
        case Qt::DisplayRole :
            switch (index.column ())
            {
                case COLUMN_NAME              : return current.name();
                case COLUMN_SEASON            : return tr("Season %1").arg(current.season());
                case COLUMN_EPISODE           : return getLastEpisodeDl(current);
                case COLUMN_LAST_EPISODE      : return getLastAiredEpisode(current);
                case COLUMN_LAST_EPISODE_DATE : return getLastAiredEpisodeDate(current);
                case COLUMN_NEXT_EPISODE      : return getNextAiredEpisode(current);
                case COLUMN_NEXT_EPISODE_DATE : return getNextAiredEpisodeDate(current);
                default                       : break;
            }
            break;
        case Qt::CheckStateRole :
            if (index.column() == COLUMN_ACTIVE){
                return current.isEnable() ? Qt::Checked : Qt::Unchecked;
            }
            break;
         
        case Qt::TextAlignmentRole :
            if (index.column() >= COLUMN_SEASON && index.column() <= COLUMN_NEXT_EPISODE_DATE){
               return Qt::AlignCenter;
            }
            break;
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
            case COLUMN_ACTIVE            : return tr("State");
            case COLUMN_NAME              : return tr("Name");
            case COLUMN_SEASON            : return tr("Season");
            case COLUMN_EPISODE           : return tr("Last Episode Downloaded");
            case COLUMN_LAST_EPISODE      : return tr("Last Aired Episode");
            case COLUMN_LAST_EPISODE_DATE : return tr("Last Aired Episode Date");
            case COLUMN_NEXT_EPISODE      : return tr("Next Aired Episode");
            case COLUMN_NEXT_EPISODE_DATE : return tr("Next Aired Episode Date");
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

//----------------------------------------------------------------------------------------------
bool SeriesModel::aNewEpisodeIsAvailable(const Serie & serie) const
{
    return _series->aNewEpisodeIsAvailable(serie);
}

//----------------------------------------------------------------------------------------------
bool SeriesModel::nextAiredEpisodeDetailsAreAvailable(const Serie & serie) const
{
    return _series->nextAiredEpisodeDetailsAreAvailable(serie);
}

//----------------------------------------------------------------------------------------------
bool SeriesModel::lastAiredEpisodeDetailsAreAvailable(const Serie & serie) const
{
    return _series->lastAiredEpisodeDetailsAreAvailable(serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesModel::lastAiredEpisode(const Serie & serie) const
{
    Q_ASSERT(lastAiredEpisodeDetailsAreAvailable(serie));
    return _series->lastAiredEpisode(serie);
}

//----------------------------------------------------------------------------------------------
QDate SeriesModel::lastAiredEpisodeDate(const Serie & serie) const
{
    Q_ASSERT(lastAiredEpisodeDetailsAreAvailable(serie));
    return _series->lastAiredEpisodeDate(serie);
}

//----------------------------------------------------------------------------------------------
uint SeriesModel::nextAiredEpisode(const Serie & serie) const
{
    Q_ASSERT(nextAiredEpisodeDetailsAreAvailable(serie));
    return _series->nextAiredEpisode(serie);
}

//----------------------------------------------------------------------------------------------
QDate SeriesModel::nextAiredEpisodeDate(const Serie & serie) const
{
    Q_ASSERT(nextAiredEpisodeDetailsAreAvailable(serie));
    return _series->nextAiredEpisodeDate(serie);
}

//----------------------------------------------------------------------------------------------
QString toEpisode(uint episode) 
{
    return QObject::tr("Episode %1").arg(episode);
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::getLastEpisodeDl(const Serie & serie)        const
{
    return serie.lastEpisode() == 0? tr("None") : toEpisode(serie.lastEpisode());
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::getLastAiredEpisode(const Serie & serie)     const
{
    return lastAiredEpisodeDetailsAreAvailable(serie)?
            toEpisode(lastAiredEpisode(serie)) : tr("Unknown");
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::getLastAiredEpisodeDate(const Serie & serie) const
{
    return lastAiredEpisodeDetailsAreAvailable(serie)? 
            lastAiredEpisodeDate(serie).toString() : QVariant(tr("Unknown"));
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::getNextAiredEpisode(const Serie & serie)     const
{
    return nextAiredEpisodeDetailsAreAvailable(serie)? 
            toEpisode(nextAiredEpisode(serie)) : tr("Unknown");

}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::getNextAiredEpisodeDate(const Serie & serie) const
{
    return nextAiredEpisodeDetailsAreAvailable(serie)? 
            nextAiredEpisodeDate(serie).toString() : tr("Unknown");

}
