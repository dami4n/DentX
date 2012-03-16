#include <QtGui>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringBuilder>
#include <QString>
#include "teeth.h"
#include "diagramdialog.h"
#include "colorbuttons.h"
#include "history.h"
#include "actiontabs.h"

DiagramDialog::DiagramDialog(int newId, QWidget *parent) :
    QDialog(parent)
{
    setModal(Qt::NonModal);

    diagram = new Diagram;
    diagramMilkTeeth = new DiagramMilkTeeth;
    diagramMilkTeeth->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    id = newId;

    createButtons();
    createDiagram();
    createHistory();
    createActionTabs();
    createLabel();
    createMainLayout();

    if((history->sizeHistory()) == 0)
            saveEnable(false);

    setColor(Qt::blue, true);

    setLayout(mainLayout);
    setWindowTitle( tr("Wizyty") );

    resize(800, 600);
}

void DiagramDialog::setBackgroundColor(QColor color)
{
    diagram->setAutoFillBackground(true);
    diagram->setPalette(QPalette(color));

    diagramMilkTeeth->setAutoFillBackground(true);
    diagramMilkTeeth->setPalette(QPalette(color));
}

void DiagramDialog::createButtons()
{
    okButton = new QPushButton(tr("OK"));
    okButton->setIcon(QIcon(":/icons/ok.png"));

    cancelButton = new QPushButton(tr("Anuluj"));
    cancelButton->setIcon(QIcon(":/icons/Cancel.png"));


    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(okButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addStretch();
    buttonsLayout->setDirection(QBoxLayout::RightToLeft);

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    }

void DiagramDialog::okClicked()
{
    accept();
}

void DiagramDialog::createActionTabs()
{
    actionTabs = new ActionTabs;

    connect(actionTabs->colorButtons, SIGNAL(colorChanged(QColor,bool))
            ,this, SLOT(setColor(QColor,bool)));

}

void DiagramDialog::createHistory()
{
    historyGroupBox = new QGroupBox(tr("Historia wizyt"));

    history = new History;
    history->createModel(id);
    connect(history, SIGNAL(clicked(QString)), this, SLOT(clicked(QString)));

    QVBoxLayout *historyLayout = new QVBoxLayout;
    historyLayout->addWidget(history);

    newAppointmentButton = new QPushButton(tr("Nowa wizyta"));
    newAppointmentButton->setIcon(QIcon(":/icons/New.png"));
    connect(newAppointmentButton, SIGNAL(clicked()), this, SLOT(newAppointment()));

//    deleteAppointmentButton = new QPushButton( tr("Usuń wizytę") );
//    connect(deleteAppointmentButton, SIGNAL(clicked()), this, SLOT(deleteAppointment()));

    saveAppointmentButton = new QPushButton( tr("Zapisz") );
    saveAppointmentButton->setIcon(QIcon(":/icons/Save.png"));
    connect(saveAppointmentButton, SIGNAL(clicked()), this, SLOT(saveAppointment()));


    QHBoxLayout *buttonHistoyrLayout = new QHBoxLayout;
    buttonHistoyrLayout->addWidget(newAppointmentButton);
   // buttonHistoyrLayout->addWidget(deleteAppointmentButton);
    buttonHistoyrLayout->addWidget(saveAppointmentButton);

    historyLayout->addLayout(buttonHistoyrLayout);

    historyGroupBox->setLayout(historyLayout);
}

void DiagramDialog::deleteAppointment()
{

}

void DiagramDialog::createLabel()
{
    QSqlQuery query;
    query.prepare("SELECT name, lastname "
                  "FROM patient "
                  "WHERE id = :patientID");

    query.bindValue(":patientID", id);

    bool value = query.exec();

    if( !value )
    {
        qDebug() << "CreateLabel sql error";
        qDebug() << query.lastQuery();
        qDebug() << query.lastError();
    }

    QString name;
    QString lastName;

    if(query.next())
    {
        name = query.value(0).toString();
        lastName = query.value(1).toString();
    }

    QString labelString = "<h1>" % name % " " % lastName;

    nameLabel = new QLabel(labelString );

    QPixmap pixmap(":/icons/PatientData.png");
    userImageLabel = new QLabel;
    userImageLabel->setPixmap(pixmap.scaled(
                    64, 64, Qt::KeepAspectRatio));

}

void DiagramDialog::createMainLayout()
{
    QHBoxLayout *milkListLayout = new QHBoxLayout;
    milkListLayout->addWidget(milkTeethGroupBox);
    milkListLayout->addWidget(historyGroupBox);

    QVBoxLayout *upLay = new QVBoxLayout;
    upLay->addWidget(teethGroupBox);
    upLay->addLayout(milkListLayout);

    QWidget *widget = new QWidget;
    widget->setLayout(upLay);

    QSplitter *splitter = new QSplitter;
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(widget);
    splitter->addWidget(actionTabs);

    QHBoxLayout *labelLayout = new QHBoxLayout;
    labelLayout->addWidget(userImageLabel);
    labelLayout->addSpacing(15);
    labelLayout->addWidget(nameLabel);
    labelLayout->addStretch();

    mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(teethGroupBox);
//    mainLayout->addLayout(milkListLayout);
//    mainLayout->addWidget(actionTabs);
    mainLayout->addLayout(labelLayout);
    mainLayout->addWidget(splitter);
    mainLayout->addLayout(buttonsLayout);

}

void DiagramDialog::createDiagram()
{
    teethGroupBox = new QGroupBox(tr("Stale"));
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(diagram);
    teethGroupBox->setLayout(layout);

    milkTeethGroupBox = new QGroupBox(tr("Mleczne"));
    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2->addWidget(diagramMilkTeeth);
    layout2->addStretch();
    milkTeethGroupBox->setLayout(layout2);
}


void DiagramDialog::newAppointment()
{
    QMessageBox msgBox;
    msgBox.addButton(tr("Anuluj"), QMessageBox::RejectRole);
    msgBox.addButton(tr("Tak"), QMessageBox::AcceptRole);
    msgBox.setText(tr("Czy na pewno chcesz dodać nową wizytę?"));
    msgBox.setIcon(QMessageBox::Question);

    if( msgBox.exec() == QMessageBox::Accepted )
    {
        QString second = diagram->save();
        QString milk = diagramMilkTeeth->save();

        history->addNewAppointment(id, milk, second);

        saveEnable(true); // brzydko
    }
}

void DiagramDialog::saveAppointment()
{
    QString second = diagram->save();
    QString milk = diagramMilkTeeth->save();
    QString plan = actionTabs->getPlan();
    QString diagnosis = actionTabs->getDiagnosis();

    history->save(id, milk, second, plan, diagnosis);

}

void DiagramDialog::setColor(QColor color, bool part)
{
    Teeth::partEnabled = part;
    Teeth::color = color;
}

void DiagramDialog::clicked(const QString text)
{

    QString milk = history->getMilk(text);
    QString second = history->getSecond(text);

    actionTabs->setPlan( history->getPlan() );
    actionTabs->setDiagnosis( history->getDiagnosis() );

    diagram->read(second);
    diagramMilkTeeth->read(milk);
}

void DiagramDialog::closeEvent(QCloseEvent *)
{
    // QMessageBox::question();

}

void DiagramDialog::saveEnable(bool value)
{
    saveAppointmentButton->setEnabled(value);
}

void DiagramDialog::saveActionTabs()
{

}






