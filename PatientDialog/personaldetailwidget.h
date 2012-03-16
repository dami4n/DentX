/**
  * PersonalDetailWidget
  * Widget służący do wprowadzania danych osobowych pacjenta
 */

#ifndef PERSONALDETAILWIDGET_H
#define PERSONALDETAILWIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QLineEdit>
#include <QRadioButton>
#include "patient.h"

class QGroupBox;
class QLabel;


class PersonalDetailWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PersonalDetailWidget(QWidget *parent = 0);

    // akcesory
    QString getId() { return idLineEdit->text(); }
    QString getName() { return nameLineEdit->text(); }
    QString getLastName() { return lastNameLineEdit->text(); }
    QString getCity() { return cityLineEdit->text(); }
    QString getZipCode() { return zipCodeLineEdit->text(); }
    QString getStreet() { return streetLineEdit->text(); }
    QString getStreetNumber() { return streetNumberLineEdit->text(); }
    QString getApartmentNumber() { return apartmentNumberLineEdit->text(); }
    QString getPesel() { return peselLineEdit->text(); }
    QString getPhone() { return phoneLineEdit->text(); }
    QDateTime getRegistrationDate() { return registrationDate; }
    bool maleIsChecked() { return maleRadioButton->isChecked(); }

    /**
      * Metoda ustawia widget jako edytowalny/nieedytowalny
      * @param void
      * @return void
      */
    void setEditable(bool value);

    /**
      * Metoda wczytuje do widgetu dane z pacjenta
      * @param void
      * @return void
      */
    void setPatient(Patient patient);

private:

    /**
      * Metoda tworzy główny layout widgetu
      * @param void
      * @return void
      */
    void createLayout();


    /**
      * Metoda tworzy GUI widgetu związane z adresem
      * @param void
      * @return void
      */
    void createAddress();


    /**
      * Metoda tworzy GUI widgetu związane z płcią
      * @param void
      * @return void
      */
    void createGender();

    /**
      * Metoda tworzy GUI widgetu związane z danymi osobowymi
      * @param void
      * @return void
      */
    void createPersonalDetail();


    /**
      * Metoda tworzy GUI widgetu związane z pozostałymi danymi osobowymi
      * @param void
      * @return void
      */
    void createOthersInformation();

    QGroupBox *addressGroupBox;
    QGroupBox *personalDetailsGroupBox;
    QGroupBox *genderGroupBox;
    QGroupBox *othersInformationGroupBox;

    QLabel *idLabel;
    QLabel *nameLabel;
    QLabel *secondNameLabel;
    QLabel *lastNameLabel;
    QLabel *cityLabel;
    QLabel *zipCodeLabel;
    QLabel *streetLabel;
    QLabel *streetNumberLabel;
    QLabel *apartmentNumberLabel;
    QLabel *peselLabel;
    QLabel *phoneLabel;
    QLabel *registrationDateLabel;

    QRadioButton *maleRadioButton;
    QRadioButton *femaleRadioButton;

    QLineEdit *idLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *secondNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *cityLineEdit;
    QLineEdit *zipCodeLineEdit;
    QLineEdit *streetLineEdit;
    QLineEdit *streetNumberLineEdit;
    QLineEdit *apartmentNumberLineEdit;
    QLineEdit *peselLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *registrationDateLineEdit;

    QDateTime registrationDate;

};

#endif // PERSONALDETAILWIDGET_H
