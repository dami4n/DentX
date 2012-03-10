#include <QWizardPage>
#include <QVBoxLayout>
#include "Preferences/clinicpagewidget.h"
#include "clinicpage.h"


ClinicPage::ClinicPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle( tr("Ustawienia gabinetu"));
    setSubTitle( tr("Wybierz dni i godziny otwarcia gabinetu"));

    ClinicPageWidget *clinicPage = new ClinicPageWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(clinicPage);

    setLayout(layout);
}
