#ifndef FINDERSELECTION_H
#define FINDERSELECTION_H

class IFinderSelectionWidget;
class FinderController;
class FindersMemento;

class FinderSelection
{
public:

    //----------------------------------------------------------------------------------------------
    explicit FinderSelection(FinderController       * const finderController,
                             IFinderSelectionWidget * const finderSelectionWidget);

    
    // Commands:
    
    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Enable or disable torrent finder.]
    void enableTorrent (bool isEnable);

    //----------------------------------------------------------------------------------------------
    // REQ [None]
    // ENS [Enable or disable direct download finder.]
    void enableDirectDownload (bool isEnable);

    void loadFrom (const FindersMemento & memento);
    
    // Queries:
    
    FindersMemento createMemento() const;
    
private:
    IFinderSelectionWidget  * const _finderSelectionWidget;
    FinderController        * const _finderController;
};

#endif // FINDERSELECTION_H
