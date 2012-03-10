#include <QtGui>
#include "Database/database.h"
#include "Note/note.h"
#include "Note/notefunction.h"
#include "patient.h"

#include "demo.h"

Demo::Demo(QObject *parent) :
    QObject(parent)
{
}

void Demo::createExampleUser()
{
    Database database;

    Patient newPatient;
    newPatient.name = "Jan";
    newPatient.lastName = "Kowalski";
    newPatient.PESEL = "76012157218";
    newPatient.phone = "600123456";
    newPatient.city = "Warszawa";
    newPatient.street = "Przykladowa";
    newPatient.house = "25a";
    newPatient.apartment = "3";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient);

    Patient newPatient2;
    newPatient2.name = "Marek";
    newPatient2.lastName = "Nowak";
    newPatient2.PESEL = "96012119810";
    newPatient2.phone = "789456654";
    newPatient2.city = "Poznań";
    newPatient2.street = "Dworcowa";
    newPatient2.house = "212";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient2);

    Patient newPatient3;
    newPatient3.name = "Mirek";
    newPatient3.lastName = "Wiśniewski";
    newPatient3.PESEL = "90062536654";
    newPatient3.phone = "521458796";
    newPatient3.city = "Wrocław";
    newPatient3.street = "Przemysłowa";
    newPatient3.house = "3";
    newPatient3.apartment = "5";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient3);

    Patient newPatient4;
    newPatient4.name = "Ania";
    newPatient4.lastName = "Wójcik";
    newPatient4.PESEL = "86012187810";
    newPatient4.phone = "693125698";
    newPatient4.city = "Gdynia";
    newPatient4.street = "Mickiewicza";
    newPatient4.house = "45";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient4);

    Patient newPatient5;
    newPatient5.name = "Mariusz";
    newPatient5.lastName = "Lewandowski";
    newPatient5.PESEL = "89050427711";
    newPatient5.phone = "600896589";
    newPatient5.city = "Olsztyn";
    newPatient5.street = "Mostowa";
    newPatient5.house = "12";
    newPatient5.apartment = "2";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient5);

    Patient newPatient6;
    newPatient6.name = "Krystyna";
    newPatient6.lastName = "Kowalczyk";
    newPatient6.PESEL = "91012156616";
    newPatient6.phone = "789458745";
    newPatient6.city = "Poznań";
    newPatient6.street = "Stołowa";
    newPatient6.house = "21";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient6);

    Patient newPatient7;
    newPatient7.name = "Tomasz";
    newPatient7.lastName = "Zieliński";
    newPatient7.PESEL = "66012129212";
    newPatient7.phone = "78052145";
    newPatient7.city = "Zakopane";
    newPatient7.street = "Alejowa";
    newPatient7.house = "3";
    newPatient7.apartment = "4";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient7);

    Patient newPatient8;
    newPatient8.name = "Katarzyna";
    newPatient8.lastName = "Kozłowska";
    newPatient8.PESEL = "79050493719";
    newPatient8.phone = "54785587";
    newPatient8.city = "Piła";
    newPatient8.street = "Klonowa";
    newPatient8.house = "25";
    newPatient.registrationDate = QDateTime::currentDateTime();
    database.addPatient(newPatient8);
}

void Demo::createExampleNote()
{
    NoteFunction noteFunction;

    Note note;
    note.dateAdded = QDateTime::currentDateTime().addDays(-3).toString();
    note.topic = "Wyczyścić unit";
    note.text = "To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    note.textHtml = "<h1><font color='red'>To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    noteFunction.addNoteToDatabase(note);

    Note note2;
    note2.dateAdded = QDateTime::currentDateTime().addDays(-3).toString();
    note2.topic = "Włączyć autoklaw";
    note2.text = "To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    note2.textHtml = "<h1><font color='red'>To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    noteFunction.addNoteToDatabase(note2);

    Note note3;
    note3.dateAdded = QDateTime::currentDateTime().addDays(-3).toString();
    note3.topic = "Wyrzucić odpady medyczne";
    note3.text = "To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    note3.textHtml = "<h1><font color='red'>To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    noteFunction.addNoteToDatabase(note3);

    Note note4;
    note4.dateAdded = QDateTime::currentDateTime().addDays(-30).toString();
    note4.topic = "Zadzwonić do J.Kowalskiego";
    note4.text = "To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    note4.textHtml = "<h1><font color='red'>To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    noteFunction.addNoteToDatabase(note4);

    Note note5;
    note5.dateAdded = QDateTime::currentDateTime().addDays(-30).toString();
    note5.topic = "Przygotować zestawy";
    note5.text = "To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    note5.textHtml = "<h1><font color='red'>To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    noteFunction.addNoteToDatabase(note5);

    Note note6;
    note6.dateAdded = QDateTime::currentDateTime().toString();
    note6.topic = "Kupić wodę";
    note6.text = "To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    note6.textHtml = "<h1><font color='red'>To jest jakiś przypadkowy, długi tekst notatki."
                "Zapytanie SQL ucina ten tekst po 20 znakach";
    noteFunction.addNoteToDatabase(note6);

}
