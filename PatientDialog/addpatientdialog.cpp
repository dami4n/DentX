#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QLineEdit>
#include <QGroupBox>
#include <QDebug>
#include <QScrollArea>
#include <QMessageBox>
#include "patientdialog.h"
#include "personaldetailwidget.h"
#include "additionalinformationwidget.h"
#include "examinationwidget.h"
#include "addpatientdialog.h"
#include "../patient.h"

AddPatientDialog::AddPatientDialog(QWidget *parent) :
    QDialog(parent)
{
    patient = new Patient;
    id = 0;

    createTabs();
    createImageLabel();
    createButtons();
    createLayout();
}

void AddPatientDialog::createTabs()
{
    personalDetailWidget = new PersonalDetailWidget;
    additionalInformationWidget = new AdditionalInformationWidget;
    examinationWidget = new ExaminationWidget;

//    QScrollArea *personalDetailScrollArea = new QScrollArea;
//    personalDetailScrollArea->setWidget(personalDetailWidget);
//    personalDetailScrollArea->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
//    personalDetailScrollArea->setWidgetResizable(true);
//    resize(personalDetailWidget->sizeHint());

//    QScrollArea *additionalInformationScrollArea = new QScrollArea;
//    additionalInformationScrollArea->setWidget(additionalInformationWidget);
//    additionalInformationScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    personalDetailScrollArea->setWidgetResizable(true);

    QScrollArea *examinationScrollArea = new QScrollArea;
    examinationScrollArea->setWidget(examinationWidget);
    examinationScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


//    tabWidget = new QTabWidget;
//    tabWidget->addTab( personalDetailScrollArea, QString(tr("Dane osobowe")) );
//    tabWidget->addTab( examinationScrollArea, QString( tr("Badania przedmiotowe") ));
//    tabWidget->addTab( additionalInformationScrollArea, QString(tr("Informacje dodatkowe")) );

        tabWidget = new QTabWidget;
        tabWidget->addTab( personalDetailWidget, QString(tr("Dane osobowe")) );
        tabWidget->addTab( examinationScrollArea, QString( tr("Badania przedmiotowe") ));
        tabWidget->addTab( additionalInformationWidget, QString(tr("Informacje dodatkowe")) );

}

void AddPatientDialog::createButtons()
{
    okButton = new QPushButton( tr("OK") );
    okButton->setIcon(QIcon(":/icons/ok.png"));

    cancelButton = new QPushButton( tr("Anuluj") );
    cancelButton->setIcon(QIcon(":/icons/Cancel.png"));

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void AddPatientDialog::createLayout()
{
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addStretch();
    buttonsLayout->setDirection(QBoxLayout::RightToLeft);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(userImageLabel);
    mainLayout->addWidget(tabWidget);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

void AddPatientDialog::createImageLabel()
{
    QPixmap pixmap(":/icons/user.png");
    userImageLabel = new QLabel;
    userImageLabel->setPixmap(pixmap);
}

void AddPatientDialog::okClicked()
{
    // niepotrzebna redundacja kodu

    if( personalDetailWidget->getName().isEmpty() )
    {
        QMessageBox::information(this, tr("Niepełne dane"),
                                 tr("Pole 'Imię' musi zawierać dane"));
        return;
    }

    if( personalDetailWidget->getLastName().isEmpty() )
    {
        QMessageBox::information(this, tr("Niepełne dane"),
                                 tr("Pole 'Nazwisko' musi zawierać dane"));
        return;
    }

    if( personalDetailWidget->getCity().isEmpty() )
    {
        QMessageBox::information(this, tr("Niepełne dane"),
                                 tr("Pole 'Miasto' musi zawierać dane"));
        return;
    }

    if( personalDetailWidget->getStreet().isEmpty() )
    {
        QMessageBox::information(this, tr("Niepełne dane"),
                                 tr("Pole 'Ulica' musi zawierać dane"));
        return;
    }

    if( personalDetailWidget->getPesel().isEmpty() )
    {
        QMessageBox::information(this, tr("Niepełne dane"),
                                 tr("Pole 'Pesel' musi zawierać dane"));
        return;
    }

    if( !checkPesel( personalDetailWidget->getPesel() ) )
    {
        QMessageBox::information(this, tr("Błędny PESEL"),
                                 tr("Wprowadź poprawny numer PESEL"));
        return;
    }

    createPatient();

    accept();
}

void AddPatientDialog::createPatient()
{
    // new patient
    patient->id = id; // id potrzebne przy edycji pacjenta
    patient->name = personalDetailWidget->getName();
    patient->lastName = personalDetailWidget->getLastName();
    patient->city = personalDetailWidget->getCity();
    patient->apartment = personalDetailWidget->getApartmentNumber();

    if( personalDetailWidget->maleIsChecked() )
        patient->gender = patient->MALE;
    else
        patient->gender = patient->FEMALE;

    patient->street = personalDetailWidget->getStreet();
    patient->zipCode = personalDetailWidget->getZipCode();
    patient->house = personalDetailWidget->getStreetNumber();
    patient->PESEL = personalDetailWidget->getPesel();
    patient->phone = personalDetailWidget->getPhone();
    patient->registrationDate = personalDetailWidget->getRegistrationDate();


    patient->pharmaceuticals = additionalInformationWidget->getPharmaceuticals();
    patient->disorders = additionalInformationWidget->getDisorders();
    patient->allergy = additionalInformationWidget->getAllergy();
    patient->note = additionalInformationWidget->getNote();

    patient->dentalArticulation = examinationWidget->getDentalArticulation();
    patient->joint = examinationWidget->getJoint();
    patient->exposure = examinationWidget->getExposure();
    patient->color = examinationWidget->getColor();
    patient->efflorescencePre = examinationWidget->getEfflorescencePre() ;
    patient->efflorescenceSec = examinationWidget->getEfflorescenceSec();
    patient->morfologicalChanges = examinationWidget->getMorfologicalChanges();
    patient->tongue = examinationWidget->getTongue();
    patient->morfologicalDisorder = examinationWidget->getMorfologicalDisorder();
    patient->ohi = examinationWidget->getOhi();
    patient->pli = examinationWidget->getPli();
    patient->api = examinationWidget->getApi();
    patient->salivaS = examinationWidget->getStimulateSaliva();
    patient->salivaNS = examinationWidget->getNonStimulateSaliva();

}

bool AddPatientDialog::checkPesel( QString pesel )
{

    if( pesel.length() != 11)
    {
        return false;
    }

    short peselNumbers[11];

    // convert QString number to short[11]
    for( int i = 0; i < 11; ++i )
    {
        QChar c = pesel.at(i);
        QString *tmp = new QString(c);
        peselNumbers[i] = tmp->toShort();
    }

    // suma kontrolna
    // a+3b+7c+9d+e+3f+7g+9h+i+3j+k

    int s = peselNumbers[0] +
            ( 3 * peselNumbers[1] ) +
            ( 7 * peselNumbers[2] ) +
            ( 9 * peselNumbers[3] ) +
            peselNumbers[4] +
            ( 3 * peselNumbers[5] ) +
            ( 7 * peselNumbers[6] ) +
            ( 9 * peselNumbers[7] ) +
            peselNumbers[8] +
            ( 3 * peselNumbers[9] ) +
            peselNumbers[10];


    if( s % 10 == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}
