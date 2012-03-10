/**
  * Note
  * Klasa reprezentująca pojedyńczą notatkę
  */

#ifndef NOTE_H
#define NOTE_H

#include <QDate>
#include <QString>

class Note
{
public:
    explicit Note();

    int id; /*!< Unikalny identyfikator notatki */
    QString dateAdded; /*!< Data dodanie notatki */
    QString topic; /*!< Temat notatki */
    QString text; /*!< Treść notatki */
    QString textHtml; /*!< Treść notatki(html) */
};

#endif // NOTE_H
