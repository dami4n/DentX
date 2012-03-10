#include <QComboBox>
#include <QFormLayout>
#include "languagepage.h"

LanguagePage::LanguagePage(QWidget *parent) :
    QWizardPage(parent)
{

    setTitle( tr("Ustawienia języka") );
    setSubTitle( tr("Wybierz jeden z dostępnych języków"));

    languageComboBox = new QComboBox;
    languageComboBox->addItem("Polski");
    languageComboBox->addItem("English");
    languageComboBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(tr("Wybierz język aplikacji: "), languageComboBox);

    setLayout(layout);


}
