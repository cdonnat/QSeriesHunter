#ifndef TST_MAINWINDOWN_H
#define TST_MAINWINDOWN_H

#include <QObject>

class MainWindow;

class TestMainWindow : public QObject
{
    Q_OBJECT

public:
    TestMainWindow();
    virtual ~TestMainWindow();

private Q_SLOTS:
    void testCase();

private :
    MainWindow    * _sut;
};

#endif // TST_MAINWINDOWN_H
