#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include "Preferences/preferences.h"
#include "advancedpagewidget.h"

AdvancedPageWidget::AdvancedPageWidget(QWidget *parent) :
    QWidget(parent)
{
    preferences = Preferences::getInstance();

    createGui();
    createLayout();
}


void AdvancedPageWidget::createGui()
{
    dynamicSearchCheckBox = new QCheckBox(tr("Wyłącz dynamiczne wyszukiwanie"));
}

void AdvancedPageWidget::createLayout()
{
    QGroupBox *showPatientsGroupBox = new QGroupBox(tr("Pokaż pacjentów"));
    QVBoxLayout *showPatientsLayout = new QVBoxLayout;
    showPatientsLayout->addWidget(dynamicSearchCheckBox);
    showPatientsLayout->addStretch();
    showPatientsGroupBox->setLayout(showPatientsLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(showPatientsGroupBox);
    mainLayout->addStretch();

    setLayout(mainLayout);
}

void AdvancedPageWidget::readSettings()
{
    dynamicSearchCheckBox->setChecked( preferences->getDynamicSearch() );
}
