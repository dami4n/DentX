#ifndef PATIENTS_H
#define PATIENTS_H

#include <QObject>
#include <QList>
#include <QMap>


class Patients : public QObject
{
    Q_OBJECT
public:
    explicit Patients(QObject *parent = 0);
    bool next();

private:
    bool connect();

    QList< QMap<QString, QString> > allPatients; /*!< Przechowuje wszystkich pacjentów */


};

#endif // PATIENTS_H
