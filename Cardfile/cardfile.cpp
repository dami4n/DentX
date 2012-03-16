#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QLineEdit>
#include <QAction>
#include <QDebug>
#include <QStringBuilder>
#include <QtSql>

#include "Teeth/diagramdialog.h"
#include "Database/database.h"
#include "patient.h"
#include "PatientDialog/showpatientdialog.h"
#include "cardfiletable.h"
#include "Pdf/pdfcreator.h"
#include "Database/databasepatient.h"

#include "cardfile.h"


CardFile::CardFile(QWidget *parent) :
    QWidget(parent)
{
    createLabels();
    createDictionary();
    createTable();
    createModel();
    createGui();

    setDynamicSearch(true);

    createLayout();
    createContextMenu();

    setMessageLabel();
}

void CardFile::createLabels()
{
        labels  << tr("Numer karty")
                << tr("Imię")
                << tr("Nazwisko")
                << tr("PESEL")
                << tr("Miasto")
                << tr("Adres")
                << tr("Telefon")
                << tr("Data rejestracji");
}


void CardFile::createDictionary()
{
    // potrzebne przy tłumaczeniu nazw kolumn, przy wyszukiwaniu
    // do frazy 'LIKE' w zapytaniu SQL

    dictionary[labels.at(0)] = "id";
    dictionary[labels.at(1)] = "name";
    dictionary[labels.at(2)] = "lastname";
    dictionary[labels.at(3)] = "pesel";
    dictionary[labels.at(4)] = "city";
    dictionary[labels.at(5)] = "address";
    dictionary[labels.at(6)] = "phone";
    dictionary[labels.at(7)] = "registrationdate";

}

void CardFile::createTable()
{
    cardfileTable = new CardfileTable;

    connect( cardfileTable, SIGNAL(doubleClicked(QModelIndex)),
             this, SLOT(itemDoubleClicked(QModelIndex)) );

//    QColor color(253,245,235);
//    cardfileTable->setTableColor(color);
}

void CardFile::createModel()
{
    model = new QSqlTableModel(this);
    model->setTable("patient");
    model->select();

    cardfileTable->setModel(model);
    cardfileTable->show();

    for( int i = 0; i < 31; ++i )
     cardfileTable->setColumnHidden(i, true);

    cardfileTable->setColumnHidden(0, false); // id
    cardfileTable->setColumnHidden(1, false); // name
    cardfileTable->setColumnHidden(2, false); // lastname
    cardfileTable->setColumnHidden(3, false); // pesel
    cardfileTable->setColumnHidden(4, false); // city
    cardfileTable->setColumnHidden(9, false); // address
    cardfileTable->setColumnHidden(10, false); // phone
    cardfileTable->setColumnHidden(15, false); // phone

    updateColumnName();
}

void CardFile::createGui()
{
    searchLineEdit = new QLineEdit;
    QTimer::singleShot(0, searchLineEdit, SLOT(setFocus()));

    searchButton = new QPushButton( tr("Szukaj") );
    searchButton->hide();
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchClicked()));

    QPixmap pixmap(":/icons/Search.png");
    searchImageLabel = new QLabel;
    searchImageLabel->setPixmap(pixmap);

    searchComboBox = new QComboBox;
    searchLabel = new QLabel( tr("Wyszukaj: ") );

    for(int i = 0; i < labels.size(); ++i )
    {
        searchComboBox->addItem( labels[i] );
    }
    searchComboBox->setCurrentIndex(2);

    messageLabel = new QLabel( tr("Znaleziono 0 pasujących wyników") );
    messageLabel->setFrameShape( QLabel::Panel );
    messageLabel->setFrameShadow( QLabel::Sunken );

    setWindowTitle( tr("Card File") );
}

void CardFile::lineEditChanged()
{
    // wybrać delikatniejsze kolory

    QString text = searchLineEdit->text();
    QColor color;

    if(text.isEmpty())
    {
       color = Qt::white;
    }
    else
    {
        if(rowCount() != 0)
            color = QColor("#CFE6FF");
        else
            color = QColor("#FFB7B8");
    }

    QPalette palette( searchLineEdit->palette() );
    palette.setColor( QPalette::Base, color );
    searchLineEdit->setPalette(palette);
}

void CardFile::createLayout()
{
    QHBoxLayout *upLayout = new QHBoxLayout;
    upLayout->addWidget(searchLabel);
    upLayout->addWidget(searchComboBox);
    upLayout->addWidget(searchLineEdit);
    upLayout->addWidget(searchImageLabel);
    upLayout->addWidget(searchButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(upLayout);
    mainLayout->addWidget(cardfileTable);
    mainLayout->addWidget(messageLabel);

    setLayout(mainLayout);
}


void CardFile::setDynamicSearch(bool value)
{
    if( !value )
    {
        searchButton->show();
        disconnect( searchLineEdit, SIGNAL(textChanged(QString)),
                 this, SLOT(searchChanged(QString)));
        disconnect( searchComboBox, SIGNAL(currentIndexChanged(int)),
                 this, SLOT(searchComboxChanged(int)));
        disconnect( searchComboBox, SIGNAL(currentIndexChanged(int)),
                 searchLineEdit, SLOT(setFocus()));
    }
    else
    {
        searchButton->hide();
        connect( searchLineEdit, SIGNAL(textChanged(QString)),
                 this, SLOT(searchChanged(QString)));
        connect( searchComboBox, SIGNAL(currentIndexChanged(int)),
                 this, SLOT(searchComboxChanged(int)));
        connect( searchComboBox, SIGNAL(currentIndexChanged(int)),
                 searchLineEdit, SLOT(setFocus()));
    }
}

void CardFile::setMessageLabel()
{
    int index = rowCount();
    messageLabel->setText( tr("Znaleziono %1 pasujących wyników").arg(index));
}


void CardFile::searchComboxChanged(int index)
{
    QString searchText = searchLineEdit->text();
    search(index, searchText);
    lineEditChanged();


    setMessageLabel();
}

void CardFile::searchClicked()
{
    int index = searchComboBox->currentIndex();
    QString searchText = searchLineEdit->text();

    search(index, searchText);

    setMessageLabel();
}

void CardFile::searchChanged(QString text)
{
    int index = searchComboBox->currentIndex();
    search(index, text);
    lineEditChanged();

    setMessageLabel();
}

void CardFile::search(int column, QString searchText)
{
    QString columnName = labels.at(column);
    QString query = dictionary[columnName] % " LIKE " % "'" % searchText % "%'";
    model->setFilter(query);
    model->select();

    updateColumnName();
}

void CardFile::addPatient(Patient patient)
{

    Database database;
    database.addPatient(patient);

    updateModel();
    setMessageLabel();
}


int CardFile::rowCount()
{
    // sprawdzić dokładnie rowCount, czasami crashuje aplikacje
    // prawdopodbnie przy pustej tabeli
    // wg forum na windowsie zwraca złe wartości

    while(model->canFetchMore())
     model->fetchMore();

    int index = model->rowCount();

    return index;
}



void CardFile::updateColumnName()
{
    // to by było najlpiej połączyć z jakimś sygnałem
    // bo łatwo zapomnieć o aktualizowaniu nazw

    model->setHeaderData(0, Qt::Horizontal, labels.at(0));
    model->setHeaderData(1, Qt::Horizontal, labels.at(1));
    model->setHeaderData(2, Qt::Horizontal, labels.at(2));
    model->setHeaderData(3, Qt::Horizontal, labels.at(3));
    model->setHeaderData(4, Qt::Horizontal, labels.at(4));
    model->setHeaderData(9, Qt::Horizontal, labels.at(5));
    model->setHeaderData(10, Qt::Horizontal, labels.at(6));
    model->setHeaderData(15, Qt::Horizontal, labels.at(7));

}


void CardFile::itemDoubleClicked(QModelIndex index)
{
    QSqlRecord record = model->record(index.row());
    int patientID = record.value(0).toInt();

    showPatient(patientID, false);
}

void CardFile::updateModel()
{
    model->setTable("patient");
    model->select();
    updateColumnName();
}

PatientRecord CardFile::getPatientById(int id)
{
    PatientRecord patient;

    DatabasePatient d;
    patient = d.getPatientById(QString::number(id));

    return patient;
}

void CardFile::editPatient(Patient patient)
{
      DatabasePatient d;
      d.updatePatient(patient.getPatientData());
      model->setFilter("");
      model->select();

      updateColumnName();
}

void CardFile::createContextMenu()
{
    generatePdfAction = new QAction(tr("Zapisz do PDF"), this);
    generatePdfAction->setIcon(QIcon(":/icons/pdf.png"));
    generatePdfAction->setIconVisibleInMenu(true);
    connect(generatePdfAction, SIGNAL(triggered()), this, SLOT(generatePdf()));

    showTeethDialogAction = new QAction(tr("Wyświetl diagram zębowy"), this);
    showTeethDialogAction->setIcon(QIcon(":/icons/Tooth.png"));
    showTeethDialogAction->setIconVisibleInMenu(true);
    connect(showTeethDialogAction, SIGNAL(triggered()), this, SLOT(showTeethDialog()));

    showPatientAction = new QAction( tr("Pokaż dane pacjenta"), this);
    showPatientAction->setIcon(QIcon(":/icons/user.png"));
    showPatientAction->setIconVisibleInMenu(true);
    connect(showPatientAction, SIGNAL(triggered()), this, SLOT(showPatientMenuClicked()));

    editPatientAction = new QAction( tr("Edytuj dane pacjenta"), this);
    editPatientAction->setIcon(QIcon(":/icons/edit.png"));
    editPatientAction->setIconVisibleInMenu(true);
    connect(editPatientAction, SIGNAL(triggered()), this, SLOT(showEditPatientDialog()));

    printPatientAction = new QAction( tr("Drukuj kartę pacjenta"), this);
    printPatientAction->setIcon(QIcon(":/icons/print.png"));
    printPatientAction->setIconVisibleInMenu(true);
    connect(printPatientAction, SIGNAL(triggered()), this, SLOT(printPatient()));

    addVisitAction = new QAction( tr("Zaplanuj wizytę pacjenta"), this);
    addVisitAction->setIcon(QIcon(":/icons/visit.png"));
    addVisitAction->setIconVisibleInMenu(true);

    showVisitAction = new QAction( tr("Pokaż wizyty pacjenta"), this);
    showVisitAction->setIcon(QIcon(":/icons/showVisit.png"));
    showVisitAction->setIconVisibleInMenu(true);

    showPhotosAction = new QAction( tr("Wyświetl zdjęcia pacjenta"), this);
    showPhotosAction->setIcon(QIcon(":/icons/XRay.png"));
    showPhotosAction->setIconVisibleInMenu(true);

    addPrescriptionAction = new QAction( tr("Wypisz receptę"), this);
    addPrescriptionAction->setIcon(QIcon(":/icons/addPrescription.png"));
    addPrescriptionAction->setIconVisibleInMenu(true);

    showPrescriptionAction = new QAction( tr("Pokaż wydane recepty"), this);
    showPrescriptionAction->setIcon(QIcon(":/icons/Archive.png"));
    showPrescriptionAction->setIconVisibleInMenu(true);

    cardfileTable->addAction(showPatientAction);
    cardfileTable->addAction(showTeethDialogAction);
    cardfileTable->addAction(editPatientAction);
    cardfileTable->addAction(showPhotosAction);
    cardfileTable->addAction(addPrescriptionAction);
    cardfileTable->addAction(showPrescriptionAction);
    cardfileTable->addAction(addVisitAction);
    cardfileTable->addAction(showVisitAction);
    cardfileTable->addAction(generatePdfAction);
    cardfileTable->addAction(printPatientAction);
    cardfileTable->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void CardFile::showPatientMenuClicked()
{
    QItemSelectionModel *selectionModel = cardfileTable->selectionModel();
    QModelIndexList row = selectionModel->selectedRows();

    if( row.size() > 0)
        showPatient(row.at(0).data(0).toInt(), false);
}

void CardFile::showEditPatientDialog()
{
    QItemSelectionModel *selectionModel = cardfileTable->selectionModel();
    QModelIndexList row = selectionModel->selectedRows();

    if( row.size() > 0)
        showPatient(row.at(0).data(0).toInt(), true);

}

void CardFile::showPatient(int patientID, bool edit)
{
    Patient newPatient;

    newPatient.setMap(getPatientById( patientID ));

    ShowPatientDialog *showPatientDialog = new ShowPatientDialog;
    showPatientDialog->setPatient(newPatient);

    showPatientDialog->setEditableCheckBox(edit);

    if ( showPatientDialog->exec() == QDialog::Accepted )
    {
      Patient patient;
      patient = showPatientDialog->getPatient();

      editPatient(patient);
    }
}

void CardFile::showTeethDialog()
{
    QItemSelectionModel *selectionModel = cardfileTable->selectionModel();
    QModelIndexList row = selectionModel->selectedRows();

    if( row.size() > 0)
    {
        DiagramDialog *dialog = new DiagramDialog(row.at(0).data(0).toInt());
        dialog->exec();
    }
}


void CardFile::generatePdf()
{
    PdfCreator pdf;
    Patient patient;

    QItemSelectionModel *selectionModel = cardfileTable->selectionModel();
    QModelIndexList row = selectionModel->selectedRows();

    if( row.size() > 0)
    {
        patient.setMap(getPatientById( row.at(0).data(0).toInt() ));
        pdf.createPatientPage(patient);
    }
}

void CardFile::printPatient()
{

}

