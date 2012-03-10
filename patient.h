/**
  * Patient
  * Klasa reprezentująca pacjenta
  */

#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDateTime>
#include <QMap>


class Patient
{
public:
    Patient();

    QString name; /*!< Imię */
    QString lastName; /*!< Nazwisko */
    QString PESEL; /*!< PESEL  */
    QString city; /*!< Miasto zamieszkania */
    QString street; /*!< Nazwa ulicy  */
    QString house; /*!< Numer domu  */
    QString zipCode; /*!< Kod pocztowy  */
    QString apartment; /*!< Numer mieszkania */
    QString phone; /*!< Numer telefonu */
    QString address; /*!< Adres */

    QString pharmaceuticals; /*!< Przyjmowane leki */
    QString allergy; /*!< Alergie */
    QString disorders; /*!< Choroby */
    QString note; /*!< Informacje dodatkowe */

    QDateTime registrationDate; /*!< Data rejestracji */

    QString dentalArticulation; /*!< Zgryz */
    QString joint; /*!< Staw skroniowo - żuchwowy*/
    QString exposure; /*!<  Narażenia tkanek zmineralizowanych */
    QString color; /*!< Kolor */
    QString efflorescencePre; /*!< Wykwity pierwotne */
    QString efflorescenceSec; /*!< Wykwity wtórne */
    QString morfologicalChanges; /*!< Ogniskowe zmiany morfologiczne */
    QString tongue; /*!< Nalot na języku */
    QString morfologicalDisorder; /*!< Zaburzenia morfologiczne zębów  */
    QString ohi; /*!< Współczynnik OHI */
    QString pli; /*!< Współczynnik PLI */
    QString api; /*!< Współczynnik AI */
    QString salivaS; /*!< Ilość śliny stymulowanej */
    QString salivaNS; /*!< Ilość śliny niestymulowanej */

    enum { MALE, FEMALE }; /*!< Stałe określające płeć pacjenta */
    int gender; /*!< Płeć pacjenta */

    /**
      * Metoda 'sklejająca' adres do jednego stringa
      * @param void
      * @return QString
      */
    QString getAddress() const;
    QMap<QString, QString> getPatientData() const;

    int id; /*!< ID pacjenta */
};
#endif // PATIENT_H
