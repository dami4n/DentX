/**
  * ShowNoteDialog
  * Klasa odpowiedzialna za wyświetlenie dialogu notatki
  */

#ifndef SHOWNOTEDIALOG_H
#define SHOWNOTEDIALOG_H

#include <QDialog>
#include "note.h"

class NoteWidget;
class QPushButton;

class ShowNoteDialog : public QDialog
{
    Q_OBJECT
public:
    /**
      * Kontruktor klasy ShowPatientDialog
      * @param QWidget
      * @return void
      */
    explicit ShowNoteDialog(QWidget *parent = 0);

    /**
      * Kontruktor klasy ShowPatientDialog ustawiający wartość pól dialogu
      * @param Note, QWidget
      * @return void
      */
    ShowNoteDialog(Note note, QWidget *parent = 0);

    /**
      * Metoda ustawiająca notatkę dialogu
      * @param Note
      * @return void
      */
    void setNote(Note note);

    /**
      * Metoda ustawiająca notatkę dialogu
      * @param QString, QString
      * @return void
      */
    void setNote(QString topic, QString text);

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

#endif // SHOWNOTEDIALOG_H
