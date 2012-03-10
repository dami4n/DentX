#ifndef SPEEDDIAL_H
#define SPEEDDIAL_H

#include <QWidget>

class QPushButton;
class Stat;

class SpeedDial : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedDial(QWidget *parent = 0);

signals:
    void showButtonClicked();
    void addPatientButtonClicked();
    void addNoteButtonClicked();
    void addReminderButtonClicked();
    void prescriptionButtonClicked();

protected:
    void resizeEvent(QResizeEvent *);

private:
    void createButtons();
    void createLayout();
    void createStat();

    QPushButton *addNoteButton;
    QPushButton *addReminderButton;
    QPushButton *prescriptionButton;
    QPushButton *showPatientsButton;
    QPushButton *addPatientButton;

    Stat *stat;

};

#endif // SPEEDDIAL_H
