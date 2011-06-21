#ifndef SERIESMODEL_H
#define SERIESMODEL_H

#include <QAbstractTableModel>

#include "seriesmemento.h"
#include "iseriescontroller.h"

class Serie;

class SeriesModel : public ISeriesController, public QAbstractTableModel
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
    virtual bool contains (const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual const Serie & at(uint index) const;

    //----------------------------------------------------------------------------------------------
    virtual uint lastEpisodeDl (const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual uint nextEpisode (const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual uint nbSeries () const;

    //----------------------------------------------------------------------------------------------
    virtual SeriesMemento createMemento () const;

    // Commands:

    //----------------------------------------------------------------------------------------------
    virtual void addSerie (const Serie & serie, uint episode = 0);

    //----------------------------------------------------------------------------------------------
    virtual void removeSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void inc (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void loadFrom (const SeriesMemento &memento);

private:
    ISeriesController  * _series;
};

#endif // SERIESMODEL_H
