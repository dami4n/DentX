/**
  * AddNoteDialog
  * Klasa odpowiedzialna za wyświetlenie dialogu umożliwiającego
  * dodanie nowej notatki.
  *
*/

#ifndef ADDNOTEDIALOG_H
#define ADDNOTEDIALOG_H

#include <QDialog>
#include "note.h"

class NoteWidget;
class QPushButton;

class AddNoteDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddNoteDialog(QWidget *parent = 0);

    /**
      * Metoda zwracająca notatkę
      * @param void
      * @return Note
      */
    Note getNote() const;

private slots:
    /**
      * Slot sprawdzający czy wymagane pola są uzupełnione
      * @param void
      * @return void
      */
    void okClicked();

private:
    /**
      * Metoda odpowiedzialna za stworzenie GUI dialogu.
      * @param void
      * @return void
      */
    void createGui();

    /**
      *Tworzy layout dialogu
      * @param void
      * @return void
      */
    void createLayout();

    NoteWidget *noteWidget; /*!< Edytor tekstu */

    QPushButton *okButton; /*!< Przycisk OK */
    QPushButton *cancelButton; /*!< Przycisk Anuluj */

};

#endif // ADDNOTEDIALOG_H
