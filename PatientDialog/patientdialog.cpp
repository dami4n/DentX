#include <QtGui>
#include "patientdialog.h"
#include "personaldetailwidget.h"
#include "additionalinformationwidget.h"
#include "examinationwidget.h"

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent)
{
    createTabs();
    createImageLabel();
    createButtons();
    createLayout();
}

void PatientDialog::createTabs()
{
    personalDetailWidget = new PersonalDetailWidget;
    additionalInformationWidget = new AdditionalInformationWidget;
    examinationWidget = new ExaminationWidget;

    tabWidget = new QTabWidget;
    tabWidget->addTab( personalDetailWidget, QString(tr("Dane osobowe")) );
    tabWidget->addTab( examinationWidget, QString( tr("Badania przedmiotowe") ));
    tabWidget->addTab( additionalInformationWidget, QString(tr("Informacje dodatkowe")) );

}

void PatientDialog::createButtons()
{
    showTeethDiagramButton = new QPushButton( tr("Pokaż diagram zębowy"));
    showTeethDiagramButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);

    okButton = new QPushButton( tr("OK") );
    cancelButton = new QPushButton( tr("Anuluj") );

    connect(showTeethDiagramButton, SIGNAL(clicked()), this, SLOT(showTeethDiagram()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void PatientDialog::createLayout()
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

void PatientDialog::createImageLabel()
{
    QPixmap pixmap(":/icons/user.png");
    userImageLabel = new QLabel;
    userImageLabel->setPixmap(pixmap);
}

void PatientDialog::showTeethDiagram()
{

}

void PatientDialog::okClicked()
{

}
