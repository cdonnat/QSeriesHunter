#ifndef TST_EDITSERIE_H
#define TST_EDITSERIE_H

#include <QObject>

class SeriesModel;
class EditSerie;
class MessageBoxStub;
class EditSerieDialogStub;

class TestEditSerie : public QObject
{
    Q_OBJECT

public:
    TestEditSerie();

private Q_SLOTS:
    void testAdd ();
    void testRemove ();

private:
    void testAddRobustness (const QString & name,
                            const QString & season,
                            const QString & lastEpisode,
                            const QString & comment);

private:
    EditSerieDialogStub * _editDialog;
    SeriesModel         * _series;
    MessageBoxStub      * _message;
    EditSerie           * _sut;
};

#endif // TST_EDITSERIE_H
