#include "tst_editserie.h"

#include <QTest>

#include "serie.h"
#include "editserie.h"
#include "seriesmodel.h"
#include "stub_editseriedialog.h"
#include "stub_messagebox.h"

TestEditSerie::TestEditSerie()
{
    _editDialog = new EditSerieDialogStub();
    _series     = new SeriesModel();
    _message    = new MessageBoxStub();
    _sut        = new EditSerie(_editDialog, _series, _message);
}

void TestEditSerie::testAdd ()
{
    TestEditSerie fixture;
    fixture._editDialog->setup (false, "House", "1", "2");
    fixture._sut->add ();
    QVERIFY2(!fixture._series->contains (Serie("House", 1)), "Serie not added");
    QVERIFY2(!fixture._message->displayWarningIsCalled (), "Warning not called");
    //
    fixture._editDialog->setup (true, "dr  house", "1", "2");
    fixture._sut->add ();
    QVERIFY2(fixture._series->contains (Serie("Dr House", 1)), "Serie added - 1");
    QVERIFY2(fixture._series->lastEpisodeDl (Serie("Dr House", 1)) == 2, "Serie added - 2");
    //
    fixture._sut->add ();
    QVERIFY2(fixture._message->displayWarningIsCalled (), "Warning called");
    //
    testAddRobustness ("", "1", "1", "Robustness when no name");
    testAddRobustness ("Toto", "", "1", "Robustness when no season");
    testAddRobustness ("Toto", "1", "", "Robustness when no episode");
}

void TestEditSerie::testAddRobustness (const QString & name,
                                       const QString & season,
                                       const QString & lastEpisode,
                                       const QString & comment)
{
    _message->clear ();
    _editDialog->setup (true, name, season, lastEpisode);
    _sut->add ();
    QVERIFY2(_message->displayWarningIsCalled (), comment.toStdString ().c_str ());
  }

void TestEditSerie::testRemove ()
{
    TestEditSerie fixture;
    fixture._editDialog->setup (true, "dr  house", "1", "2");
    fixture._sut->add ();
    fixture._editDialog->setup (true, "dr  house", "2", "6");
    fixture._sut->add ();
    fixture._editDialog->setup (true, "himym","5", "3");
    fixture._sut->add ();

    fixture._sut->remove (fixture._series->index (2, 2));
    fixture._sut->remove (fixture._series->index (0,0));

    QVERIFY2(fixture._series->nbSeries () == 1, "Only one serie left");
    QVERIFY2(fixture._series->contains (Serie("Dr House", 2)), "Only series in list have been removed");

    fixture._sut->remove (QModelIndex());
    QVERIFY2(fixture._message->displayWarningIsCalled (), "Warning called");
}
