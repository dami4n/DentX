/**
  * NoteWidget
  * Widget służący do wprowadzania/wyświetlania notatki
  */

#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include "note.h"

class Editor;
class QLabel;
class QLineEdit;

class NoteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NoteWidget(QWidget *parent = 0);

    Note getNote();

    /**
      * Metoda wczytująca notatkę
      * @param Note
      * @return void
      */
    void setNote(Note note);

    /**
      * Metoda wczytująca notatkę
      * @param QString, QString
      * @return void
      */
    void setNote(QString topic, QString text);

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
      * Metoda zwraca temat notatki
      * @param void
      * @return QString
      */
    QString getTopic();

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

    QLabel *noteTextLabel; /*!< Etykieta 'Treść' */
    QLabel *noteTopicLabel; /*!< Etykieta 'Temat' */
    QLabel *dateLabel; /*!< Etykieta 'Data' */
    QLineEdit *topicLineEdit; /*!< Temat notatki */
    QLineEdit *dateLineEdit; /*!< Treść notatki */

    Editor *editor; /*!< Edytor tekstu */

};

#endif // NOTEWIDGET_H
