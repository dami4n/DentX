/**
  * ReminderWidget
  * Widget służący do wprowadzania/wyświetlania przypomnienia
  */

#ifndef REMINDERWIDGET_H
#define REMINDERWIDGET_H

#include <QWidget>
#include "reminder.h"

class Editor;
class QLabel;
class QLineEdit;
class QDateTimeEdit;
class QComboBox;


class ReminderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReminderWidget(QWidget *parent = 0);

     Reminder getReminder();

    /**
      * Metoda wczytująca przypomnienie
      * @param Reminder
      * @return void
      */
    void setReminder(Reminder reminder);

    /**
      * Metoda wczytująca przypomnienie
      * @param QString, QString, QString, QString
      * @return void
      */
    void setReminder(QString topic, QString text, QString date, QString priority);

    /**
      * Metoda pozwalająca ustawić pola jako edytowalne/nieedytowalne
      * @param bool
      * @return void
      */
    void setEditable(bool value);

    /**
      * Metoda ustawia dateLineEdit aktualną date
      * @param void
      * @return void
      */
    void setToday();

    /**
      * Metoda zwraca temat przypomnienia
      * @param void
      * @return QString
      */
    QString getTopic();
    QString getReminderDate();

private:
    /**
      * Metoda odpowiedzialna za stworzenie GUI widgetu.
      * @param void
      * @return void
      */
    void createGui();

    /**
      *Tworzy layout widgetu
      * @param void
      * @return void
      */
    void createLayout();

    /**
      *Tworzy kalendarz
      * @param void
      * @return void
      */
    void createCalendar();

    QLabel *reminderTextLabel; /*!< Etykieta 'Treść' */
    QLabel *reminderTopicLabel; /*!< Etykieta 'Temat' */
    QLabel *dateLabel; /*!< Etykieta 'Data' */
    QLabel *priorityLabel; /*!< Etykieta 'Priorytet' */
    QLabel *dateReminderLabel; /*!< Etykieta 'Data przypomnienia' */
    QLineEdit *topicLineEdit; /*!< Temat przypomnienia */
    QLineEdit *dateLineEdit; /*!< Treść przypomnienia */
    QDateTimeEdit *dateTimeEdit; /*!< Data przypomnienia */
    QComboBox *priorityComboBox; /*!< Priorytet przypomnienia */

    Editor *editor; /*!< Edytor tekstu */



};

#endif // REMINDERWIDGET_H
