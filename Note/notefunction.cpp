#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QStringBuilder>
#include <QVariant>
#include "note.h"

#include "notefunction.h"

NoteFunction::NoteFunction(QObject *parent) :
    QObject(parent)
{
}


int NoteFunction::addNoteToDatabase(const QString topic, const QString text,
                                    const QString textHtml)
{
    QSqlQuery query;
    query.prepare("INSERT INTO note (dateAdded, topic, text, textHtml, dateSQL )"
                    "VALUES (:dateAdded, :date, :topic, :text, :textHtml, dateSQL)");

    query.bindValue(":dateAdded", QDateTime::currentDateTime().toString());
    query.bindValue(":topic", topic);
    query.bindValue(":text", text);
    query.bindValue(":textHtml", textHtml);
    query.bindValue(":dateSQL", QDateTime::currentDateTime().toString("yyyy-MM-dd"));

    bool value = query.exec();    

    if( !value )
    {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }

    emit changed();

    return 1;
}

int NoteFunction::addNoteToDatabase(Note note)
{
    QSqlQuery query;
    query.prepare("INSERT INTO note (dateAdded, topic, text, textHtml, dateSQL )"
                    "VALUES (:dateAdded, :topic, :text, :textHtml, :dateSQL)"
                    );

    query.bindValue(":dateAdded", note.dateAdded);
    query.bindValue(":topic", note.topic);
    query.bindValue(":text", note.text);
    query.bindValue(":textHtml", note.textHtml);
    query.bindValue(":dateSQL", QDateTime::fromString(note.dateAdded).toString("yyyy-MM-dd"));

    bool value = query.exec();

    if( !value )
    {
        qDebug() << "addNoteToDatabase error";
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }

    qDebug() << "Dodaje";

    emit changed();

    return 1;
}

QList<Note> NoteFunction::getNote(const QString &date) const
{
    // dopracować to zapytanie, żeby działało na jakiś funkcjach
    // z SQLite i operowało na datach a nie porównywało dwa stringi

    QList<Note> notesList;

    QSqlQuery query;
    QString queryString = "SELECT * FROM note "
                          "WHERE date"
                          " = '" % date % "'";

    query.exec(queryString);

    //qDebug() << query.lastQuery();

    while(query.next())
    {
        Note note;
        note.id = query.value(0).toInt();
        note.dateAdded = query.value(1).toString();
        note.topic = query.value(3).toString();
        note.text = query.value(4).toString();
        note.textHtml = query.value(5).toString();

        notesList << note;
    }

    return notesList;
}

QList<Note> NoteFunction::getNote() const
{
    QList<Note> notesList;

    QSqlQuery query;
    QString queryString = "SELECT * FROM note ";

    query.exec(queryString);

    //qDebug() << query.lastQuery();

    while(query.next())
    {
        Note note;
        note.id = query.value(0).toInt();
        note.dateAdded = query.value(1).toString();
        note.topic = query.value(3).toString();
        note.text = query.value(4).toString();
        note.textHtml = query.value(5).toString();

        notesList << note;
    }

    return notesList;
}

