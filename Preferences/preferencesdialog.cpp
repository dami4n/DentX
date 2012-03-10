#include "advancedpagewidget.h"
#include "databasepagewidget.h"
#include "generalpagewidget.h"
#include "lookpagewidget.h"
#include "clinicpagewidget.h"
#include "preferences.h"

#include "preferencesdialog.h"

#include <QtGui>

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
{
    createMainPage();
    createLookPage();
    createAdvancedPage();
    createDatabasePage();
    createClinicPage();
    createStackedLayout();
    createButtons();
    createLayout();

    advancedPage->readSettings();
    databasePage->readSettings();
    clinicPage->readSettings();
    mainPage->readSettings();
    lookPage->readSettings();

    preferences = Preferences::getInstance();

    setWindowTitle( tr("Ustawienia") );
    resize(500, 400);
}

void PreferencesDialog::createButtons()
{
    okButton = new QPushButton(tr("OK"));
    okButton->setIcon(QIcon(":/icons/ok.png"));

    cancelButton = new QPushButton(tr("Anuluj"));
    cancelButton->setIcon(QIcon(":/icons/Cancel.png"));

    applyButton = new QPushButton(tr("Zastosuj"));

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(applyButton, SIGNAL(clicked()), this, SLOT(applyClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(applyButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addStretch();
    buttonsLayout->setDirection(QBoxLayout::RightToLeft);
}

void PreferencesDialog::applyClicked()
{
    createPrefernces();
}

void PreferencesDialog::okClicked()
{
    applyClicked();
    accept();
}

void PreferencesDialog::createLayout()
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 3);
    mainLayout->addWidget(listWidget, 0, 0);
    mainLayout->addLayout(stackedLayout, 0, 1);
    mainLayout->addLayout(buttonsLayout, 1, 0, 1, 2);
    setLayout(mainLayout);
}

void PreferencesDialog::createStackedLayout()
{
    listWidget = new QListWidget;
    listWidget->addItem(new QListWidgetItem(QIcon(":/icons/general.png"),tr("Podstawowe")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/icons/look.png"),tr("Wygląd")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/icons/clinic.png"), tr("Gabinet")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/icons/adcanced.png"),tr("Zaawansowane")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/icons/database.png"),tr("Baza danych")));

    stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(mainPage);
    stackedLayout->addWidget(lookPage);
    stackedLayout->addWidget(clinicPage);
    stackedLayout->addWidget(advancedPage);
    stackedLayout->addWidget(databasePage);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedLayout,
            SLOT(setCurrentIndex(int)));

    listWidget->setCurrentRow(0);
}

void PreferencesDialog::createClinicPage()
{
    clinicPage = new ClinicPageWidget;
}

void PreferencesDialog::createMainPage()
{
    mainPage = new GeneralPageWidget;
}

void PreferencesDialog::createDatabasePage()
{
    databasePage = new DatabasePageWidget;
}

void PreferencesDialog::createLookPage()
{
    lookPage = new LookPageWidget;
}

void PreferencesDialog::createAdvancedPage()
{
    advancedPage = new AdvancedPageWidget;
}

void PreferencesDialog::createPrefernces()
{

    preferences->setLanguage(mainPage->getLanguage());
    preferences->setSavePosition(mainPage->getSavePosition());
    preferences->setAlwaysMax(mainPage->getAlwaysMax());
    preferences->setCloseQuestion(mainPage->getCloseCheck());

    preferences->setMovableToolBar(lookPage->getMovableToolBar());
    preferences->setPositionToolBar(lookPage->getPosition());

    preferences->setDatabaseType(databasePage->getDatabaseType());
    preferences->setHostname(databasePage->getHostname());
    preferences->setUserName(databasePage->getUserName());
    preferences->setPassword(databasePage->getPasswordName());
    preferences->setDatabaseName(databasePage->getDatabaseName());
    preferences->setDatabaseType(databasePage->getDatabaseType());

    preferences->setDynamicSearch(advancedPage->getDynamicSearch());

    preferences->setStartTime(clinicPage->getStartTime());
    preferences->setEndTime(clinicPage->getEndTime());
    preferences->setMonday(clinicPage->getMonday());
    preferences->setTuesday(clinicPage->getTuesday());
    preferences->setWednesday(clinicPage->getWednesday());
    preferences->setThursday(clinicPage->getThursday());
    preferences->setFriday(clinicPage->getFriday());
    preferences->setSaturday(clinicPage->getSaturday());
    preferences->setSunday(clinicPage->getSunday());
}


