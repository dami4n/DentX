#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QStringBuilder>
#include <QVariant>
#include "reminder.h"

#include "reminderfunction.h"

ReminderFunction::ReminderFunction(QObject *parent) :
    QObject(parent)
{
}

int ReminderFunction::addReminderToDatabase(Reminder reminder)
{
    QSqlQuery query;
    query.prepare("INSERT INTO reminder "
                  "(dateAdded, dateReminder, topic, priority, text, "
                  "textHtml, dateAddedSQL, dateReminderSQL) "
                  "VALUES (:dateAdded, :dateReminder,  :topic, :priority,  :text,"
                  ":textHtml, :dateAddedSQL, :dateReminderSQL)"
                    );

    qDebug() << reminder.dateReminder;

    query.bindValue(":dateAdded", reminder.dateAdded);
    query.bindValue(":dateReminder", reminder.dateReminder);
    query.bindValue(":topic", reminder.topic);
    query.bindValue(":priority", reminder.priority);
    query.bindValue(":text", reminder.text);
    query.bindValue(":textHtml", reminder.textHtml);
    query.bindValue(":dateAddedSQL", QDateTime::fromString(reminder.dateAdded).toString("yyyy-MM-dd"));
    query.bindValue(":dateReminderSQL", QDateTime::fromString(reminder.dateReminder).toString("yyyy-MM-dd"));

    bool value = query.exec();

    qDebug() << query.lastQuery();

    if( !value )
    {
        qDebug() << "addReminderToDatabase error";
        qDebug() << query.lastError();
        return -1;
    }

    qDebug() << "Dodaje";

    emit changed();

    return 1;
}
