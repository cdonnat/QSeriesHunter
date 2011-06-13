#include "seriesmodel.h"

#include <QDebug>

const int NB_COLUMNS = 3;

//----------------------------------------------------------------------------------------------
SeriesModel::SeriesModel(QObject *parent):QAbstractTableModel(parent)
{
}

//----------------------------------------------------------------------------------------------
int SeriesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return nbSeries();
}

//----------------------------------------------------------------------------------------------
int SeriesModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return NB_COLUMNS;
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        switch (index.column ())
        {
        case 0 : return _series.at(index.row ()).name();
        case 1 : return _series.at(index.row ()).season();
        case 2 : return _series.at(index.row ()).lastEpisodeDownloaded();
        default : break;
        }
    }
    return QVariant();
}

//----------------------------------------------------------------------------------------------
QVariant SeriesModel::headerData(int              section,
                                 Qt::Orientation  orientation,
                                 int              role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:  return tr("Name");
            case 1:  return tr("Season");
            case 2:  return tr("Last Episode Downloaded");
            default: break;
        }
    }
    return QVariant();
}

//----------------------------------------------------------------------------------------------
uint SeriesModel::nbSeries () const
{
    return _series.nbSeries ();
}

//----------------------------------------------------------------------------------------------
const Serie & SeriesModel::at (uint index) const
{
    return _series.at (index);
}

//----------------------------------------------------------------------------------------------
void SeriesModel::addSerie (const Serie & serie)
{
    beginInsertRows (QModelIndex(), _series.nbSeries (), _series.nbSeries ());
    _series.addSerie (serie);
    endInsertRows ();
}

//----------------------------------------------------------------------------------------------
void SeriesModel::removeSerie (const Serie & serie)
{
    beginRemoveRows (QModelIndex(), _series.nbSeries (), _series.nbSeries ());
    _series.removeSerie (serie);
    endRemoveRows ();
}

void SeriesModel::inc (const Serie & serie)
{
    _series.inc (serie);
}
