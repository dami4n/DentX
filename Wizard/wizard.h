#ifndef WIZARD_H
#define WIZARD_H

#include <QWizard>

class QWizard;
class QWizardPage;
class QComboBox;
class QLineEdit;

class IntroPage;
class LanguagePage;
class DatabasePage;
class ClinicPage;
class FinishPage;

class Wizard : public QWizard
{
    Q_OBJECT
public:
    explicit Wizard(QWidget *parent = 0);

private:
    void createWizard();
    void createIntroPage();
    void createLanguagePage();
    void createDatabasePage();
    void createClinicPage();
    void createFinishPage();

    IntroPage *introPage;
    LanguagePage *languagePage;
    DatabasePage *databasePage;
    ClinicPage *clinicPage;
    FinishPage *finishPage;

};

#endif // WIZARD_H
