#ifndef TST_SERIE_H
#define TST_SERIE_H

#include <QObject>

class Serie;

class TestSerie : public QObject
{
    Q_OBJECT
public:
    TestSerie(QObject *parent = 0);

private Q_SLOTS:
    void testCase();
    void testOperators ();

private :
    Serie    * sut;
};

#endif // TST_SERIE_H
