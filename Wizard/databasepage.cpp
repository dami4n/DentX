#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDir>

#include "databasepage.h"

DatabasePage::DatabasePage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle( tr("Ustawienia bazy danych"));
    setSubTitle( tr("Wybierz baze danych"));

    createGui();
    createLayout();

    databaseComboboxChanged(0);
}


void DatabasePage::createGui()
{
    databaseTypeLabel = new QLabel( tr("Typ bazy danych: ") );
    databaseTypeLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    databaseTypeComboBox = new QComboBox;
    databaseTypeComboBox->addItem( tr("Lokalnie zapisana baza SQLite"));
    databaseTypeComboBox->addItem( tr("Baza MySQL") );
    connect(databaseTypeComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(databaseComboboxChanged(int)));

    getPathButton = new QPushButton( tr("Przeglądaj...") );

    pathLabel = new QLabel( tr("Miejsce zapisu: "));
    hostLabel = new QLabel( tr("Host: "));
    databaseNameLabel = new QLabel( tr("Nazwa bazy danych"));
    userNameLabel = new QLabel( tr("Nazwa użytkownika"));
    passwordLabel = new QLabel( tr("Hasło: "));

    hostnameLineEdit = new QLineEdit;
    databaseNameLineEdit= new QLineEdit;
    userNameLineEdit= new QLineEdit;
    passwordLineEdit= new QLineEdit;

    pathLineEdit = new QLineEdit;
    pathLineEdit->setText(QDir::homePath());
}

void DatabasePage::createLayout()
{
    formLayout = new QFormLayout;
    formLayout->addRow(hostLabel, hostnameLineEdit);
    formLayout->addRow(databaseNameLabel, databaseNameLineEdit );
    formLayout->addRow(userNameLabel, userNameLineEdit );
    formLayout->addRow(passwordLabel, passwordLineEdit);

    QHBoxLayout *databaseTypeLayout = new QHBoxLayout;
    databaseTypeLayout->addWidget(databaseTypeLabel);
    databaseTypeLayout->addWidget(databaseTypeComboBox);

    QHBoxLayout *sqliteLayout = new QHBoxLayout;
    sqliteLayout->addWidget(pathLabel);
    sqliteLayout->addWidget(pathLineEdit);
    sqliteLayout->addWidget(getPathButton);
    //sqliteLayout->addStretch();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(databaseTypeLayout);
    layout->addSpacing(20);
    layout->addLayout(formLayout);
    layout->addLayout(sqliteLayout);
    layout->addStretch();

    setLayout(layout);
}

void DatabasePage::databaseComboboxChanged(int value)
{
    if( value == 0 ) // SQLite
    {
        showSqlite(true);
        showMySql(false);

    }

    if( value == 1 ) // MySQL
    {
        showSqlite(false);
        showMySql(true);
    }
}

void DatabasePage::showMySql(bool value)
{
    if( value )
    {
        hostLabel->show();
        databaseNameLabel->show();
        userNameLabel->show();
        passwordLabel->show();

        hostnameLineEdit->show();
        databaseNameLineEdit->show();
        userNameLineEdit->show();
        passwordLineEdit->show();
    }
    else
    {
        hostLabel->hide();
        databaseNameLabel->hide();
        userNameLabel->hide();
        passwordLabel->hide();

        hostnameLineEdit->hide();
        databaseNameLineEdit->hide();
        userNameLineEdit->hide();
        passwordLineEdit->hide();
    }
}

void DatabasePage::showSqlite(bool value)
{
    if( value )
    {
        pathLabel->show();
        pathLineEdit->show();
        getPathButton->show();
    }
    else
    {
        pathLabel->hide();
        pathLineEdit->hide();
        getPathButton->hide();
    }
}

