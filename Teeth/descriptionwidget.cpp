#include <QToolButton>
#include <QTableView>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QSqlQueryModel>
#include "adddescriptiondialog.h"

#include "descriptionwidget.h"

DescriptionWidget::DescriptionWidget(QWidget *parent) :
    QWidget(parent)
{
    createGui();
    createTable();
    createLayout();
}


void DescriptionWidget::createGui()
{
    addToolButton = new QToolButton;
    addToolButton->setIcon(QIcon(":/icons/add_green.png"));
    connect(addToolButton, SIGNAL(clicked()), this, SLOT(addDescriptionClicked()));

    removeToolButton = new QToolButton;
    removeToolButton->setIcon(QIcon(":/icons/remove.png"));
}

void DescriptionWidget::createTable()
{
    tableView = new QTableView;
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->verticalHeader()->hide();
    tableView->setShowGrid(false);

    model = new QSqlQueryModel;
    model->setQuery("Select nnumber, description FROM teeth_description");

    tableView->setModel(model);

    updateColumnName();

}

void DescriptionWidget::updateColumnName()
{
    model->setHeaderData(0, Qt::Horizontal, tr("Ząb"));
    model->setHeaderData(1, Qt::Horizontal, tr("Wykonany zabieg"));
}

void DescriptionWidget::createLayout()
{
    QVBoxLayout *iconLayout = new QVBoxLayout;
    iconLayout->addWidget(addToolButton);
    iconLayout->addWidget(removeToolButton);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(iconLayout);
    mainLayout->addWidget(tableView);

    setLayout(mainLayout);
}

void DescriptionWidget::addDescriptionClicked()
{
    AddDescriptionDialog *add = new AddDescriptionDialog;
    if( add->exec() == QDialog::Accepted )
    {

    }
}


