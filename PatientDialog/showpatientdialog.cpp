#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QGroupBox>
#include <QDebug>
#include <QIcon>
#include <QCheckBox>
#include "personaldetailwidget.h"
#include "additionalinformationwidget.h"
#include "examinationwidget.h"
#include "Teeth/diagramdialog.h"

#include "showpatientdialog.h"

ShowPatientDialog::ShowPatientDialog(QWidget *parent) :
    AddPatientDialog(parent)
{
    createEditableCheckBox();
    createButtons();

    createLayout();

    setEditable(false);
}

void ShowPatientDialog::setEditable(bool value)
{
    examinationWidget->setEditable(value);
    additionalInformationWidget->setEditable(value);
    personalDetailWidget->setEditable(value);

    if(value)
    {
        closeButton->hide();
        okButton->show();
        cancelButton->show();
    }
    else
    {
        okButton->hide();
        cancelButton->hide();
        closeButton->show();
    }

    setPatient(patient);
}

void ShowPatientDialog::createLayout()
{
    mainLayout->removeWidget(okButton);
    mainLayout->removeWidget(cancelButton);

    mainLayout->addWidget(showTeethDiagramButton);

    mainLayout->addWidget(isEditableCheckBox);
    mainLayout->addWidget( closeButton );

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addStretch();
    buttonsLayout->setDirection(QBoxLayout::RightToLeft);
    mainLayout->addLayout(buttonsLayout);

}

void ShowPatientDialog::createButtons()
{
    closeButton = new QPushButton( tr("Zamknij") );
    closeButton->setIcon(QIcon(":/icons/Cancel.png"));
    closeButton->hide();
    connect( closeButton, SIGNAL(clicked()), this, SLOT(reject()) );

    showTeethDiagramButton = new QPushButton( tr("Pokaż diagram zębowy"));
    showTeethDiagramButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    showTeethDiagramButton->setIcon(QIcon(":/icons/Tooth.png"));
    //showTeethDiagramButton->setIconSize(QSize(20, 20));
    connect(showTeethDiagramButton, SIGNAL(clicked()), this, SLOT(showTeethDiagram()));

}

void ShowPatientDialog::createEditableCheckBox()
{
    isEditableCheckBox = new QCheckBox( tr("Edycja"), this );
    connect(isEditableCheckBox, SIGNAL(clicked(bool)), this, SLOT(setEditable(bool)));
}

void ShowPatientDialog::setPatient(Patient newPatient)
{
    patient = newPatient;

    personalDetailWidget->setPatient(patient);
    additionalInformationWidget->setPatient(patient);
    examinationWidget->setPatient(patient);

    id = patient.id;
}

void ShowPatientDialog::showTeethDiagram()
{
    DiagramDialog *dialog = new DiagramDialog(id);
    dialog->exec();
}

void ShowPatientDialog::setEditableCheckBox(bool value)
{
    isEditableCheckBox->setChecked(value);
    setEditable(value);
}
