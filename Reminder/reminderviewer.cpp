#include <QtGui>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QStringBuilder>
#include "showreminderdialog.h"
#include "Preferences/preferences.h"

#include "reminderviewer.h"

ReminderViewer::ReminderViewer(QWidget *parent) :
    QWidget(parent)
{
    preferences = Preferences::getInstance();

    createTableView();
    createSearchGUI();
    createLayout();

    setTime(NOW); // Pokaż aktualne
}


void ReminderViewer::createSearchGUI()
{
    showLabel = new QLabel(tr("Pokaż przypomnienia: "));

    showReminderComboBox = new QComboBox;
    showReminderComboBox->addItem( tr("Aktualne") );
    showReminderComboBox->addItem( tr("Zaplanowane na dzisiaj") );
    showReminderComboBox->addItem( tr("Zaplanowane na 7 dni") );
    showReminderComboBox->addItem( tr("Zaplanowane na 30 dni") );
    showReminderComboBox->addItem( tr("Zaplanowane na 365 dni") );
    showReminderComboBox->addItem( tr("Wszystkie") );

    connect(showReminderComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setTime(int)));

    searchLabel = new QLabel( tr("Wyszukaj w treści") );

    searchLineEdit = new QLineEdit;

    searchButton = new QPushButton( tr("Szukaj") );
    searchButton->setIcon(QIcon(":/icons/Search.png"));

    connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));

    connect(searchLineEdit, SIGNAL(returnPressed()),
            searchButton, SIGNAL(clicked()));
}


void ReminderViewer::createTableView()
{
    tableView = new QTableView;
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->resizeColumnsToContents();
    tableView->setShowGrid(false);
    tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->hide();

    connect( tableView->horizontalHeader(), SIGNAL(sectionClicked(int)),
             tableView, SLOT(sortByColumn(int)));

    connect(tableView, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(showReminder(QModelIndex)));

    model = new QSqlQueryModel;    

    if( preferences->getDatabaseType() == Preferences::SQLITE )
    {
        model->setQuery("SELECT topic, dateAdded, dateReminder, priority, "
                        "SUBSTR(text, 1, 20) || '(...)' "
                        "FROM reminder"
                        );
    }

    if( preferences->getDatabaseType() == Preferences::MYSQL )
    {
        model->setQuery("SELECT topic, dateAdded, dateReminder, priority, "
                        "CONCAT( SUBSTR(text, 1, 20), '(...)') "
                        "FROM reminder"
                        );
    }

    updateColumnsName();

    tableView->setModel(model);

}


void ReminderViewer::createLayout()
{
    QHBoxLayout *searchLayout = new QHBoxLayout;
    searchLayout->addWidget(showLabel);
    searchLayout->addWidget(showReminderComboBox);
    searchLayout->addStretch();
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(searchButton);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(searchLayout);
    layout->addWidget(tableView);

    setLayout(layout);
}

void ReminderViewer::updateColumnsName()
{
    model->setHeaderData(0, Qt::Horizontal, tr("Tytuł"));
    model->setHeaderData(1, Qt::Horizontal, tr("Data dodanie"));
    model->setHeaderData(2, Qt::Horizontal, tr("Data przypomnienia"));
    model->setHeaderData(3, Qt::Horizontal, tr("Priorytet"));
    model->setHeaderData(4, Qt::Horizontal, tr("Treść"));
}

void ReminderViewer::changed()
{
     search();
     updateColumnsName();
}

void ReminderViewer::search()
{
    QString search = searchLineEdit->text();
    setFilter(search);
}

void ReminderViewer::setFilter(QString search)
{
    QString query;

    if( preferences->getDatabaseType() == Preferences::SQLITE )
    {
           query = "SELECT topic, dateAdded, dateReminder, priority,"
                    "SUBSTR(text, 1, 20) || '(...)' "
                    "FROM reminder "
                    "WHERE (text LIKE '%" % search % "%' "
                    "OR topic LIKE '%" % search % "%')"
                    % dateFilterString % ";";
    }

    if( preferences->getDatabaseType() == Preferences::MYSQL )
    {
           query = "SELECT topic, dateAdded, dateReminder, priority,"
                    "CONCAT( SUBSTR(text, 1, 20), '(...)') "
                    "FROM reminder "
                    "WHERE (text LIKE '%" % search % "%' "
                    "OR topic LIKE '%" % search % "%')"
                    % dateFilterString % ";";
    }

    qDebug() << query;

    model->setQuery(query);

    updateColumnsName();
}

void ReminderViewer::showReminder(QModelIndex index)
{
    QSqlRecord record = model->record(index.row());

    QString topic = record.value(0).toString();
    QString dateAdded = record.value(1).toString();
    QString date = record.value(2).toString();
    QString priority = record.value(3).toString();

    QSqlQuery query;

    QString queryString = "SELECT textHtml FROM reminder "
                    "WHERE topic = '" % topic % "' AND "
                    "dateAdded = '" % dateAdded % "';";

    query.exec(queryString);

    qDebug() << query.lastQuery();

    if( query.next() )
    {
        QString text = query.value(0).toString();
        ShowReminderDialog *reminderDialog = new ShowReminderDialog;
        reminderDialog->setReminder(topic, text, date, priority);

        reminderDialog->exec();
    }

}

void ReminderViewer::setTime(int time)
{
    switch(time)
    {
    case NOW:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "> date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::MYSQL )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "> date('now'))";
        }

        break;


    case TODAY:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "BETWEEN date('now')"
                               "AND date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::MYSQL )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "BETWEEN date('now')"
                               "AND date('now'))";
        }

        break;

    case WEEK:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "BETWEEN date('now', '7 day')"
                               "AND date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::MYSQL )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "BETWEEN date('now', '7 day')"
                               "AND date('now'))";
        }


        break;

    case MONTH:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateReminderSQL "
                              "BETWEEN date('now', '30 day')"
                              "AND date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::MYSQL )
        {
            dateFilterString = " AND (dateReminderSQL "
                              "BETWEEN date('now', '30 day')"
                              "AND date('now'))";
        }

        break;

    case YEAR:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "BETWEEN date('now', '365 day')"
                               "AND date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::MYSQL )
        {
            dateFilterString = " AND (dateReminderSQL "
                               "BETWEEN date('now', '365 day')"
                               "AND date('now'))";
        }

        break;

    case ALL:
        dateFilterString = "";
        break;

    }

    search();
}





