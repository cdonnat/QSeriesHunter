#include <QtTest>

#include "mainwindow.h"
#include "tst_mainwindow.h"

TestMainWindow::TestMainWindow()
{
    this->_sut = new MainWindow;
}

TestMainWindow::~TestMainWindow()
{
    delete this->_sut;
}

void TestMainWindow::testCase()
{
    TestMainWindow fixture;

}
