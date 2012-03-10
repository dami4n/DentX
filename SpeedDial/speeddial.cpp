#include <QtGui>
#include "Note/addnotedialog.h"
#include "speeddial.h"
#include "stat.h"


SpeedDial::SpeedDial(QWidget *parent) :
    QWidget(parent)
{
    createButtons();
    createStat();
    createLayout();
}

void SpeedDial::createButtons()
{
    addNoteButton = new QPushButton( tr("Dodaj nową \nnotatkę") );
    addNoteButton->setIcon(QIcon(":/icons/note.png"));
    addNoteButton->setIconSize(QSize(128,128));
    connect(addNoteButton, SIGNAL(clicked()), this, SIGNAL(addNoteButtonClicked()));

    addReminderButton = new QPushButton( tr("Dodaj nowe \nprzypomnienie") );
    addReminderButton->setIcon(QIcon(":/icons/reminder.png"));
    addReminderButton->setIconSize(QSize(128,128));
    connect(addReminderButton, SIGNAL(clicked()), this, SIGNAL(addReminderButtonClicked()));

    prescriptionButton = new QPushButton( tr("Wypisz \nreceptę") );
    prescriptionButton->setIcon(QIcon(":/icons/DefineControls.png"));
    prescriptionButton->setIconSize(QSize(128, 128));
    connect(prescriptionButton, SIGNAL(clicked()), this, SIGNAL(prescriptionButtonClicked()));

    showPatientsButton = new QPushButton( tr("Pokaż \npacjentów") );
    showPatientsButton->setIcon(QIcon(":/icons/PatientFile.png") );
    showPatientsButton->setIconSize(QSize(128, 128));
    connect(showPatientsButton, SIGNAL(clicked()), this, SIGNAL(showButtonClicked()));

    addPatientButton = new QPushButton( tr("Dodaj nowego \npacjenta") );
    addPatientButton->setIcon(QIcon(":/icons/PatientData.png"));
    addPatientButton->setIconSize(QSize(128, 128));
    connect(addPatientButton, SIGNAL(clicked()), this, SIGNAL(addPatientButtonClicked()));

}


void SpeedDial::createLayout()
{
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(showPatientsButton);
    rightLayout->addWidget(addPatientButton);
    rightLayout->addWidget(addNoteButton);
    rightLayout->addWidget(addReminderButton);
    rightLayout->addWidget(prescriptionButton);


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(stat, 0, 0, 1, 3);
    layout->addLayout(rightLayout, 0, 4);

    setLayout(layout);
}

void SpeedDial::createStat()
{
    stat = new Stat;

}

void SpeedDial::resizeEvent(QResizeEvent *)
{
   addNoteButton->setIconSize( QSize( addNoteButton->size().width()-40, addNoteButton->size().height()-60 ));
   addReminderButton->setIconSize( QSize( addNoteButton->size().width()-40, addNoteButton->size().height()-60 ));
   prescriptionButton->setIconSize( QSize( addNoteButton->size().width()-40, addNoteButton->size().height()-60));
    showPatientsButton->setIconSize( QSize( addNoteButton->size().width()-40, addNoteButton->size().height()-60 ));
    addPatientButton->setIconSize( QSize( addNoteButton->size().width()-40, addNoteButton->size().height()-60 ));
}


