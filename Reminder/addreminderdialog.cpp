#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "reminderwidget.h"

#include "addreminderdialog.h"

AddReminderDialog::AddReminderDialog(QWidget *parent) :
    QDialog(parent)
{
    createGui();
    createLayout();

    setWindowTitle( tr("Dodaj przypomnienie") );
}

void AddReminderDialog::createGui()
{
    reminderWidget = new ReminderWidget;
    reminderWidget->setToday();

    okButton = new QPushButton( tr("Ok") );
    cancelButton = new QPushButton( tr("Anuluj") );

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void AddReminderDialog::createLayout()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(reminderWidget);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void AddReminderDialog::okClicked()
{
    if( reminderWidget->getTopic().isEmpty()
        || reminderWidget->getReminderDate().isEmpty() )
    {
        QMessageBox::warning(this, tr("Puste pole"),
                             tr("Pole 'temat' musi być uzupełnione"));
    }
    else
    {
        accept();
    }

}

Reminder AddReminderDialog::getReminder() const
{
    return reminderWidget->getReminder();
}
