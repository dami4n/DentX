/**
  * XmlWriter
  * Klasa pozwalająca zapisywac baze danych pacjentów do pliku XML
  */

#ifndef XMLWRITER_H
#define XMLWRITER_H

#include <QObject>
#include <QString>

class XmlWriter : public QObject
{
    Q_OBJECT
public:
    explicit XmlWriter(QObject *parent = 0);

    /**
      * Metoda zapisuje baze pacjentów do pliku
      * @param QString
      * @return int
      */
    int writePatientsToXmlFile(QString fileName);

    /**
     * Metoda zapisuje do pliku XML pacjenta o zadanym ID
     * @param QString, QString
     * @return int
     */
    int writePatientByIdToXmlFile(QString id, QString fileName);


signals:

public slots:

};

#endif // XMLWRITER_H
