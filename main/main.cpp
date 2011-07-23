#include <QApplication>
#include <QIcon>
#include <QTableView>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow  m;
    m.setWindowIcon(QIcon(":/QSeriesHunter.png"));
    m.show ();

    return app.exec ();
}
