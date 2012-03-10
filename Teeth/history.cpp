#include <QtGui>
#include <QStringBuilder>
#include <QSqlQuery>
#include <QSqlError>
#include <QtAlgorithms>
#include "history.h"

History::History(QWidget *parent) :
    QWidget(parent)
{
    createListView();
    createMainLayout();

    connect(listView, SIGNAL(clicked(QModelIndex)), this, SLOT(clicked(QModelIndex)));

}

void History::createListView()
{
    listView = new QListView;
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    listView->setAlternatingRowColors(true);

}

void History::createMainLayout()
{
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(listView);

    setLayout(mainLayout);

}

void History::clicked(QModelIndex index)
{
    QString date = model->data(index, 0).toString();

    emit clicked(date);
}

void History::deleteSelected()
{

}

void History::createModel(const int newId)
{
    id = newId;

    model = new QStringListModel;
    createStringList();
    model->setStringList(stringList);

    listView->setModel(model);
}

QString History::getMilk(const QString data) const
{
    return milkTeethMap[data];
}

QString History::getSecond(const QString data) const
{
    return secondTeethMap[data];
}

int History::addNewAppointment(int id, QString milk, QString second)
{
    model->insertRow(0);
    model->setData(model->index(0), QDateTime::currentDateTime().toString());

    bool value = createNewAppintment(id, milk, second);

    if( !value )
        return -1;

    createStringList();

    return 1;
}

void History::createStringList()
{
    // za duża złożoność obliczeniowa
    // sortowanie, przepisywanie list, mapy...

    QString stringQuery = "SELECT * FROM history WHERE id = " % QString::number(id);
    QSqlQuery query;

    query.exec(stringQuery);

    while(query.next())
    {
        QString date = query.value(1).toString();
        dateList << QDateTime::fromString(date);

        milkTeethMap[date] = query.value(2).toString();
        secondTeethMap[date] = query.value(3).toString();
    }

    qSort(dateList.begin(), dateList.end(), qGreater<QDateTime>());

    for(int i = 0; i < dateList.size(); ++i)
        stringList << dateList.at(i).toString();
}

QString History::getId()
{
    QItemSelectionModel *sel = listView->selectionModel();
    QModelIndexList indexList = sel->selectedIndexes();

    QString date;
    if(indexList.size()) {
        date = indexList.at(0).data().toString();
    }
    else {
        return "";
    }

    QSqlQuery query;
    query.prepare("SELECT auto_id FROM history WHERE id = :id AND date = :date");
    query.bindValue(":id", id);
    query.bindValue(":date", date);
    query.exec();

    if(!query.next())
     return "";

    return query.value(0).toString();
}


QString History::getPlan()
{
    QString id = getId();

    QSqlQuery query;
    query.prepare("SELECT plan FROM history WHERE auto_id = :id");
    query.bindValue(":id", id);
    query.exec();

    if(!query.next())
     return "";

    return query.value(0).toString();
}


QString History::getDiagnosis()
{
    QString id = getId();

    QSqlQuery query;
    query.prepare("SELECT diagnosis FROM history WHERE auto_id = :id");
    query.bindValue(":id", id);
    query.exec();

    if(!query.next())
     return "";

    return query.value(0).toString();
}

bool History::save(int id, QString milk, QString second, QString plan, QString diagnosis)
{

    QItemSelectionModel *sel = listView->selectionModel();
    QModelIndexList indexList = sel->selectedIndexes();

    QString date;
    if(indexList.size()) {
        date = indexList.at(0).data().toString();
    }
    else {
        qDebug() << "Size: " << indexList.size();
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE history"
                  " SET milkteeth = :milkteeth,"
                  " secondteeth = :secondteeth,"
                  " plan = :plan,"
                  " diagnosis = :diagnosis"
                  " WHERE date = :date AND id = :id"
                  );

    query.bindValue(":id", id);
    query.bindValue(":date", date);
    query.bindValue(":milkteeth", milk);
    query.bindValue(":secondteeth", second);
    query.bindValue(":plan", plan);
    query.bindValue(":diagnosis", diagnosis);

    bool value = query.exec();
    createStringList();

    if( !value )
    {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();
        return value;
    }

    return value;
}

bool History::createNewAppintment(int id, QString milk, QString second)
{

    QSqlQuery query;
    query.prepare("INSERT INTO history (id, date, milkteeth, secondteeth)"
                  "VALUES (:id,:date,:milkteeth,:secondteeth)"
                  );

    QString date = QDateTime::currentDateTime().toString();

    query.bindValue(":id", QString::number(id) );
    query.bindValue(":date", date);
    query.bindValue(":milkteeth", milk);
    query.bindValue(":secondteeth", second);

    return query.exec();
}

int History::sizeHistory() const
{
    return stringList.size();
}
