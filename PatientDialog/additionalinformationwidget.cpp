#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QLineEdit>
#include <QGroupBox>
#include <QDebug>
#include "additionalinformationwidget.h"

AdditionalInformationWidget::AdditionalInformationWidget(QWidget *parent) :
    QWidget(parent)
{
    createAdditionalInformation();
    createLayout();
}


void AdditionalInformationWidget::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(additionalInformationGroupBox);

    setLayout(mainLayout);
}

void AdditionalInformationWidget::createAdditionalInformation()
{
    additionalInformationGroupBox = new QGroupBox( tr("Informacje dodatkowe") );

    pharmaceuticalsLabel = new QLabel( tr("Przyjmowane leki: ") );
    pharmaceuticalsTextEdit = new QTextEdit;
    pharmaceuticalsTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    pharmaceuticalsLabel->setBuddy(pharmaceuticalsTextEdit);

    allergyLabel = new QLabel( tr("Uczulenia: ") );
    allergyTextEdit = new QTextEdit;
    allergyTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    allergyLabel->setBuddy(allergyTextEdit);

    disordersLabel = new QLabel( tr("Choroby: ") );
    disordersTextEdit = new QTextEdit;
    disordersTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    disordersLabel->setBuddy(disordersTextEdit);

    noteLabel = new QLabel( tr("Uwagi: ") );
    noteTextEdit = new QTextEdit;
    noteTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    noteLabel->setBuddy(noteTextEdit);

    QGridLayout *additionalInformationLayout = new QGridLayout;
    additionalInformationLayout->addWidget(pharmaceuticalsLabel, 0, 0, 1, 1, Qt::AlignTop);
    additionalInformationLayout->addWidget(pharmaceuticalsTextEdit, 1, 0);
    additionalInformationLayout->addWidget(allergyLabel, 2, 0, 1, 1, Qt::AlignTop);
    additionalInformationLayout->addWidget(allergyTextEdit, 3, 0);
    additionalInformationLayout->addWidget(disordersLabel, 4, 0, 1, 1, Qt::AlignTop);
    additionalInformationLayout->addWidget(disordersTextEdit, 5, 0);
    additionalInformationLayout->addWidget(noteLabel, 6, 0);
    additionalInformationLayout->addWidget(noteTextEdit, 7, 0);

    additionalInformationGroupBox->setLayout(additionalInformationLayout);
}

void AdditionalInformationWidget::setEditable(bool value)
{
    pharmaceuticalsTextEdit->setEnabled( value );
    disordersTextEdit->setEnabled( value );
    allergyTextEdit->setEnabled( value );
    noteTextEdit->setEnabled( value );
}

void AdditionalInformationWidget::setPatient(Patient patient)
{
    pharmaceuticalsTextEdit->setText( patient.pharmaceuticals );
    disordersTextEdit->setText( patient.disorders );
    allergyTextEdit->setText( patient.allergy );
    noteTextEdit->setText( patient.note );
}
