#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include "Preferences/preferences.h"

#include "databasepagewidget.h"

DatabasePageWidget::DatabasePageWidget(QWidget *parent) :
    QWidget(parent)
{
    preferences = Preferences::getInstance();

    createGui();
    createLayout();
}

void DatabasePageWidget::createGui()
{
    databaseTypeLabel = new QLabel( tr("Typ bazy danych: ") );
    databaseTypeLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    databaseTypeComboBox = new QComboBox;
    databaseTypeComboBox->addItem( tr("Lokalnie zapisana baza SQLite"));
    databaseTypeComboBox->addItem( tr("Baza MySQL") );
    connect(databaseTypeComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(databaseComboboxChanged(int)));

    hostnameLineEdit = new QLineEdit;
    databaseNameLineEdit= new QLineEdit;
    userNameLineEdit= new QLineEdit;
    passwordLineEdit= new QLineEdit;
}

void DatabasePageWidget::createLayout()
{
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("Host:"), hostnameLineEdit);
    formLayout->addRow(tr("Nazwa bazy danych: "), databaseNameLineEdit );
    formLayout->addRow(tr("Nazwa użytkownik: "), userNameLineEdit );
    formLayout->addRow(tr("Hasło: "), passwordLineEdit);

    QHBoxLayout *databaseTypeLayout = new QHBoxLayout;
    databaseTypeLayout->addWidget(databaseTypeLabel);
    databaseTypeLayout->addWidget(databaseTypeComboBox);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(databaseTypeLayout);
    layout->addSpacing(20);
    layout->addLayout(formLayout);
    layout->addStretch();

    setLayout(layout);
}

void DatabasePageWidget::databaseComboboxChanged(int value)
{
    if( value == 0 ) // SQLite
    {
        setSqlite(true);
    }

    if( value == 1 ) // MySQL
    {
        setSqlite(false);
    }
}

void DatabasePageWidget::setSqlite(bool value)
{
    hostnameLineEdit->setEnabled(!value);
    databaseNameLineEdit->setEnabled(!value);
    userNameLineEdit->setEnabled(!value);
    passwordLineEdit->setEnabled(!value);
}

int DatabasePageWidget::getDatabaseType()
{
    if(databaseTypeComboBox->currentIndex() == 0)
        return Preferences::SQLITE;
    if(databaseTypeComboBox->currentIndex() == 1)
        return Preferences::MYSQL;

    return -1;
}

void DatabasePageWidget::readSettings()
{
    hostnameLineEdit->setText(preferences->getHostname());
    databaseNameLineEdit->setText(preferences->getDatabaseName());
    userNameLineEdit->setText(preferences->getUserName());
    passwordLineEdit->setText(preferences->getPassword());

    if(preferences->getDatabaseType() == Preferences::SQLITE)
    {
        databaseTypeComboBox->setCurrentIndex(0);
        setSqlite(true);
    }
    if(preferences->getDatabaseType() == Preferences::MYSQL)
    {
        databaseTypeComboBox->setCurrentIndex(1);
        setSqlite(false);
    }
}
