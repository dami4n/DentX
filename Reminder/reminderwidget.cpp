#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QTextCodec>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QCalendarWidget>
#include <QComboBox>

#include "Note/editor.h"
#include "Note/note.h"

#include "reminderwidget.h"

ReminderWidget::ReminderWidget(QWidget *parent) :
    QWidget(parent)
{
    createCalendar();
    createGui();
    createLayout();
}

void ReminderWidget::createGui()
{
    reminderTopicLabel = new QLabel( tr("Temat:") );
    reminderTopicLabel->setAlignment(Qt::AlignTop);
    topicLineEdit = new QLineEdit;
    topicLineEdit->setMaxLength(100);

    dateLabel = new QLabel( tr("Dodane:") );
    dateLabel->setAlignment(Qt::AlignTop);
    dateLineEdit = new QLineEdit;
    dateLineEdit->setEnabled(false);

    dateReminderLabel = new QLabel( tr("Przypomnij: "));
    dateReminderLabel->setAlignment(Qt::AlignTop);

    priorityLabel = new QLabel( tr("Priorytet: ") );
    priorityComboBox = new QComboBox;
    priorityComboBox->addItem( tr("Wysoki") );
    priorityComboBox->addItem( tr("Normalny") );
    priorityComboBox->addItem( tr("Niski") );
    priorityComboBox->setCurrentIndex(1);

    reminderTextLabel = new QLabel(tr("Treść: "));
    reminderTextLabel->setAlignment(Qt::AlignTop);
    editor = new Editor;
}

void ReminderWidget::createCalendar()
{
    // format daty jest ważny
    // dodać zmienną do klasy ustawień i zrobić w całym programie ten sam format

    QCalendarWidget *pushCalendar = new QCalendarWidget;
    pushCalendar->setFirstDayOfWeek(Qt::Monday);
    pushCalendar->setGridVisible(true);
    pushCalendar->setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);
    pushCalendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    dateTimeEdit = new QDateTimeEdit(QDate::currentDate());
    dateTimeEdit->setMinimumDate(QDate::currentDate());
    dateTimeEdit->setDisplayFormat("yyyy-MM-dd");

    dateTimeEdit->setCalendarPopup(true);
    dateTimeEdit->setCalendarWidget(pushCalendar);
}


void ReminderWidget::createLayout()
{
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(reminderTopicLabel, 0, 0);
    mainLayout->addWidget(topicLineEdit, 0, 1, 1, 3);
    mainLayout->addWidget(dateLabel, 1, 0);
    mainLayout->addWidget(dateLineEdit, 1, 1, 1, 3);
    mainLayout->addWidget(dateReminderLabel, 2, 0);
    mainLayout->addWidget(dateTimeEdit, 2, 1, 1, 3);
    mainLayout->addWidget(priorityLabel, 3, 0);
    mainLayout->addWidget(priorityComboBox, 3, 1, 1, 3);
    mainLayout->addWidget(reminderTextLabel, 4, 0);
    mainLayout->addWidget(editor, 4, 1, 1, 3);

    setLayout(mainLayout);
}

Reminder ReminderWidget::getReminder()
{
    Reminder reminder;
    reminder.dateAdded = QDateTime::currentDateTime().toString();
    reminder.dateReminder = dateTimeEdit->dateTime().toString();
    reminder.text = editor->getText();
    reminder.textHtml = editor->getHtml();
    reminder.topic = topicLineEdit->text();
    reminder.priority = priorityComboBox->currentText();

    return reminder;
}

void ReminderWidget::setReminder(Reminder reminder)
{
    editor->setText(reminder.text);
    dateLineEdit->setText(reminder.dateAdded);
    topicLineEdit->setText(reminder.topic);
    priorityComboBox->setCurrentIndex( priorityComboBox->findText(reminder.priority) );
}

void ReminderWidget::setReminder(QString topic, QString text,
                                 QString date, QString priority)
{
    editor->setText(text);
    topicLineEdit->setText(topic);
    dateLineEdit->setText(date);
    priorityComboBox->setCurrentIndex( priorityComboBox->findText(priority) );
}

void ReminderWidget::setEditable(bool value)
{
    editor->setEditable(value);
    topicLineEdit->setReadOnly(!value);
    dateTimeEdit->setReadOnly(!value);
    priorityComboBox->setEditable(value);
}

void ReminderWidget::setToday()
{
    dateLineEdit->setText(QDateTime::currentDateTime().toString());
}

QString ReminderWidget::getTopic()
{
    return topicLineEdit->text();
}

QString ReminderWidget::getReminderDate()
{
    return dateTimeEdit->text();
}
