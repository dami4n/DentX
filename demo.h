/**
  * Demo
  * Klasa dodająca przykładowych pacjentów itp.
  */

#ifndef DEMO_H
#define DEMO_H

#include <QObject>

class Demo : public QObject
{
    Q_OBJECT
public:
    explicit Demo(QObject *parent = 0);

    /**
      * Metoda tworzy przykłądowych pacjentów i dodaje ich do bazy danych
      * @param void
      * @return void
      */
    void createExampleUser();

    /**
      * Metoda tworzy przykłądowe notatki
      * @param void
      * @return void
      */
    void createExampleNote();

};

#endif // DEMO_H
