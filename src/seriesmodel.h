#ifndef SERIESMODEL_H
#define SERIESMODEL_H

#include <QAbstractTableModel>

#include "seriescontroller.h"

class Serie;

class SeriesModel : public QAbstractTableModel
{
public:
    // Constructor
    SeriesModel(QObject *parent = 0);

    // Queries:

    //----------------------------------------------------------------------------------------------
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;

    //----------------------------------------------------------------------------------------------
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //----------------------------------------------------------------------------------------------
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    //----------------------------------------------------------------------------------------------
    virtual QVariant headerData(int              section,
                                Qt::Orientation  orientation,
                                int              role = Qt::DisplayRole) const;

    //----------------------------------------------------------------------------------------------
    uint nbSeries () const;

    //----------------------------------------------------------------------------------------------
    const Serie & at (uint index) const;

    // Commands:

    //----------------------------------------------------------------------------------------------
    void addSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    void removeSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    void inc (const Serie & serie);

private:
    SeriesController  _series;
};

#endif // SERIESMODEL_H
