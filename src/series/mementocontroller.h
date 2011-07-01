#ifndef MEMENTOCONTROLLER_H
#define MEMENTOCONTROLLER_H

#include <QString>

class ISeriesController;

class MementoController
{
public:

    //----------------------------------------------------------------------------------------------
    MementoController(ISeriesController * const series,
                      const QString &           absoluteFilePath);

    // Commands :

    //----------------------------------------------------------------------------------------------
    void loadMemento ();

    //----------------------------------------------------------------------------------------------
    void saveMemento ();

private:
    ISeriesController  * const _series;
    QString                    _initFile;
};

#endif // MEMENTOCONTROLLER_H
