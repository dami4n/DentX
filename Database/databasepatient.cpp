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

