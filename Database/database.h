/**
  * Database
  * Klasa odpowiedzialna za stworzenie bazy danych SQL
  */

#ifndef Database_H
#define Database_H

#include <QString>
#include "patient.h"

class Preferences;

class Database
{
public:
    /**
      * Konstruktor klasy Database
      * @param void
      * @return void
      */
    Database();

    /**
      * Metoda tworząca baze danych
      * @param void
      * @return int
      */
    int createDatabase();

    /**
      * Metoda tworzy tabele 'patients', która przechowuje dane pacjentów
      * @param void
      * @return int
      */
    int createTablePatinets();

    /**
      * Metoda tworzy tabele 'note', która przechowuje notatki
      * @param void
      * @return int
      */
    int createTableNote();

    /**
      * Metoda tworzy tabele 'reminder', która przechowuje przypomnienia
      * @param void
      * @return int
      */
    int createTableReminder();

    /**
      * Metoda tworzy tabele 'history', która przechowuje historię pacjentów
      * @param void
      * @return int
      */
    int createTableHistory();

    /**
      * Metoda tworzy tabele 'TeethDescription', która przechowuje opis zębów
      * @param void
      * @return int
      */
    int createTableTeethDescription();


    /**
      * Metoda tworzy tabele 'timesheet', która przechowuje wizyty pacjentów
      * @param void
      * @return int
      */
    int createTableTimesheet();

    /**
      * Metoda dodaje nowego pacjenta do tabeli patient
      * @param Patient
      * @return int
      */
    int addPatient(const Patient patient);

private:
    Preferences *preferences;
     int type;
};

#endif // DATABASE_H
