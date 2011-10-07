#ifndef MEMENTOCONTROLLER_H
#define MEMENTOCONTROLLER_H

#include <QString>

class ISeriesController;
class EditFinder;
class QFile;

class MementoController
{
public:

    //----------------------------------------------------------------------------------------------
    MementoController(ISeriesController * const series,
                      EditFinder        * const finders,
                      const QString &           absoluteFilePathWithoutExtension);

    // Commands :

    //----------------------------------------------------------------------------------------------
    void loadMemento ();

    //----------------------------------------------------------------------------------------------
    void saveMemento ();

private:
    
    void readOldIniFileAndDeleteIt(QFile & iniFile);
    
    ISeriesController  * const _series;
    EditFinder         * const _finders;
    QString                    _yamlFile;
    QString                    _iniFile;
};

#endif // MEMENTOCONTROLLER_H
