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
#include "examinationwidget.h"

ExaminationWidget::ExaminationWidget(QWidget *parent) :
    QWidget(parent)
{
    createExamination();
    createLayout();
}

void ExaminationWidget::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(testLayout);

    setLayout(mainLayout);
}

void ExaminationWidget::createExamination()
{
    // Zgryz
    dentalArticulationLabel = new QLabel( tr("Zgryz:") );
    dentalArticulationComboBox = new QComboBox;
    dentalArticulationComboBox->addItem("");
    dentalArticulationComboBox->addItem( tr("prawidłowy") );
    dentalArticulationComboBox->addItem( tr("krzyżowy") );
    dentalArticulationComboBox->addItem( tr("retruzja") );
    dentalArticulationComboBox->addItem( tr("protruzja") );
    dentalArticulationComboBox->addItem( tr("otwarty") );
    dentalArticulationComboBox->addItem( tr("głeboki") );

    dentalArticulationLabel->setBuddy(dentalArticulationComboBox);

    QHBoxLayout *dentalArticulationLayout = new QHBoxLayout;
    dentalArticulationLayout->addWidget(dentalArticulationLabel);
    dentalArticulationLayout->addWidget(dentalArticulationComboBox);

    // Staw
    jointLabel = new QLabel( tr("Staw skroniowo-żuchwowy:"));
    jointComboBox = new QComboBox;
    jointComboBox->addItem("");
    jointComboBox->addItem( tr("prawidłowy") );
    jointComboBox->addItem( tr("trzaski") );
    jointComboBox->addItem( tr("zbaczanie żuchwy") );
    jointComboBox->addItem( tr("szczękościsk") );
    jointComboBox->addItem( tr("przerost mięśni żwaczowych") );
    jointComboBox->addItem( tr("boleśność palpacyjna") );
    jointComboBox->addItem( tr("szmery") );
    jointComboBox->addItem( tr("sztywność mieśni") );

    jointLabel->setBuddy(jointComboBox);

    QHBoxLayout *joinLayout = new QHBoxLayout;
    joinLayout->addWidget(jointLabel);
    joinLayout->addWidget(jointComboBox);

    // narażenia
    exposureLabel = new QLabel( tr("Narażenia tkanek zmineralizowanych:") );
    exposureComboBox = new QComboBox;
    exposureComboBox->addItem("");
    exposureComboBox->addItem( tr("brak") );
    exposureComboBox->addItem( tr("abfrakcja") );
    exposureComboBox->addItem( tr("abrazja") );
    exposureComboBox->addItem( tr("atrycja") );
    exposureComboBox->addItem( tr("erozja") );

    exposureLabel->setBuddy(exposureComboBox);

    QHBoxLayout *exposureLayout = new QHBoxLayout;
    exposureLayout->addWidget(exposureLabel);
    exposureLayout->addWidget(exposureComboBox);

    // Błona śluzowa
    QGroupBox *mucosaGroupBox = new QGroupBox( tr("Stan błony śluzowej") );

    colorLabel = new QLabel( tr("Barwa") );
    colorComboBox = new QComboBox;
    colorComboBox->addItem("");
    colorComboBox->addItem( tr("prawidłowa") );
    colorComboBox->addItem( tr("nieprawidłowa") );

    colorLabel->setBuddy(colorComboBox);

    efflorescencePreLabel = new QLabel( tr("Wykwity pierowtne") );
    efflorescencePreComboBox = new QComboBox;
    efflorescencePreComboBox->addItem("");
    efflorescencePreComboBox->addItem( tr("brak") );
    efflorescencePreComboBox->addItem( tr("plama") );
    efflorescencePreComboBox->addItem( tr("plamka") );
    efflorescencePreComboBox->addItem( tr("grudka") );
    efflorescencePreComboBox->addItem( tr("guzek") );
    efflorescencePreComboBox->addItem( tr("guz") );
    efflorescencePreComboBox->addItem( tr("bąbel pokrzywowy") );
    efflorescencePreComboBox->addItem( tr("pęchęrzyk") );
    efflorescencePreComboBox->addItem( tr("pęcherz") );

    efflorescencePreLabel->setBuddy(efflorescencePreComboBox);

    efflorescenceSecLabel = new QLabel( tr("Wykwity wtórne") );
    efflorescenceSecComboBox = new QComboBox;
    efflorescenceSecComboBox->addItem("");
    efflorescenceSecComboBox->addItem( tr("brak") );
    efflorescenceSecComboBox->addItem( tr("nadżerka") );
    efflorescenceSecComboBox->addItem( tr("owrzodzenie") );
    efflorescenceSecComboBox->addItem( tr("szczelina") );
    efflorescenceSecComboBox->addItem( tr("blizna") );
    efflorescenceSecComboBox->addItem( tr("krosta") );
    efflorescenceSecComboBox->addItem( tr("strup") );

    efflorescenceSecLabel->setBuddy(efflorescenceSecComboBox);

    morfologicalChangesLabel = new QLabel( tr("Ogniskowe zmiany morfologiczne") );
    morfologicalChangesComboBox = new QComboBox;
    morfologicalChangesComboBox->addItem("");
    morfologicalChangesComboBox->addItem( tr("brak") );
    morfologicalChangesComboBox->addItem( tr("leukoplakia") );
    morfologicalChangesComboBox->addItem( tr("erytroplakia") );
    morfologicalChangesComboBox->addItem( tr("leukoerytroplakia") );
    morfologicalChangesComboBox->addItem( tr("liszaj płaski") );
    morfologicalChangesComboBox->addItem( tr("nikotynowe zapalenie jamy ustnej") );
    morfologicalChangesComboBox->addItem( tr("halitosis") );

    morfologicalChangesLabel->setBuddy(morfologicalChangesComboBox);

    QGridLayout *mucosaLayout = new QGridLayout;
    mucosaLayout->addWidget(colorLabel, 0, 0);
    mucosaLayout->addWidget(colorComboBox, 0, 1);
    mucosaLayout->addWidget(efflorescencePreLabel, 1, 0);
    mucosaLayout->addWidget(efflorescencePreComboBox, 1, 1);
    mucosaLayout->addWidget(efflorescenceSecLabel, 2, 0);
    mucosaLayout->addWidget(efflorescenceSecComboBox, 2, 1);
    mucosaLayout->addWidget(morfologicalChangesLabel, 3, 0);
    mucosaLayout->addWidget(morfologicalChangesComboBox, 3, 1);

    mucosaGroupBox->setLayout(mucosaLayout);

    // język
    QGroupBox *tongueGroupBox = new QGroupBox( tr("Język") );

    tongueLabel = new QLabel( tr("Nalot") );
    tongueComboBox = new QComboBox;
    tongueComboBox->addItem("");
    tongueComboBox->addItem( tr("brak") );
    tongueComboBox->addItem( tr("występuje") );

    tongueLabel->setBuddy(tongueComboBox);

    QHBoxLayout *tongueLayout = new QHBoxLayout;
    tongueLayout->addWidget(tongueLabel);
    tongueLayout->addWidget(tongueComboBox);

    tongueGroupBox->setLayout(tongueLayout);

    // zaburzenia morfologiczne
    QGroupBox *morfologicalDisorderGroupBox = new QGroupBox( tr("Zmiany morfologiczne") );

    morfologicalDisorderLabel = new QLabel( tr("Zaburzenia morfologiczne zębów") );
    morfologicalDisorderComboBox = new QComboBox;
    morfologicalDisorderComboBox->addItem("");
    morfologicalDisorderComboBox->addItem( tr("brak") );
    morfologicalDisorderComboBox->addItem( tr("hipomineralizacja szkliwa") );
    morfologicalDisorderComboBox->addItem( tr("hipoplazja szkliwa") );
    morfologicalDisorderComboBox->addItem( tr("niedorozwój zębiny") );
    morfologicalDisorderComboBox->addItem( tr("fluoroza") );

    morfologicalDisorderLabel->setBuddy(morfologicalDisorderComboBox);

    QHBoxLayout *morfologicalDisorderLayout = new QHBoxLayout;
    morfologicalDisorderLayout->addWidget(morfologicalDisorderLabel);
    morfologicalDisorderLayout->addWidget(morfologicalDisorderComboBox);

    morfologicalDisorderGroupBox->setLayout(morfologicalDisorderLayout);

    // higiena
    QGroupBox *hygieneGroupBox = new QGroupBox( tr("Higiena jamy ustnej"));

    ohiLabel = new QLabel( tr("OHI") );
    ohiComboBox = new QComboBox;
    ohiComboBox->addItem( "" );
    ohiComboBox->addItem( tr("0") );
    ohiComboBox->addItem( tr("1") );
    ohiComboBox->addItem( tr("2") );
    ohiComboBox->addItem( tr("3") );
    ohiComboBox->addItem( tr("4") );
    ohiComboBox->addItem( tr("5") );
    ohiComboBox->addItem( tr("6") );

    ohiLabel->setBuddy(ohiComboBox);

    pliLabel = new QLabel( tr("PLI (Plaque Index) "));
    pliComboBox = new QComboBox;
    pliComboBox->addItem( "" );
    pliComboBox->addItem( tr("0") );
    pliComboBox->addItem( tr("1") );
    pliComboBox->addItem( tr("2") );
    pliComboBox->addItem( tr("3") );

    pliLabel->setBuddy(pliComboBox);

    apiLabel = new QLabel( tr("API (Approximal Plaque Index)") );
    apiComboBox = new QComboBox;
    apiComboBox->addItem("");
    apiComboBox->addItem( tr("< 25%") );
    apiComboBox->addItem( tr("25% - 39%") );
    apiComboBox->addItem( tr("40% - 70%") );
    apiComboBox->addItem( tr("71% - 100%") );

    apiLabel->setBuddy(apiComboBox);

    QGridLayout *hygieneLayout = new QGridLayout;
    hygieneLayout->addWidget(ohiLabel, 0, 0);
    hygieneLayout->addWidget(ohiComboBox, 0, 1);
    hygieneLayout->addWidget(pliLabel, 1, 0);
    hygieneLayout->addWidget(pliComboBox, 1, 1);
    hygieneLayout->addWidget(apiLabel, 2, 0);
    hygieneLayout->addWidget(apiComboBox, 2, 1);

    hygieneGroupBox->setLayout(hygieneLayout);

    // sialometria
    QGroupBox *sialometryGroupBox = new QGroupBox( tr("Sialometria") );

    stimulateSalivaLabel = new QLabel( tr("Ślina stymulowana(ml/min)") );
    stimulateSalivaLineEdit = new QLineEdit;
    stimulateSalivaLabel->setBuddy(stimulateSalivaLineEdit);

    nonStimulateSalivaLabel = new QLabel( tr("Ślina niestymulowana(ml/min)"));
    nonStimulateSalivaLineEdit = new QLineEdit;
    nonStimulateSalivaLabel->setBuddy(nonStimulateSalivaLineEdit);

    QGridLayout *sialometryLayout = new QGridLayout;
    sialometryLayout->addWidget(stimulateSalivaLabel, 0, 0);
    sialometryLayout->addWidget(stimulateSalivaLineEdit, 0, 1);
    sialometryLayout->addWidget(nonStimulateSalivaLabel, 1, 0);
    sialometryLayout->addWidget(nonStimulateSalivaLineEdit, 1, 1);

    sialometryGroupBox->setLayout(sialometryLayout);

    // main layout
    testLayout = new QVBoxLayout;
    testLayout->addLayout(dentalArticulationLayout);
    testLayout->addLayout(joinLayout);
    testLayout->addLayout(exposureLayout);
    testLayout->addWidget(mucosaGroupBox);
    testLayout->addWidget(tongueGroupBox);
    testLayout->addWidget(morfologicalDisorderGroupBox);
    testLayout->addWidget(hygieneGroupBox);
    testLayout->addWidget(sialometryGroupBox);
    testLayout->addStretch();
}

void ExaminationWidget::setEditable(bool value)
{
    dentalArticulationComboBox->setEnabled( value );
    jointComboBox->setEnabled( value );
    exposureComboBox->setEnabled( value );
    colorComboBox->setEnabled( value );
    efflorescencePreComboBox->setEnabled( value );
    efflorescenceSecComboBox->setEnabled( value );
    morfologicalChangesComboBox->setEnabled( value );
    tongueComboBox->setEnabled( value );
    morfologicalDisorderComboBox->setEnabled( value );
    ohiComboBox->setEnabled( value );
    pliComboBox->setEnabled( value );
    apiComboBox->setEnabled( value );
    stimulateSalivaLineEdit->setEnabled( value );
    nonStimulateSalivaLineEdit->setEnabled( value );
}

void ExaminationWidget::setPatient(Patient patient)
{
    dentalArticulationComboBox->setCurrentIndex( dentalArticulationComboBox->findText(patient.dentalArticulation ) );
    jointComboBox->setCurrentIndex( jointComboBox->findText(patient.joint ) );
    exposureComboBox->setCurrentIndex( exposureComboBox->findText(patient.exposure ) );
    colorComboBox->setCurrentIndex( colorComboBox->findText(patient.color ) );
    efflorescencePreComboBox->setCurrentIndex( efflorescencePreComboBox->findText(patient.efflorescencePre ) );
    efflorescenceSecComboBox->setCurrentIndex( efflorescenceSecComboBox->findText(patient.efflorescenceSec ) );
    morfologicalChangesComboBox->setCurrentIndex( morfologicalChangesComboBox->findText(patient.morfologicalChanges ) );
    tongueComboBox->setCurrentIndex( tongueComboBox->findText(patient.tongue ) );
    morfologicalDisorderComboBox->setCurrentIndex( morfologicalDisorderComboBox->findText(patient.morfologicalDisorder ) );
    ohiComboBox->setCurrentIndex( ohiComboBox->findText(patient.ohi ) );
    pliComboBox->setCurrentIndex( pliComboBox->findText(patient.pli ) );
    apiComboBox->setCurrentIndex( apiComboBox->findText(patient.api ) );

    stimulateSalivaLineEdit->setText( patient.salivaS );
    nonStimulateSalivaLineEdit->setText( patient.salivaNS );
}
