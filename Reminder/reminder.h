#ifndef REMINDER_H
#define REMINDER_H

#include <QString>

class Reminder
{
public:
    Reminder();

    int id; /*!< Unikalny identyfikator przypomnienia */
    QString dateAdded; /*!< Data dodanie przypomnienia */
    QString dateReminder; /*!< Data przypomnienia */
    QString priority; /*!< Priorytet */
    QString topic; /*!< Temat przypomnienia */
    QString text; /*!< Treść przypomnienia */
    QString textHtml; /*!< Treść przypomnienia(html) */
};

#endif // REMINDER_H
