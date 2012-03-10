#ifndef LANGUAGEPAGE_H
#define LANGUAGEPAGE_H

#include <QWizardPage>

class QComboBox;

class LanguagePage : public QWizardPage
{
    Q_OBJECT
public:
    explicit LanguagePage(QWidget *parent = 0);

private:
     QComboBox *languageComboBox;

};

#endif // LANGUAGEPAGE_H
