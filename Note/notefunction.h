/**
  * NoteFunction
  * Klasa odpowiedzialna za funckje związane z notatkami:
  * dodawanie, odczytywanie notatek z bazy danych
  */

#ifndef NOTEFUNCTION_H
#define NOTEFUNCTION_H

#include <QDateTime>
#include <QObject>
#include <QString>
#include <QMap>
#include "note.h"

class NoteFunction : public QObject
{
    Q_OBJECT
public:
    explicit NoteFunction(QObject *parent = 0);

    /**
      * Metoda dodaje notatkę do bazy danych
      * @param QString, QString, QString
      * @return int
      */
    int addNoteToDatabase(const QString topic, const QString text = 0,
                          const QString textHtml = 0);

    /**
      * Metoda dodaje notatkę do bazy danych
      * @param Note
      * @return int
      */
    int addNoteToDatabase(Note note);

    /**
      * Metoda zwraca notatki z danego dnia
      * @param QDateTime
      * @return QList<Note>
      */
    QList<Note> getNote(const QString &date) const;

    /**
      * Metoda zwraca wszystkie dodane notatki
      * @param void
      * @return QList<Note>
      */
    QList<Note> getNote() const;


signals:
    /**
      * Sygnał emitowany gdy tabela w bazie została zmodyfikowana
      * @param void
      * @return void
      */
    void changed();
};

#endif // NOTEFUNCTION_H

