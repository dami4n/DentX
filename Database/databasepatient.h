#ifndef DATABASEPATIENT_H
#define DATABASEPATIENT_H

#include <QObject>
#include <QMap>
#include <QList>

typedef QMap<QString, QString> PatientRecord;
typedef QMapIterator<QString, QString> PatientRecordIterator;

class QSqlQuery;

class DatabasePatient : public QObject
{
    Q_OBJECT
public:
    explicit DatabasePatient(QObject *parent = 0);

    /**
     * Metoda zwraca wszystkich pacjentów z bazy danych
     * @param void
     * @return QList< QMap<QString, QString> >
     **/
    QList< QMap<QString, QString> > getPatientTable() const;

    /**
     * Metoda zwraca pacjenta na którego aktualnie wskazuje sqlQuery
     * @param void
     * @return QMap<QString,QString>
     **/
    QMap<QString,QString> getPatient() const;

    /**
     * Metoda zwraca wszystkich pacjenta z bazy danych o wybranym ID
     * @param void
     * @return QMap<QString, QString>
     **/
    QMap<QString, QString> getPatientById(const QString& id) const;

    /**
     * Metoda sprawdza czy są jeszcze pacjenci do zwrócenia (sqlQuery.next())
     * @param void
     * @return bool
     **/
    bool next();

private:
     QSqlQuery *sqlQuery;

    /**
     * Metoda inicjalizuje sqlQuery
     * @param void
     * @return void
     **/
    void activate();
};

#endif // DATABASEPATIENT_H
