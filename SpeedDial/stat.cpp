#include <QtGui>
#include <QSqlQuery>
#include <QSqlRecord>
#include "stat.h"


Stat::Stat(QWidget *parent) :
    QWidget(parent)
{
    getStat();
    createGui();
    createLayout();

}


void Stat::createGui()
{
    statGrouBox = new QGroupBox( tr("Statystyki") );

    patientsNumberLabel = new QLabel( tr("<h4>Liczba pacjentów zapisanych w bazie danych: <font color='red'>%1")
                                      .arg(patientNumbersString) );

    noteNumberLabel = new QLabel( tr("<h4>Liczba zapisanych notatek: <font color='red'>%1 ")
                                  .arg(noteNumberString) );


    reminderNumberLabel = new QLabel( tr("<h4>Liczba zapisanych przypomnień: <font color='red'>%1 ")
                                  .arg(reminderNumberString) );

    lastRunDateLabel = new QLabel( tr("<h4>Data ostatniego uruchomienia programu: <font color='red'>%1")
                                   .arg(lastRunDate) );

    programVersionLabel = new QLabel( tr("<h4>Wersja programu: <font color='red'>v.0.1") );


    QVBoxLayout *statLayout = new QVBoxLayout;
    statLayout->addWidget(patientsNumberLabel);
    statLayout->addWidget(noteNumberLabel);
    statLayout->addWidget(reminderNumberLabel);
    statLayout->addWidget(lastRunDateLabel);
    statLayout->addWidget(programVersionLabel);
    statLayout->addStretch();

    statGrouBox->setLayout(statLayout);
}


void Stat::createLayout()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(statGrouBox);

    setLayout(layout);
}


void Stat::getStat()       
{
    QSqlQuery query;

    query.exec("SELECT count(*) FROM patient");
    if(query.next())
        patientNumbersString = query.value(0).toString();

    query.exec("SELECT count(*) FROM note");
    if(query.next())
        noteNumberString = query.value(0).toString();

    query.exec("SELECT count(*) FROM note");
    if(query.next())
        reminderNumberString = query.value(0).toString();


    lastRunDate = QDate::currentDate().toString();

}


