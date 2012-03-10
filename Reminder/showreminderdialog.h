/**
  * ShowNoteDialog
  * Klasa odpowiedzialna za wyświetlenie dialogu notatki
  */

#ifndef SHOWREMINDERDIALOG_H
#define SHOWREMINDERDIALOG_H

#include <QDialog>
#include "reminder.h"

class ReminderWidget;
class QPushButton;

class ShowReminderDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ShowReminderDialog(QWidget *parent = 0);

    /**
      * Kontruktor klasy ShowRemindertDialog ustawiający wartość pól dialogu
      * @param Reminder, QWidget
      * @return void
      */
    ShowReminderDialog(Reminder reminder, QWidget *parent = 0);

    /**
      * Metoda ustawiająca wartości pól dialogu z przypomnienia
      * @param Reminder
      * @return void
      */
    void setReminder(Reminder reminder);

    /**
      * Metoda ustawiająca wartości pól dialogu z przypomnienia
      * @param QString, QString, QString, QString
      * @return void
      */
    void setReminder(QString topic, QString text,
                     QString dateReminder, QString priority);

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


    ReminderWidget *reminderWidget; /*!< Edytor przypomnienia */

    QPushButton *okButton; /*!< Przycisk OK */
    QPushButton *cancelButton; /*!< Przycisk Anuluj */




};

#endif // SHOWREMINDERDIALOG_H
