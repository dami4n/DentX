#include <QtGui>
#include <QTabWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "radiograph.h"
#include "colorbuttons.h"
#include "descriptionwidget.h"

#include "actiontabs.h"

ActionTabs::ActionTabs(QWidget *parent) :
    QWidget(parent)
{
    createButtonsTab();
    createDescriptionTab();
    createDiagnosisTab();
    createPlanTextEdit();
    createRadiograph();
    createTabs();
}

void ActionTabs::createButtonsTab()
{
    colorButtons = new ColorButtons;
}

void ActionTabs::createDescriptionTab()
{
   descriptionWidget = new DescriptionWidget;
}

void ActionTabs::createDiagnosisTab()
{
    diagnosisTextEdit = new QTextEdit;
}

void ActionTabs::createPlanTextEdit()
{
    planTextEdit = new QTextEdit;
}

void ActionTabs::createRadiograph()
{
    radiograph = new Radiograph;
}

void ActionTabs::createTabs()
{
    tabWidget = new QTabWidget;

    tabWidget->addTab(colorButtons, tr("Oznacz na diagramie") );
    tabWidget->addTab(descriptionWidget, tr("Opis wizyty"));
    tabWidget->addTab(diagnosisTextEdit, tr("Rozpoznanie"));
    tabWidget->addTab(planTextEdit, tr("Plan leczenia"));
    tabWidget->addTab(radiograph, tr("Zdjęcia"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tabWidget);

    setLayout(layout);
}

QString ActionTabs::getDiagnosis() const
{
    return diagnosisTextEdit->toPlainText();
}

QString ActionTabs::getPlan() const
{
    return planTextEdit->toPlainText();
}

void ActionTabs::setPlan(QString value)
{
    planTextEdit->setText(value);
}

void ActionTabs::setDiagnosis(QString value)
{
    diagnosisTextEdit->setText(value);
}
