#ifndef MEMENTOCONTROLLER_H
#define MEMENTOCONTROLLER_H

#include <QString>

class ISeriesController;
class EditFinder;

class MementoController
{
public:

    //----------------------------------------------------------------------------------------------
    MementoController(ISeriesController * const series,
                      EditFinder        * const finders,
                      const QString &           absoluteFilePath);

    // Commands :

    //----------------------------------------------------------------------------------------------
    void loadMemento ();

    //----------------------------------------------------------------------------------------------
    void saveMemento ();

private:
    ISeriesController  * const _series;
    EditFinder         * const _finders;
    QString                    _initFile;
};

#endif // MEMENTOCONTROLLER_H
