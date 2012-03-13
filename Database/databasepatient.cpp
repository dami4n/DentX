#include <QtSql>
#include <QDebug>
#include <QStringBuilder>
#include "databasepatient.h"
#include "patient.h"

DatabasePatient::DatabasePatient(QObject *parent) :
    QObject(parent)
{
    activate();
}

void DatabasePatient::activate()
{
    sqlQuery = new QSqlQuery("SELECT * FROM patient");
}

bool DatabasePatient::next()
{
    return sqlQuery->next();
}

QList< QMap<QString, QString> > DatabasePatient::getPatientTable() const
{
    QList< QMap<QString, QString> > patientsMap;
    QSqlQuery query("SELECT * FROM patient");

    while( query.next() )
    {
        QSqlRecord rec = query.record();
        QMap<QString, QString> tmp;
        for( int i = 0; i < rec.count(); ++i)
        {
            tmp[rec.fieldName(i)] = rec.value(i).toString();
        }
        patientsMap << tmp;
    }
    return patientsMap;
}

QMap<QString, QString> DatabasePatient::getPatient() const
{
    QMap<QString, QString> tmp;
    QSqlRecord rec = sqlQuery->record();

    for( int i = 0; i < rec.count(); ++i)
    {
        tmp[rec.fieldName(i)] = rec.value(i).toString();
    }

    return tmp;
}

QMap<QString, QString> DatabasePatient::getPatientById(const QString& id) const
{
    QSqlQuery query("SELECT * FROM patient WHERE id = '" % id % "'");

    QSqlRecord rec;
    if( query.next() )
        rec = query.record();

    QMap<QString, QString> tmp;
    for( int i = 0; i < rec.count(); ++i)
       tmp[rec.fieldName(i)] = rec.value(i).toString();

    return tmp;
}

int DatabasePatient::addPatient(QMap<QString, QString> patientMap)
{
    qDebug() << "Adding new patient...";

    QString queryStart = "INSERT INTO patient (";
    QString queryEnd = ") VALUES (";

    QMapIterator<QString, QString> i(patientMap);
    while (i.hasNext())
    {
        i.next();
        if( i.hasNext() )
        {
            queryStart = queryStart % i.key() % ", " ;
            queryEnd = queryEnd % ":" % i.key() % ", ";
        }
        else
        {
            queryStart = queryStart % i.key();
            queryEnd = queryEnd % ":" % i.key();
        }
    }

    QSqlQuery query;
    query.prepare(queryStart % queryEnd % ");");
    i.toFront();

    while (i.hasNext())
    {
        i.next();
        query.bindValue(i.key(), i.value());
    }

    bool value = query.exec();

    if( !value )
    {
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
        return -1;
    }

    emit patientAdded();

    return 0;
}

int DatabasePatient::updatePatient(QMap<QString, QString> patientMap)
{
    qDebug() << "Adding new patient...";

    QString query = "UPDATE patient SET ";


    QMapIterator<QString, QString> i(patientMap);
    while (i.hasNext())
    {
        i.next();
        if( i.hasNext() )
            query = query % i.key() % "= '" % i.value() % "', ";
        else
            query = query % i.key() % "= '" % i.value() % "' ";
    }

    query = query % " WHERE id = '" % patientMap["id"] % "';";

    qDebug() << query;

    QSqlQuery q;
    bool value = q.exec(query);

    if( !value )
    {
        qDebug() << q.lastQuery();
        qDebug() << q.lastError();
        return -1;
    }

    return 0;
}

