#include <QtGui>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include "timesheet.h"

Timesheet::Timesheet(QWidget *parent) :
    QWidget(parent)
{

    setSpecialCellColor(QColor("#A8D4FF"));
    createTable();
    createVisitTypeMap();
    createColorComboBox();
    createSearchPatient();
    createToolButton();
    createDateLabel();
    createCalendar();
    createLine();

    createLayout();

    resize(1000, 700);
}

// zrobić szerszy searchPatientLineEdit

void Timesheet::createLayout()
{
    QHBoxLayout *visitTypeLayout = new QHBoxLayout;
    visitTypeLayout->addWidget(visitTypeLabel);
    visitTypeLayout->addWidget(visitTypeComboBox);
    visitTypeLayout->addStretch();

    QHBoxLayout *searchPatientLayout = new QHBoxLayout;
    searchPatientLayout->addWidget(searchPatientLabel);
    searchPatientLayout->addWidget(searchPatientLineEdit);
    searchPatientLayout->addWidget(newVisitButton);

    QHBoxLayout *upLayout = new QHBoxLayout;
    upLayout->addLayout(visitTypeLayout);
    upLayout->addStretch();
    upLayout->addLayout(searchPatientLayout);

    QVBoxLayout *calendarLayout = new QVBoxLayout;
    calendarLayout->setAlignment(this, Qt::AlignCenter);
    calendarLayout->addWidget(pushCalendar);
    calendarLayout->addWidget(calendarButton);

    QHBoxLayout *arrowsLayout = new QHBoxLayout;
    arrowsLayout->addWidget(leftToolButton);
    arrowsLayout->addLayout(calendarLayout);
    arrowsLayout->addWidget(rightToolButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(arrowsLayout);
    layout->addWidget(lineDown);
    layout->addWidget(tableWidget);
    layout->addWidget(lineUp);
    layout->addLayout(upLayout);

    setLayout(layout);

}


void Timesheet::createLine()
{
    lineUp = new QFrame;
    lineUp->setLineWidth(2);
    lineUp->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lineUp->setFrameShape(QFrame::HLine);

    lineDown = new QFrame;
    lineDown->setLineWidth(2);
    lineDown->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lineDown->setFrameShape(QFrame::HLine);
}


void Timesheet::createTable()
{
    tableWidget = new QTableWidget(2,2);
    tableWidget->horizontalHeader()->hide();
    tableWidget->verticalHeader()->hide();
    tableWidget->resizeRowsToContents();
    tableWidget->resizeColumnsToContents();
    tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    selectionEnabled(false);

    QTableWidgetItem *item =  new QTableWidgetItem(tr("Godzina / Dzień"));
    item->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable);
    item->setData(Qt::BackgroundColorRole, color);
    tableWidget->setItem(0, 0, item);    

    createHorizontalLabels();
    createVerticalLabels(9, 18);
 }


void Timesheet::selectionEnabled(bool value)
{
   if(value)
        tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
   else
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
}


void Timesheet::createHorizontalLabels()
{
    dayStringList << tr("Poniedziałek")
                  << tr("Wtorek")
                  << tr("Środa")
                  << tr("Czwartek")
                  << tr("Piątek")
                  << tr("Sobota")
                  << tr("Niedziela");

    tableWidget->setColumnCount(dayStringList.size() + 1);

    for(int i = 0; i < dayStringList.size(); ++i)
    {
        dayList << new QTableWidgetItem(dayStringList[i]);
        dayList[i]->setData(Qt::BackgroundColorRole, color);
        dayList[i]->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable);
        tableWidget->setItem(0, i + 1, dayList[i]);
        tableWidget->setFont(QFont("arial",7));
    }

    setLabels(QDate::currentDate());
}


void Timesheet::setLabels(QDate date)
{
    QDate start = getFirstDayOfWeek(date);

    dayStringList[0] = start.toString();
    dayStringList[1] = start.addDays(1).toString();
    dayStringList[2] = start.addDays(2).toString();
    dayStringList[3] = start.addDays(3).toString();
    dayStringList[4] = start.addDays(4).toString();
    dayStringList[5] = start.addDays(5).toString();
    dayStringList[6] = start.addDays(6).toString();

    for(int i = 0; i < dayStringList.size(); ++i)
    {
        tableWidget->item(0, i+1)->setText(dayStringList[i]);
    }
}


void Timesheet::setSelectionColor(QColor color)
{
    selectionColor = color;

    QString styleSheetString = "QTableView::item:selected { background-color: "
                               % selectionColor.name() % "}"
                               "QTableView::item:disabled { color: black }"
                               "QTableWidget { gridline-color: #474747 } ";

    setStyleSheet( styleSheetString );
}


void Timesheet::createVerticalLabels(int start, int end)
{
    int row = 1;

    tableWidget->setRowCount((end-start)*4 + 1);

    for(int i = start; i <= end; ++i)
    {
        QTableWidgetItem *item1 =  new QTableWidgetItem(QString::number(i) % ":00");
        QTableWidgetItem *item2 =  new QTableWidgetItem(QString::number(i) % ":15");
        QTableWidgetItem *item3 =  new QTableWidgetItem(QString::number(i) % ":30");
        QTableWidgetItem *item4 =  new QTableWidgetItem(QString::number(i) % ":45");

        item1->setData(Qt::BackgroundColorRole, color);
        item2->setData(Qt::BackgroundColorRole, color);
        item3->setData(Qt::BackgroundColorRole, color);
        item4->setData(Qt::BackgroundColorRole, color);

        item1->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable);
        item2->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable);
        item3->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable);
        item4->setFlags(Qt::ItemIsEditable|Qt::ItemIsSelectable);

        tableWidget->setItem(row++, 0, item1);
        tableWidget->setItem(row++, 0, item2);
        tableWidget->setItem(row++, 0, item3);
        tableWidget->setItem(row++, 0, item4);
    }
}


void Timesheet::setSpecialCellColor(QColor newColor)
{
    color = newColor;
}


void Timesheet::createVisitTypeMap()
{
    visitTypeMap[tr("Wizyta podstawowa")] = Qt::green;
    visitTypeMap[tr("Wizyta kontrolna")] = Qt::gray;
    visitTypeMap[("Przegląd")] = Qt::yellow;
    visitTypeMap[("Usunięcie zęba")] = Qt::red;
}

void Timesheet::addVisitType(QString type, QColor color)
{
    visitTypeMap[type] = color;
}

void Timesheet::createColorComboBox()
{
    visitTypeLabel = new QLabel( tr("Typ wizyty: ") );

    visitTypeComboBox = new QComboBox;

    int i = 0;
    QMap<QString, QColor>::iterator visitTypeIterator = visitTypeMap.begin();
    while(visitTypeIterator!=visitTypeMap.end())
    {
        visitTypeComboBox->insertItem(i, visitTypeIterator.key());
        visitTypeComboBox->setItemData(i, visitTypeIterator.value(), Qt::DecorationRole);
        ++visitTypeIterator;
        ++i;
    }

    connect(visitTypeComboBox, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(visitTypeChanged(QString)));

    visitTypeComboBox->setCurrentIndex(3);
}


void Timesheet::createSearchPatient()
{
    searchPatientLabel = new QLabel( tr("Wybierz pacjenta: ") );
    searchPatientLineEdit = new QLineEdit;
    searchPatientLineEdit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    connect(searchPatientLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(lineEditChanged()));

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT lastname || \" \" ||  name || \" \" || address  FROM patient");

    while ( model->canFetchMore() )
      model->fetchMore();

    QCompleter *completer = new QCompleter;
    completer->setModel(model);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    searchPatientLineEdit->setCompleter(completer);

    newVisitButton = new QPushButton( tr("Nowa wizyta") );
    newVisitButton->setEnabled(false);
    connect(newVisitButton, SIGNAL(clicked()), this, SLOT(newVisit()));
}


void Timesheet::visitTypeChanged(QString name)
{
    QColor newColor = visitTypeMap[name];
    setSelectionColor(newColor);
}


void Timesheet::newVisit()
{

    if( newVisitButton->text() == tr("Ok") )
    {
        okClicked();
        selectionEnabled(false);
        newVisitButton->setText( tr("Nowa wizyta") );
    }
    else
    {
        selectionEnabled(true);
        newVisitButton->setText( tr("Ok") );
    }

}


void Timesheet::lineEditChanged()
{
    if( searchPatientLineEdit->text().isEmpty() )
    {
        newVisitButton->setEnabled(false);
    }
    else
    {
        newVisitButton->setEnabled(true);
    }
}


void Timesheet::okClicked()
{
    QItemSelectionModel *indexList = tableWidget->selectionModel();
    QModelIndexList list = indexList->selectedIndexes();

    int selectionSize = list.size();
    QString patient = searchPatientLineEdit->text();

    for(int i = 0; i < selectionSize; ++i)
    {
        QTableWidgetItem *item = new QTableWidgetItem(patient);
        item->setData(Qt::BackgroundRole, selectionColor);
        tableWidget->setItem(list.at(i).row(), list.at(i).column(), item);
    }

    tableWidget->clearSelection();
}


void Timesheet::createToolButton()
{
    leftToolButton = new QToolButton;
    leftToolButton->setIcon(QIcon(":/icons/left.png"));
    leftToolButton->setArrowType(Qt::NoArrow);
    connect(leftToolButton, SIGNAL(clicked()), this, SLOT(leftClicked()));

    rightToolButton = new QToolButton;
    rightToolButton->setIcon(QIcon(":/icons/right.png"));
    rightToolButton->setArrowType(Qt::NoArrow);
    connect(rightToolButton, SIGNAL(clicked()), this, SLOT(rightClicked()));
}


void Timesheet::leftClicked()
{
    QDate date = pushCalendar->selectedDate();
    QDate first = getFirstDayOfWeek(date);
    setLabels(first.addDays(-7));
    pushCalendar->setSelectedDate(first.addDays(-7));

}


void Timesheet::rightClicked()
{
    QDate date = pushCalendar->selectedDate();
    QDate first = getFirstDayOfWeek(date);
    setLabels(first.addDays(7));
    pushCalendar->setSelectedDate(first.addDays(7));
}


void Timesheet::createDateLabel()
{
    calendarButton = new QPushButton;
    calendarButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    calendarButton->setText( tr("Pokaż kalendarz") );
    calendarButton->setIcon(QIcon(":/icons/Calendar.png")); // licencja ikonki
    connect(calendarButton, SIGNAL(clicked()), this, SLOT(selectDateClicked()));

}


void Timesheet::selectDateClicked()
{
    if( pushCalendar->isHidden() )
    {
        pushCalendar->show();
        calendarButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        calendarButton->setText( tr("Ukryj kalendarz") );
    }
    else
    {
        pushCalendar->hide();
        calendarButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        calendarButton->setText( tr("Pokaż kalendarz") );
    }
}


void Timesheet::setButtonDate(QDateTime time)
{
    QString start = time.toString("dd.mm.yyyy");
    QString end = time.addDays(7).toString("dd.mm.yyyy");

    QString text = start % " - " % end;

    calendarButton->setText(text);
}


void Timesheet::createCalendar()
{
    pushCalendar = new QCalendarWidget;
    pushCalendar->setFirstDayOfWeek(Qt::Monday);
    pushCalendar->setGridVisible(true);
    pushCalendar->setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);
    pushCalendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    pushCalendar->setSelectionMode(QCalendarWidget::SingleSelection);
    pushCalendar->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
    pushCalendar->hide();

    connect(pushCalendar, SIGNAL(selectionChanged()), this, SLOT(dateSelectionChanged()));
}


void Timesheet::dateSelectionChanged()
{
    setLabels(pushCalendar->selectedDate());
    qDebug() << getFirstDayOfWeek(pushCalendar->selectedDate()).toString();

}


QDate Timesheet::getFirstDayOfWeek(QDate day)
{
   return day.addDays(-(day.dayOfWeek()-1));
}


void Timesheet::save()
{


}

void Timesheet::load()
{



}

void Timesheet::saveDay(QDateTime day)
{
    QString dayString = day.toString("yyyy-MM-dd");
    QSqlQuery query;

    query.prepare("SELECT * FROM timesheet"
                  " WHERE date = :dateValue");
    query.bindValue(":dateValue", dayString);

    bool value = query.exec();

    if( !value )
    {
        qDebug() << query.lastError();
        return;
    }

    if( query.next() )
    {
         //UPDATE
    }
    else
    {
         //INSERT
    }
}

//QString Timesheet::saveDayToString(QString day)
//{


//}


