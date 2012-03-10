/**
  * AddReminderDialog
  * Klasa odpowiedzialna za wyświetlenie dialogu umożliwiającego
  * dodanie nowego przypomnienia.
  *
*/

#ifndef ADDREMINDERDIALOG_H
#define ADDREMINDERDIALOG_H

#include <QDialog>
#include "reminder.h"

class ReminderWidget;
class QPushButton;

class AddReminderDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddReminderDialog(QWidget *parent = 0);

    /**
      * Metoda zwracająca przypomnienie
      * @param void
      * @return Reminder
      */
    Reminder getReminder() const;

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

    ReminderWidget *reminderWidget;

    QPushButton *okButton; /*!< Przycisk OK */
    QPushButton *cancelButton; /*!< Przycisk Anuluj */

};

#endif // ADDREMINDERDIALOG_H
