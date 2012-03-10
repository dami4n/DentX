#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QLineEdit>
#include <QGroupBox>
#include <QDebug>
#include <QComboBox>
#include <QRegExp>
#include "personaldetailwidget.h"

PersonalDetailWidget::PersonalDetailWidget(QWidget *parent) :
    QWidget(parent)
{
   createAddress();
   createPersonalDetail();
   createGender();
   createOthersInformation();
   createLayout();

}

void PersonalDetailWidget::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(personalDetailsGroupBox);
    mainLayout->addWidget(genderGroupBox);
    mainLayout->addWidget(addressGroupBox);
    mainLayout->addWidget(othersInformationGroupBox);
    mainLayout->addStretch();

    setLayout(mainLayout);
}

void PersonalDetailWidget::createAddress()
{
    addressGroupBox = new QGroupBox( tr("Adres") );

    // city
    cityLabel = new QLabel( tr("Miasto") );
    cityLineEdit = new QLineEdit;

    cityLabel->setBuddy(cityLineEdit);

    QRegExp cityRegExp("[A-Za-z]+");
    cityLineEdit->setValidator(new QRegExpValidator(cityRegExp, this));

    // zip code
    zipCodeLabel = new QLabel( tr("Kod pocztowy") );
    zipCodeLineEdit = new QLineEdit;
    zipCodeLineEdit->setMaxLength(8);
    zipCodeLineEdit->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    zipCodeLabel->setBuddy(zipCodeLineEdit);

    QRegExp zipCodeRegExp("[0-9-]+");
    zipCodeLineEdit->setValidator(new QRegExpValidator(zipCodeRegExp, this));

    // street
    streetLabel = new QLabel( tr("Ulica") );
    streetLineEdit = new QLineEdit;

    streetLabel->setBuddy(streetLineEdit);

    QRegExp streetRegExp("[A-Za-z0-9 ]+");
    streetLineEdit->setValidator(new QRegExpValidator(streetRegExp, this));

    // street number
    streetNumberLabel = new QLabel( tr("Numer domu") );
    streetNumberLineEdit = new QLineEdit;
    streetNumberLineEdit->setMaxLength(6);
    streetNumberLineEdit->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    streetNumberLabel->setBuddy(streetNumberLineEdit);

    QRegExp streetNumberRegExp("[0-9A-Za-z]+");
    streetNumberLineEdit->setValidator(new QRegExpValidator(streetNumberRegExp, this));

    // apartment number
    apartmentNumberLabel = new QLabel( tr("Numer mieszkania") );
    apartmentNumberLineEdit = new QLineEdit;
    apartmentNumberLineEdit->setMaxLength(6);
    apartmentNumberLineEdit->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    apartmentNumberLabel->setBuddy(apartmentNumberLineEdit);

    QRegExp apartmentNumberRegExp("[0-9A-Za-z]+");
    apartmentNumberLineEdit->setValidator(new QRegExpValidator(apartmentNumberRegExp, this));

    // layout - address section
    QGridLayout *addressLayout = new QGridLayout;
    addressLayout->addWidget(cityLabel, 0, 0);
    addressLayout->addWidget(cityLineEdit, 0, 1);
    addressLayout->addWidget(zipCodeLabel, 1, 0);
    addressLayout->addWidget(zipCodeLineEdit, 1, 1);
    addressLayout->addWidget(streetLabel, 2, 0);
    addressLayout->addWidget(streetLineEdit, 2, 1);
    addressLayout->addWidget(streetNumberLabel, 3, 0);
    addressLayout->addWidget(streetNumberLineEdit, 3, 1);
    addressLayout->addWidget(apartmentNumberLabel, 4, 0);
    addressLayout->addWidget(apartmentNumberLineEdit, 4, 1);

    addressGroupBox->setLayout(addressLayout);
}

void PersonalDetailWidget::createOthersInformation()
{
    othersInformationGroupBox = new QGroupBox( tr("Pozostałe dane") );

    // phone number
    phoneLabel = new QLabel( tr("Telefon") );
    phoneLineEdit = new QLineEdit;
    phoneLineEdit->setMaxLength(20);

    phoneLabel->setBuddy(phoneLineEdit);

    QRegExp phoneRegExp("[0-9-+]+");
    phoneLineEdit->setValidator(new QRegExpValidator(phoneRegExp, this));


    // registartion date
    registrationDateLabel = new QLabel( tr("Data rejestracji") );
    registrationDateLineEdit = new QLineEdit;

    registrationDateLabel->setBuddy(registrationDateLineEdit);

    registrationDate = QDateTime::currentDateTime();

    registrationDateLineEdit->setText( registrationDate.toString() );
    registrationDateLineEdit->setReadOnly( true );


    // layout for 'others information' section
    QGridLayout *othersInformationLayout = new QGridLayout;
    othersInformationLayout->addWidget(phoneLabel, 0, 0);
    othersInformationLayout->addWidget(phoneLineEdit, 0, 1);
    othersInformationLayout->addWidget(registrationDateLabel, 1, 0);
    othersInformationLayout->addWidget(registrationDateLineEdit, 1, 1);

    othersInformationGroupBox->setLayout(othersInformationLayout);
}

void PersonalDetailWidget::createPersonalDetail()
{
    personalDetailsGroupBox = new QGroupBox( tr("Dane osobowe") );

    // id
    idLabel = new QLabel( tr("Numer karty") );
    idLineEdit = new QLineEdit;
    idLineEdit->setEnabled(false);
    QVBoxLayout *idLayout = new QVBoxLayout;
    idLayout->addWidget(idLabel);
    idLayout->addWidget(idLineEdit);

    idLabel->setBuddy(idLineEdit);

    // name
    nameLabel = new QLabel( tr("Imię") );
    nameLineEdit = new QLineEdit;
    nameLabel->setBuddy(nameLineEdit);

    QRegExp nameRegExp("[A-Za-z]+");
    nameLineEdit->setValidator(new QRegExpValidator(nameRegExp, this));

    QVBoxLayout *nameLayout = new QVBoxLayout;
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(nameLineEdit);

    // last name
    lastNameLabel = new QLabel( tr("Nazwisko") );
    lastNameLineEdit = new QLineEdit;
    lastNameLineEdit->setValidator(new QRegExpValidator(nameRegExp, this));

    lastNameLabel->setBuddy(lastNameLineEdit);

    QVBoxLayout *lastNameLayout = new QVBoxLayout;
    lastNameLayout->addWidget(lastNameLabel);
    lastNameLayout->addWidget(lastNameLineEdit);

    // pesel
    peselLabel = new QLabel( tr("PESEL") );
    peselLineEdit = new  QLineEdit;
    peselLineEdit->setMaxLength(11);

    peselLabel->setBuddy(peselLineEdit);

    QRegExp peselRegExp("[0-9]+");
    peselLineEdit->setValidator(new QRegExpValidator(peselRegExp, this));

    QVBoxLayout *peselLayout = new QVBoxLayout;
    peselLayout->addWidget(peselLabel);
    peselLayout->addWidget(peselLineEdit);

    // id, name, last name layout
    QGridLayout *idNameLastNameLayout = new QGridLayout;
    idNameLastNameLayout->addLayout(nameLayout, 0, 0);
    idNameLastNameLayout->addLayout(lastNameLayout, 0 , 1);
    idNameLastNameLayout->addLayout(idLayout, 1, 0);
    idNameLastNameLayout->addLayout(peselLayout, 1, 1);

    personalDetailsGroupBox->setLayout(idNameLastNameLayout);

}

void PersonalDetailWidget::createGender()
{
    genderGroupBox = new QGroupBox( tr("Płeć") );

    maleRadioButton = new QRadioButton( tr("Mężczyzna") );
    femaleRadioButton = new QRadioButton( tr("Kobieta") );
    maleRadioButton->setChecked(true);

    QHBoxLayout *genderLayout =new QHBoxLayout();
    genderLayout->addWidget(maleRadioButton);
    genderLayout->addWidget(femaleRadioButton);
    genderLayout->addStretch();

    genderGroupBox->setLayout(genderLayout);
}

void PersonalDetailWidget::setEditable(bool value)
{
    nameLineEdit->setEnabled( value );
    lastNameLineEdit->setEnabled( value );
    cityLineEdit->setEnabled( value );
    apartmentNumberLineEdit->setEnabled( value );
    maleRadioButton->setEnabled(value);
    femaleRadioButton->setEnabled( value );
    streetLineEdit->setEnabled( value );
    zipCodeLineEdit->setEnabled( value );
    streetNumberLineEdit->setEnabled( value );
    peselLineEdit->setEnabled( value );
    phoneLineEdit->setEnabled( value );
    registrationDateLineEdit->setEnabled( value );
}

void PersonalDetailWidget::setPatient(Patient patient)
{
    idLineEdit->setText( QString::number(patient.id) );

    nameLineEdit->setText( patient.name );
    lastNameLineEdit->setText( patient.lastName );
    cityLineEdit->setText( patient.city );
    apartmentNumberLineEdit->setText( patient.apartment);

    if( patient.gender == patient.MALE )
        maleRadioButton->setChecked(true);
    else
        femaleRadioButton->setChecked(true);

    streetLineEdit->setText( patient.street );
    zipCodeLineEdit->setText( patient.zipCode );
    streetNumberLineEdit->setText( patient.house );
    peselLineEdit->setText( patient.PESEL );
    phoneLineEdit->setText( patient.phone );
    registrationDateLineEdit->setText( patient.registrationDate.toString() );
}
