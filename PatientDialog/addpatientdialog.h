#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include "patient.h"

class PersonalDetailWidget;
class AdditionalInformationWidget;
class ExaminationWidget;
class QTabWidget;
class QPushButton;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;

class AddPatientDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddPatientDialog(QWidget *parent = 0);

    /**
      * Publiczna metoda umożliwiająca pobranie pacjenta, który
      * został stworzony przy użyciu klasy AddPatientDialog
      * @param void
      * @return Patient
      */
    Patient getPatient() { return *patient; }

private slots:
    /**
      * Slot wywoływany przy akceptacji dodania pacjenta
      * Sprawdza on poprawność wprowadzonych danych
      * @param void
      * @return void
      */
    void okClicked();

protected:
    /**
      * Metoda tworzy nowego pacjenta
      * @param void
      * @return void
      */
    void createPatient();

    /**
      * Metoda sprawdza poprawność wprowadzonego numeru PESEL
      * @param QString
      * @return bool
      */
    bool checkPesel(QString pesel);

    /**
      * Metoda tworzy GUI związane z zakładkami
      * @param void
      * @return void
      */
    void createTabs();

    /**
      * Metoda tworzy główny layout dialogu
      * @param void
      * @return void
      */
    void createLayout();

    void createImageLabel();
    void createButtons();

    QTabWidget *tabWidget;

    QPushButton *okButton;
    QPushButton *cancelButton;

    PersonalDetailWidget *personalDetailWidget;
    AdditionalInformationWidget *additionalInformationWidget;
    ExaminationWidget *examinationWidget;

    QLabel *userImageLabel;

    QVBoxLayout *mainLayout;


    Patient *patient;

     int id;

};

#endif // ADDPATIENTDIALOG_H
