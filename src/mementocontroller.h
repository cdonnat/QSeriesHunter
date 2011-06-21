#ifndef MEMENTOCONTROLLER_H
#define MEMENTOCONTROLLER_H

class ISeriesController;

class MementoController
{
public:
    //----------------------------------------------------------------------------------------------
    MementoController(ISeriesController * series);

    // Commands :

    //----------------------------------------------------------------------------------------------
    void loadMemento ();

    //----------------------------------------------------------------------------------------------
    void saveMemento ();

private:
    ISeriesController  * _series;
};

#endif // MEMENTOCONTROLLER_H
