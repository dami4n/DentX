#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "reminderwidget.h"

#include "showreminderdialog.h"

ShowReminderDialog::ShowReminderDialog(QWidget *parent) :
    QDialog(parent)
{
    createGui();
    createLayout();
}

ShowReminderDialog::ShowReminderDialog(Reminder reminder, QWidget *parent) :
        QDialog(parent)
{
    createGui();
    createLayout();
    setReminder(reminder);
}


void ShowReminderDialog::createGui()
{
    reminderWidget = new ReminderWidget;
    reminderWidget->setEditable(false);

    okButton = new QPushButton( tr("Ok") );
    okButton->setEnabled(false);
    cancelButton = new QPushButton( tr("Anuluj") );

    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void ShowReminderDialog::createLayout()
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

void ShowReminderDialog::setReminder(Reminder reminder)
{
   reminderWidget->setReminder(reminder);
}

void ShowReminderDialog::setReminder(QString topic, QString text,
                                     QString dateReminder, QString priority)
{
   reminderWidget->setReminder(topic, text, dateReminder, priority);
}
