#include "patient.h"
#include <QStringBuilder>
#include <QString>

Patient::Patient()
{

}

QString Patient::getAddress() const
{
    QString address = street % " " % house;

    if(! apartment.isEmpty() )
    {
        address.append("/");
        address.append(apartment);
    }

    return address;
}

QMap<QString, QString> Patient::getPatientData() const
{
    QMap<QString, QString> map;

    map.insert("name ", name); /*!< Imię */
    map.insert("lastName", lastName); /*!< Nazwisko */
    map.insert("PESEL", PESEL ); /*!< PESEL  */
    map.insert("city", city ); /*!< Miasto zamieszkania */
    map.insert("street", street); /*!< Nazwa ulicy  */
    map.insert("house", house); /*!< Numer domu  */
    map.insert("zipCode", zipCode); /*!< Kod pocztowy  */
    map.insert("apartment", apartment ); /*!< Numer mieszkania */
    map.insert("phone", phone); /*!< Numer telefonu */
    map.insert("address", address ); /*!< Adres */
    map.insert("pharmaceuticals", pharmaceuticals ); /*!< Przyjmowane leki */
    map.insert("allergy", allergy); /*!< Alergie */
    map.insert("disorders", disorders ); /*!< Choroby */
    map.insert("note",note ); /*!< Informacje dodatkowe */
    map.insert("registrationDate", registrationDate.toString() ); /*!< Data rejestracji */
    map.insert("dentalArticulation", dentalArticulation ); /*!< Zgryz */
    map.insert("joint", joint ); /*!< Staw skroniowo - żuchwowy*/
    map.insert("exposure", exposure ); /*!<  Narażenia tkanek zmineralizowanych */
    map.insert("color", color ); /*!< Kolor */
    map.insert("efflorescencePre", efflorescencePre); /*!< Wykwity pierwotne */
    map.insert("efflorescenceSec", efflorescenceSec); /*!< Wykwity wtórne */
    map.insert("morfologicalChanges", morfologicalChanges); /*!< Ogniskowe zmiany morfologiczne */
    map.insert("tongue", tongue); /*!< Nalot na języku */
    map.insert("morfologicalDisorder", morfologicalDisorder ); /*!< Zaburzenia morfologiczne zębów  */
    map.insert("ohi", ohi); /*!< Współczynnik OHI */
    map.insert("pli", pli ); /*!< Współczynnik PLI */
    map.insert("api", api); /*!< Współczynnik AI */
    map.insert("salivaS", salivaS); /*!< Ilość śliny stymulowanej */
    map.insert("salivaNS", salivaNS); /*!< Ilość śliny niestymulowanej */
    map.insert("id", QString::number(id));

    return map;
}

void Patient::setMap(const QMap<QString, QString>& patientMap)
{
    name = patientMap["name"];
    lastName = patientMap["lastname"];
    PESEL = patientMap["pesel"];
    city = patientMap["city"];
    street= patientMap["street"];
    house= patientMap["house"];
    zipCode = patientMap["zipCode"];
    apartment= patientMap["apartment"];
    phone= patientMap["phone"];
    address = patientMap["address"];
    pharmaceuticals = patientMap["pharmaceuticals"];
    allergy= patientMap["allergy"];
    disorders = patientMap["disorders"];
    note = patientMap["note"];
    registrationDate= QDateTime::fromString(patientMap["registrationDate"]);
    dentalArticulation= patientMap["dentalArticulation"];
    joint = patientMap["joint"];
    exposure = patientMap["exposure"];
    color = patientMap["color"];
    efflorescencePre= patientMap["efflorescencePre"];
    efflorescenceSec= patientMap["efflorescenceSec"];
    morfologicalChanges= patientMap["morfologicalChanges"];
    tongue= patientMap["tongue"];
    morfologicalDisorder= patientMap["morfologicalDisorder"];
    ohi= patientMap["ohi"];
    pli = patientMap["pli"];
    api= patientMap["api"];
    salivaS= patientMap["salivaS"];
    salivaNS= patientMap["salivaNS"];
    id = patientMap["id"].toInt();

    getAddress();
    this->patientMap = patientMap;
}

QString Patient::getValue(const QString &value) const
{
    return patientMap[value];
}

QString Patient::insertValue(const QString &key, const QString &value)
{
    patientMap.insert(key, value);
}
