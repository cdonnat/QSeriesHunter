#ifndef EDITFINDER_H
#define EDITFINDER_H

class IEditFinderWidget;
class FinderController;
class FindersMemento;

class EditFinder
{
public:

    //----------------------------------------------------------------------------------------------
    explicit EditFinder(FinderController  * const finderController,
                        IEditFinderWidget * const editFinderWidget);

    
    // Commands:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Enable or disable torrent finder.]
    void enableTorrent (bool isEnable);

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Enable or disable direct download finder.]
    void enableDirectDownload (bool isEnable);

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Finder types are loaded from memento.]
    void loadFrom (const FindersMemento & memento);
    
    // Queries:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Memento is returned.]
    FindersMemento createMemento() const;
    
private:
    IEditFinderWidget  * const _editFinderWidget;
    FinderController   * const _finderController;
};

#endif // EDITFINDER_H
