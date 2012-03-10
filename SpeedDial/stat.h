#ifndef STAT_H
#define STAT_H

#include <QWidget>

class QLabel;
class QGroupBox;

class Stat : public QWidget
{
    Q_OBJECT
public:
    explicit Stat(QWidget *parent = 0);


private:
    void createGui();
    void createLayout();
    void getStat();

    QGroupBox *statGrouBox;
    QLabel *patientsNumberLabel;
    QLabel *noteNumberLabel;
    QLabel *reminderNumberLabel;
    QLabel *lastRunDateLabel;
    QLabel *programVersionLabel;

    QString patientNumbersString;
    QString noteNumberString;
    QString reminderNumberString;
    QString lastRunDate;

};

#endif // STAT_H
