#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTimeEdit>
#include <QFormLayout>
#include "Preferences/preferences.h"

#include "clinicpagewidget.h"

ClinicPageWidget::ClinicPageWidget(QWidget *parent) :
    QWidget(parent)
{
    preferences = Preferences::getInstance();

    createGui();
    createLayout();
 }

 void ClinicPageWidget::createGui()
 {
     mondayCheckBox = new QCheckBox(tr("Poniedziałek"));
     tuesdayCheckBox = new QCheckBox(tr("Wtorek"));
     wednesdayCheckBox = new QCheckBox(tr("Środa"));
     thursdayCheckBox = new QCheckBox(tr("Czwartek"));
     fridayCheckBox = new QCheckBox(tr("Piątek"));
     saturdayCheckBox = new QCheckBox(tr("Sobota"));
     sundayCheckBox = new QCheckBox(tr("Niedziela"));

     startTimeEdit = new QTimeEdit;
     endTimeEdit = new QTimeEdit;

 }

 void ClinicPageWidget::createLayout()
 {
     QGroupBox *dayGroupBox = new QGroupBox(tr("Dni otwarcia"), this);

     QGridLayout *dayLayout = new QGridLayout;
     dayLayout->addWidget(mondayCheckBox, 0, 0);
     dayLayout->addWidget(tuesdayCheckBox, 1, 0);
     dayLayout->addWidget(wednesdayCheckBox, 2, 0);
     dayLayout->addWidget(thursdayCheckBox, 3, 0);
     dayLayout->addWidget(fridayCheckBox, 4, 0);
     dayLayout->addWidget(saturdayCheckBox, 0, 1);
     dayLayout->addWidget(sundayCheckBox, 1, 1);

     dayGroupBox->setLayout(dayLayout);

     QGroupBox *timeGroupBox = new QGroupBox(tr("Godziny otwarcia"), this);

     QFormLayout *timeLayout = new QFormLayout;
     timeLayout->addRow(tr("Od: "), startTimeEdit);
     timeLayout->addRow(tr("Do: "), endTimeEdit);

     timeGroupBox->setLayout(timeLayout);

     QVBoxLayout *mainLayout = new QVBoxLayout;
     mainLayout->addWidget(dayGroupBox);
     mainLayout->addWidget(timeGroupBox);

     setLayout(mainLayout);
 }

 void ClinicPageWidget::readSettings()
 {
     mondayCheckBox->setChecked(preferences->getMonday());
     tuesdayCheckBox->setChecked(preferences->getTuesday());
     wednesdayCheckBox->setChecked(preferences->getWednesday());
     thursdayCheckBox->setChecked(preferences->getThursday());
     fridayCheckBox->setChecked(preferences->getFriday());
     saturdayCheckBox->setChecked(preferences->getSaturday());
     sundayCheckBox->setChecked(preferences->getSunday());

     startTimeEdit->setTime(preferences->getStartTime());
     endTimeEdit->setTime(preferences->getEndTime());
 }
