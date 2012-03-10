#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include "Preferences/preferences.h"

#include "lookpagewidget.h"

LookPageWidget::LookPageWidget(QWidget *parent) :
    QWidget(parent)
{
    preferences = Preferences::getInstance();

    createGui();
    createLayout();
}

void LookPageWidget::createGui()
{
    movableToolBarCheckBox = new QCheckBox( tr("Zablokuj pasek narzędiowy"));

    positionComboBox = new QComboBox;
    positionComboBox->addItem(tr("góra"));
    positionComboBox->addItem(tr("dół"));
    positionComboBox->addItem(tr("lewo"));
    positionComboBox->addItem(tr("prawo"));
    positionComboBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

}

void LookPageWidget::createLayout()
{
    QGroupBox *toolbarGroupBox = new QGroupBox(tr("Pasek narzędziowy"));

    QFormLayout *positionToolbarLayout = new QFormLayout;
    positionToolbarLayout->addRow(tr("Umiejscowienie paska narzędziowego:"), positionComboBox);

    QVBoxLayout *toolbarLayout = new QVBoxLayout;
    toolbarLayout->addLayout(positionToolbarLayout);
    toolbarLayout->addWidget(movableToolBarCheckBox);
    toolbarLayout->addStretch();

    toolbarGroupBox->setLayout(toolbarLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(toolbarGroupBox);

    setLayout(mainLayout);
}

void LookPageWidget::readSettings()
{
    movableToolBarCheckBox->setChecked( preferences->getMovableToolBar() );
}

