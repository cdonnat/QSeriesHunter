#ifndef SERIESMODEL_H
#define SERIESMODEL_H

#include <QAbstractTableModel>
#include <QDate>
#include <QVariant>

#include "seriesmemento.h"
#include "iseriescontroller.h"

class QDate;
class SeriesProvider;
class Serie;

class SeriesModel : public QAbstractTableModel, public ISeriesController
{
    Q_OBJECT
    
public:
    // Constructor
    SeriesModel(SeriesProvider * seriesProvider, 
                const QDate    & currentDate,
                QObject        * parent = 0);

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
    
    //----------------------------------------------------------------------------------------------
    virtual bool aNewEpisodeIsAvailable(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual bool nextAiredEpisodeDetailsAreAvailable(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual bool lastAiredEpisodeDetailsAreAvailable(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual uint lastAiredEpisode(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual QDate lastAiredEpisodeDate(const Serie & serie) const;

    //----------------------------------------------------------------------------------------------
    virtual uint nextAiredEpisode(const Serie & serie) const;
    
    //----------------------------------------------------------------------------------------------
    virtual QDate nextAiredEpisodeDate(const Serie & serie) const;

    // Commands:
    
    //----------------------------------------------------------------------------------------------
    virtual bool setData(const QModelIndex & index,const QVariant & value, int role = Qt::EditRole); 
    
    //----------------------------------------------------------------------------------------------
    virtual void addSerie (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void removeSerie (const Serie & serie);
    
    //----------------------------------------------------------------------------------------------
    virtual void setLastEpisode (const Serie & serie);

    //----------------------------------------------------------------------------------------------
    virtual void inc (const Serie & serie);
    
    //----------------------------------------------------------------------------------------------
    virtual void enable (const Serie & serie, bool isEnable);
    
    //----------------------------------------------------------------------------------------------
    virtual void loadFrom (const SeriesMemento &memento);

signals:
    void seriesChanged();
    
private:
    ISeriesController  * _series;
    
    QVariant getLastEpisodeDl(const Serie & serie)        const;
    QVariant getLastAiredEpisode(const Serie & serie)     const;
    QVariant getLastAiredEpisodeDate(const Serie & serie) const;
    QVariant getNextAiredEpisode(const Serie & serie)     const;
    QVariant getNextAiredEpisodeDate(const Serie & serie) const;
    
};

#endif // SERIESMODEL_H
