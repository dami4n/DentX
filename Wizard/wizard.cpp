#include <QWizard>
#include <QWizardPage>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include "wizard.h"

#include "intropage.h"
#include "languagepage.h"
#include "databasepage.h"
#include "clinicpage.h"
#include "finishpage.h"

Wizard::Wizard(QWidget *parent)
    :QWizard(parent)
{
    createIntroPage();
    createDatabasePage();
    createLanguagePage();
    createClinicPage();
    createFinishPage();
    createWizard();
 }

void Wizard::createWizard()
{
    addPage(introPage);
    addPage(languagePage);
    addPage(databasePage);
    addPage(clinicPage);
    addPage(finishPage);
}

void Wizard::createIntroPage()
{
    introPage = new IntroPage;
}

void Wizard::createLanguagePage()
{
    languagePage = new LanguagePage;
}

void Wizard::createDatabasePage()
{
    databasePage = new DatabasePage;
}

void Wizard::createClinicPage()
{
    clinicPage = new ClinicPage;
}

void Wizard::createFinishPage()
{
    finishPage = new FinishPage;
}
