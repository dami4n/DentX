#include "Database/databasepatient.h"

#include "patients.h"

Patients::Patients(QObject *parent) :
    QObject(parent)
{
    DatabasePatient databasePatient;
    allPatients = databasePatient.getPatientTable();
}


