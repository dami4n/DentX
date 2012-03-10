#include <QFile>
#include <QXmlStreamWriter>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QStringBuilder>
#include <QMapIterator>
#include "Database/databasepatient.h"

#include "xmlwriter.h"

XmlWriter::XmlWriter(QObject *parent) :
    QObject(parent)
{
}

int XmlWriter::writePatientsToXmlFile(QString fileName)
{
    QFile file(fileName);
    if( !file.open(QIODevice::WriteOnly))
    {
        qDebug() << qPrintable(file.errorString());
        return -1;
    }

    DatabasePatient patient;

    QXmlStreamWriter xml(&file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement( "DentX" );

    while( patient.next() )
    {
        xml.writeStartElement( "patient" );

        PatientRecord patRec = patient.getPatient();
        PatientRecordIterator patientRecIter(patRec);

        while( patientRecIter.hasNext() )
        {
            patientRecIter.next();
            xml.writeTextElement( patientRecIter.key(), patientRecIter.value() );
        }

        xml.writeEndElement();
    }

    xml.writeEndDocument();
    xml.writeEndDocument();

    return 0;
}

int XmlWriter::writePatientByIdToXmlFile(QString id, QString fileName)
{
    QFile file(fileName);
    if( !file.open(QIODevice::WriteOnly))
    {
        qDebug() << qPrintable(file.errorString());
        return -1;
    }

    DatabasePatient patient;

    QXmlStreamWriter xml(&file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement( "Dentix" );
    xml.writeStartElement( "patient" );

    PatientRecord patRec = patient.getPatientById(id);
    PatientRecordIterator patientRecIter(patRec);

    while( patientRecIter.hasNext() )
    {
        patientRecIter.next();
        xml.writeTextElement( patientRecIter.key(), patientRecIter.value() );
    }

    xml.writeEndElement();
    xml.writeEndDocument();
    xml.writeEndDocument();

    return 0;
}
