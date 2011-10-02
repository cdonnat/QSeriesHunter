#ifndef TST_FINDERSELECTION_H
#define TST_FINDERSELECTION_H

#include <QObject>

class FinderSelection;
class FinderController;
class FinderSelectionWidgetStub;

class TestFinderSelection : public QObject
{
    Q_OBJECT

public:
    TestFinderSelection();

private Q_SLOTS:
    void testNominal ();

private:
    FinderSelectionWidgetStub * _finderWidgetStub;
    FinderController          * _finderController;
    FinderSelection           * _sut;
};

#endif // TST_FINDERSELECTION_H
