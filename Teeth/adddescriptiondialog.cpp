#include <QComboBox>
#include <QStringList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QtSql>
#include "adddescriptiondialog.h"

AddDescriptionDialog::AddDescriptionDialog(QWidget *parent) :
    QDialog(parent)
{
    createStringList();
    createComboBox();
    createTextEdit();
    createButtons();
    createLayout();

    setWindowTitle( tr("Dodaj opis") );
}

void AddDescriptionDialog::createStringList()
{
    teethSecondList << "11" << "12" << "13" << "14" << "15" << "16" << "17" << "18"
            << "21" << "22" << "23" << "24" << "25" << "26" << "27" << "28"
            << "31" << "32" << "33" << "34" << "35" << "36" << "37" << "38"
            << "41" << "42" << "43" << "44" << "45" << "46" << "47" << "48";

    teethMilkList << "51" << "52" << "53" << "54" << "55"
            << "61" << "62" << "63" << "64" << "65"
            << "71" << "72" << "73" << "74" << "75"
            << "81" << "82" << "83" << "84" << "85";
}

void AddDescriptionDialog::createComboBox()
{
    teethLabel = new QLabel( tr("Ząb:"));

    teethTypeComboBox = new QComboBox;
    teethTypeComboBox->addItem(tr("Stałe"));
    teethTypeComboBox->addItem(tr("Mleczne"));
    teethTypeComboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    connect(teethTypeComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(teethTypeChanged(int)));

    teethNumberComboBox = new QComboBox;
    teethTypeChanged(0);
}

void AddDescriptionDialog::createTextEdit()
{
    descriptionLabel = new QLabel( tr("Opis: ") );
    descriptionLabel->setAlignment(Qt::AlignTop);
   // descriptionLabel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    descriptionTextEdit = new QTextEdit;
}


void AddDescriptionDialog::teethTypeChanged(int type)
{
    if(type == 0)
    {
        teethNumberComboBox->clear();
        teethNumberComboBox->addItems(teethSecondList);
        teethNumberComboBox->insertSeparator(8);
        teethNumberComboBox->insertSeparator(17);
        teethNumberComboBox->insertSeparator(26);

    }
    else
    {
        teethNumberComboBox->clear();
        teethNumberComboBox->addItems(teethMilkList);
        teethNumberComboBox->insertSeparator(5);
        teethNumberComboBox->insertSeparator(11);
        teethNumberComboBox->insertSeparator(17);
    }
}

void AddDescriptionDialog::createButtons()
{
    okButton = new QPushButton( tr("Ok") );
    cancelButton = new QPushButton( tr("Anuluj") );

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void AddDescriptionDialog::createLayout()
{
    QHBoxLayout *comboLayout = new QHBoxLayout;
    comboLayout->addWidget(teethLabel);
    comboLayout->addWidget(teethTypeComboBox);
    comboLayout->addWidget(teethNumberComboBox);
    comboLayout->addStretch();

    QHBoxLayout *textEditLayout = new QHBoxLayout;
    textEditLayout->addWidget(descriptionLabel);
    textEditLayout->addWidget(descriptionTextEdit);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(comboLayout);
    layout->addLayout(textEditLayout);
    layout->addLayout(buttonsLayout);

    setLayout(layout);
}

void AddDescriptionDialog::setTeeth(int name, int type)
{
    if( type == SECOND )
       teethTypeComboBox->setCurrentIndex(0);
    if( type == MILK )
        teethTypeComboBox->setCurrentIndex(1);

   teethNumberComboBox->setCurrentIndex(
            teethNumberComboBox->findText( QString::number(name)));
}


void AddDescriptionDialog::addToDatabase(QString id_patient, QString id_visit)
{
    QString number = teethNumberComboBox->currentText();
    QString description = descriptionTextEdit->toPlainText();

    QString type = teethTypeComboBox->currentText();

    QSqlQuery query;
    query.prepare("INSERT INTO teeth_description ("
                  "id_patient, "
                  "id_visit, "
                  "type, "
                  "number, "
                  "description)"
                  "VALUES ( :id_patient, :id_visit, :type, "
                  ":number, :description)");

    query.bindValue(":id_patient", id_patient);
    query.bindValue(":id_visit", id_visit);
    query.bindValue(":type", type);
    query.bindValue(":number", number);
    query.bindValue(":description", description);

}
