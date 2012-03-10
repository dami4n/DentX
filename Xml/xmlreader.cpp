#include <QFile>
#include <QXmlStreamReader>
#include <QSqlQuery>
#include <QDebug>
#include "patient.h"
#include "xmlreader.h"

XmlReader::XmlReader(QObject *parent) :
    QObject(parent)
{
}

int XmlReader::readPatientsFromXML(const QString fileName)
{
    QFile file(fileName);

    if( !file.open(QIODevice::ReadOnly))
    {
        qDebug() << qPrintable(file.errorString());
        return -1;
    }

    QXmlStreamReader xml(&file);
    xml.readNextStartElement();

    if( xml.name() != "Dentx")
        return -2;

    xml.readNextStartElement();
    xml.readNextStartElement();

    while( !xml.atEnd() )
    {
        Patient patient;

        patient.name = xml.readElementText(); xml.readNextStartElement(); qDebug() << xml.name();
        patient.lastName = xml.readElementText(); xml.readNextStartElement(); qDebug() << xml.name();
        patient.PESEL = xml.readElementText(); xml.readNextStartElement(); qDebug() << xml.name();
        patient.city = xml.readElementText(); xml.readNextStartElement(); qDebug() << xml.name();
        patient.street = xml.readElementText(); xml.readNextStartElement(); qDebug() << xml.name();
        patient.house = xml.readElementText(); xml.readNextStartElement(); qDebug() << xml.name();
        patient.zipCode = xml.readElementText(); xml.readNextStartElement(); qDebug() << xml.name();
        patient.apartment = xml.readElementText(); xml.readNextStartElement();
        patient.phone = xml.readElementText(); xml.readNextStartElement();
        patient.dentalArticulation = xml.readElementText(); xml.readNextStartElement();
        patient.joint = xml.readElementText(); xml.readNextStartElement();
        patient.exposure = xml.readElementText(); xml.readNextStartElement();
        patient.color = xml.readElementText(); xml.readNextStartElement();
        patient.efflorescencePre = xml.readElementText(); xml.readNextStartElement();
        patient.efflorescenceSec = xml.readElementText(); xml.readNextStartElement();
        patient.morfologicalChanges = xml.readElementText(); xml.readNextStartElement();
        patient.tongue = xml.readElementText(); xml.readNextStartElement();
        patient.morfologicalDisorder = xml.readElementText(); xml.readNextStartElement();
        patient.ohi = xml.readElementText(); xml.readNextStartElement();
        patient.pli = xml.readElementText(); xml.readNextStartElement();
        patient.api = xml.readElementText(); xml.readNextStartElement();
        patient.salivaS = xml.readElementText(); xml.readNextStartElement();
        patient.salivaNS = xml.readElementText(); xml.readNextStartElement();

        xml.readNextStartElement();
        xml.readNextStartElement();
    }

    return 0;
}
