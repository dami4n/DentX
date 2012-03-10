#include <QApplication>
#include <QDateTime>
#include "addnotedialog.h"
#include "notewidget.h"
#include "shownotedialog.h"
#include "noteviewer.h"
#include "note.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Note note;
    note.dateAdded = QDateTime::currentDateTime().toString();
    note.topic = "Nowa notatka";
    note.text = "Jakis tam prosty tekst";

    NoteViewer a;
    a.show();

    return app.exec();
}
