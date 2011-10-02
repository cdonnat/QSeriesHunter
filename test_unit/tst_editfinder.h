#ifndef TST_EDITFINDER_H
#define TST_EDITFINDER_H

#include <QObject>

class EditFinder;
class FinderController;
class EditFinderWidgetStub;

class TestEditFinder : public QObject
{
    Q_OBJECT

public:
    TestEditFinder();

private Q_SLOTS:
    void testNominal ();

private:
    EditFinderWidgetStub      * _editFinderWidgetStub;
    FinderController          * _finderController;
    EditFinder                * _sut;
};

#endif // TST_EDITFINDER_H
