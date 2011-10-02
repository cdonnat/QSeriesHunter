#ifndef MEMENTOCONTROLLER_H
#define MEMENTOCONTROLLER_H

#include <QString>

class ISeriesController;
class FinderSelection;

class MementoController
{
public:

    //----------------------------------------------------------------------------------------------
    MementoController(ISeriesController * const series,
                      FinderSelection   * const finders,
                      const QString &           absoluteFilePath);

    // Commands :

    //----------------------------------------------------------------------------------------------
    void loadMemento ();

    //----------------------------------------------------------------------------------------------
    void saveMemento ();

private:
    ISeriesController  * const _series;
    FinderSelection    * const _finders;
    QString                    _initFile;
};

#endif // MEMENTOCONTROLLER_H
