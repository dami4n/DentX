#ifndef REMINDERFUNCTION_H
#define REMINDERFUNCTION_H

#include <QObject>
#include "reminder.h"

class ReminderFunction : public QObject
{
    Q_OBJECT
public:
    explicit ReminderFunction(QObject *parent = 0);

    /**
      * Metoda dodaje przypomnienie do bazy danych
      * @param Note
      * @return int
      */
    int addReminderToDatabase(Reminder reminder);

signals:
    /**
      * Sygnał emitowany gdy tabela w bazie została zmodyfikowana
      * @param void
      * @return void
      */
    void changed();

};

#endif // REMINDERFUNCTION_H
