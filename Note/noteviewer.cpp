#include <QtGui>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QStringBuilder>
#include "notefunction.h"
#include "Note/shownotedialog.h"
#include "Preferences/preferences.h"

#include "noteviewer.h"

NoteViewer::NoteViewer(QWidget *parent) :
    QWidget(parent)
{   

    preferences = Preferences::getInstance();

    createTableView();
    createSearchGUI();
    createLayout();

    NoteFunction *noteFunction = new NoteFunction;

    connect(noteFunction, SIGNAL(changed()), this, SLOT(changed()));
}

void NoteViewer::createSearchGUI()
{
    showLabel = new QLabel(tr("Pokaż notatki: "));

    showNoteComboBox = new QComboBox;
    showNoteComboBox->addItem( tr("Wszystkie") );   
    showNoteComboBox->addItem( tr("Dodane dzisiaj") );
    showNoteComboBox->addItem( tr("Dodane przez ostatnie 7 dni") );
    showNoteComboBox->addItem( tr("Dodane przez ostatnie 30 dni") );

    connect(showNoteComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setTime(int)));

    searchLabel = new QLabel( tr("Wyszukaj w treści") );

    searchLineEdit = new QLineEdit;

    searchButton = new QPushButton( tr("Szukaj") );
    searchButton->setIcon(QIcon(":/icons/Search.png"));

    connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));

    connect(searchLineEdit, SIGNAL(returnPressed()),
            searchButton, SIGNAL(clicked()));
}


void NoteViewer::createTableView()
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
            this, SLOT(showNote(QModelIndex)));

    model = new QSqlQueryModel;

    if( preferences->getDatabaseType() == Preferences::SQLITE )
    {
        model->setQuery("SELECT topic, dateAdded, "
                        "SUBSTR(text, 1, 20) || '(...)'"
                        "FROM note"
                        );
    }

    if( preferences->getDatabaseType() == Preferences::MYSQL )
    {
        qDebug() << "MYSQL";
        model->setQuery("SELECT topic, dateAdded, "
                        "CONCAT( SUBSTR(text, 1, 20),  '(...)')"
                        "FROM note"
                        );
    }


    updateColumnsName();

    tableView->setModel(model);

}

void NoteViewer::createLayout()
{
    QHBoxLayout *searchLayout = new QHBoxLayout;
    searchLayout->addWidget(showLabel);
    searchLayout->addWidget(showNoteComboBox);
    searchLayout->addStretch();
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(searchButton);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(searchLayout);
    layout->addWidget(tableView);

    setLayout(layout);
}

void NoteViewer::updateColumnsName()
{
    model->setHeaderData(0, Qt::Horizontal, tr("Tytuł"));
    model->setHeaderData(1, Qt::Horizontal, tr("Data dodanie"));
    model->setHeaderData(2, Qt::Horizontal, tr("Treść"));
}

void NoteViewer::changed()
{
     search();
     updateColumnsName();
}

void NoteViewer::search()
{
    QString search = searchLineEdit->text();
    setFilter(search);
}

void NoteViewer::setFilter(QString search)
{
    QString query;

    if( preferences->getDatabaseType() == Preferences::SQLITE )
    {
        query = "SELECT topic, dateAdded, "
                "SUBSTR(text, 1, 20) || '(...)' "
                "FROM note "
                "WHERE (text LIKE '%" % search % "%' "
                "OR topic LIKE '%" % search % "%')"
                % dateFilterString % ";";
    }

    if( preferences->getDatabaseType() == Preferences::MYSQL )
    {
        query = "SELECT topic, dateAdded, "
                "CONCAT( SUBSTR(text, 1, 20), '(...)' ) "
                "FROM note "
                "WHERE (text LIKE '%" % search % "%' "
                "OR topic LIKE '%" % search % "%')"
                % dateFilterString % ";";
    }

    qDebug() << query;

    model->setQuery(query);

    updateColumnsName();
}

void NoteViewer::showNote(QModelIndex index)
{
    QSqlRecord record = model->record(index.row());
    QString date = record.value(1).toString();
    QString topic = record.value(0).toString();

    QSqlQuery query;

    QString queryString = "SELECT textHtml FROM note "
                    "WHERE topic = '" % topic % "' AND "
                    "dateAdded = '" % date % "';";

    query.exec(queryString);

    qDebug() << query.lastQuery();

    if( query.next() )
    {
        QString text = query.value(0).toString();
        ShowNoteDialog *noteDialog = new ShowNoteDialog;
        noteDialog->setNote(topic, text);

        noteDialog->exec();
    }

}

void NoteViewer::setTime(int time)
{
    switch(time)
    {
    case ALL:
        dateFilterString = "";
        break;

    case TODAY:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateSQL "
                               "BETWEEN date('now') AND date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::MYSQL )
        {
            dateFilterString = " AND (dateSQL "
                               "BETWEEN date('now') AND date('now'))";
        }
        break;

    case LASTWEEK:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateSQL "
                               "BETWEEN date('now', '-7 day') AND date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateSQL "
                               "BETWEEN date('now', '-7 day') AND date('now'))";
        }
        break;

    case LASTMONTH:

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateSQL "
                               "BETWEEN date('now', '-30 day') AND date('now'))";
        }

        if( preferences->getDatabaseType() == Preferences::SQLITE )
        {
            dateFilterString = " AND (dateSQL "
                               "BETWEEN date('now', '-30 day') AND date('now'))";
        }
        break;
    }

    search();
}











