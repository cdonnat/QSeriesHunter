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
    virtual Qt::ItemFlags flags (const QModelIndex & index) const;
    
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
    virtual uint nbSeries () const;

    //----------------------------------------------------------------------------------------------
    virtual SeriesMemento createMemento () const;

    // Commands:
    
    //----------------------------------------------------------------------------------------------
    virtual bool setData(const QModelIndex & index,const QVariant & value, int role = Qt::EditRole); 
    
    //----------------------------------------------------------------------------------------------
    virtual void addSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void removeSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void inc (const Serie & serie);
    
    //----------------------------------------------------------------------------------------------
    virtual void enable (const Serie & serie, bool isEnable);
    
    //----------------------------------------------------------------------------------------------
    virtual void loadFrom (const SeriesMemento &memento);

private:
    ISeriesController  * _series;
};

#endif // SERIESMODEL_H
