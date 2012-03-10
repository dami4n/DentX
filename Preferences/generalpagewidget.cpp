#include <QComboBox>
#include <QGroupBox>
#include <QCheckBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QRadioButton>
#include "Preferences/preferences.h"

#include "generalpagewidget.h"

GeneralPageWidget::GeneralPageWidget(QWidget *parent) :
    QWidget(parent)
{
    preferences = Preferences::getInstance();

    createGui();
    createLayout();
}

void GeneralPageWidget::createGui()
{
    languageComboBox = new QComboBox;
    languageComboBox->addItem("Polski");
    languageComboBox->addItem("English");

    savePositionRadioButton = new QRadioButton(tr("Zapamiętaj pozycje programu podczas zamknięcia"));
    alwaysMaxRadioButton = new QRadioButton(tr("Uruchamiaj zawsze zmaksymalizowany"));
    alwaysMaxRadioButton->setChecked(true);

    closeCheckBox = new QCheckBox(tr("Pytaj o potwierdzenie zamkniecia programu"));
}

void GeneralPageWidget::createLayout()
{
    QGroupBox *languageGroupBox = new QGroupBox(tr("Język"));
    QFormLayout *languageLayout = new QFormLayout;
    languageLayout->addRow(tr("Wybierz język: "), languageComboBox);
    languageGroupBox->setLayout(languageLayout);

    QGroupBox *runOptionsGroupBox = new QGroupBox(tr("Uruchamianie"));
    QVBoxLayout *runLayout = new QVBoxLayout;
    runLayout->addWidget(alwaysMaxRadioButton);
    runLayout->addWidget(savePositionRadioButton);
    runLayout->addStretch();
    runOptionsGroupBox->setLayout(runLayout);

    QGroupBox *closeGroupBox = new QGroupBox(tr("Zamykanie"));
    QVBoxLayout *closeLayout = new QVBoxLayout;
    closeLayout->addWidget(closeCheckBox);
    closeGroupBox->setLayout(closeLayout);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(languageGroupBox);
    layout->addWidget(runOptionsGroupBox);
    //layout->addWidget(closeGroupBox);
    layout->addStretch();

    setLayout(layout);
}

int GeneralPageWidget::getLanguage()
{
    if( languageComboBox->currentIndex() == 0 )
        return Preferences::POLISH;
    if( languageComboBox->currentIndex() == 1)
        return Preferences::ENGLISH;

    return -1;
}

void GeneralPageWidget::readSettings()
{
    if(preferences->getLanguage() == Preferences::POLISH)
        languageComboBox->setCurrentIndex(0);
    if(preferences->getLanguage() == Preferences::ENGLISH)
        languageComboBox->setCurrentIndex(1);

    alwaysMaxRadioButton->setChecked( preferences->getAlwaysMax() );
    savePositionRadioButton->setChecked( preferences->getSavePosition() );
    closeCheckBox->setChecked( preferences->getCloseQuestion() );
}
