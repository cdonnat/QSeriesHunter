#ifndef MEMENTOCONTROLLER_H
#define MEMENTOCONTROLLER_H

#include <QString>

class ISeriesController;
class FinderController;

class MementoController
{
public:

    //----------------------------------------------------------------------------------------------
    MementoController(ISeriesController * const series,
                      FinderController  * const finders,
                      const QString &           absoluteFilePath);

    // Commands :

    //----------------------------------------------------------------------------------------------
    void loadMemento ();

    //----------------------------------------------------------------------------------------------
    void saveMemento ();

private:
    ISeriesController  * const _series;
    FinderController   * const _finders;
    QString                    _initFile;
};

#endif // MEMENTOCONTROLLER_H
