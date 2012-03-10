/**
  * XmlReader
  * Klasa odpowiadająca za wczytywanie pacjentów z pliku XML
  */

#ifndef XMLREADER_H
#define XMLREADER_H

#include <QObject>

class XmlReader : public QObject
{
    Q_OBJECT
public:
    explicit XmlReader(QObject *parent = 0);

    /**
      * Metoda wczytuje pacjentów z pliku XML
      * @param QString
      * @return int
      */
    int readPatientsFromXML(const QString fileName);
};

#endif // XMLREADER_H
