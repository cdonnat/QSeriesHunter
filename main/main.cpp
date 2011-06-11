#include <QApplication>

#include <QTableView>
#include "seriesmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTableView     view;
    SeriesModel    model;

    view.setModel (&model);
    model.addSerie (Serie("House", 1, 22, 1));
    view.show ();

    return app.exec ();
}
