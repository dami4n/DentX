#ifndef CLINICPAGEWIDGET_H
#define CLINICPAGEWIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimeEdit>
#include <QCheckBox>

class Preferences;

class ClinicPageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClinicPageWidget(QWidget *parent = 0);

    bool getMonday() { return mondayCheckBox->isChecked();  }
    bool getTuesday() { return tuesdayCheckBox->isChecked(); }
    bool getWednesday() { return wednesdayCheckBox->isChecked(); }
    bool getThursday() { return thursdayCheckBox->isChecked(); }
    bool getFriday() { return fridayCheckBox->isChecked(); }
    bool getSaturday() { return saturdayCheckBox->isChecked(); }
    bool getSunday() { return sundayCheckBox->isChecked(); }

    QTime getStartTime() { return startTimeEdit->time(); }
    QTime getEndTime() { return endTimeEdit->time(); }

        void readSettings();

private:
    void createGui();
    void createLayout();

    QCheckBox *mondayCheckBox;
    QCheckBox *tuesdayCheckBox;
    QCheckBox *wednesdayCheckBox;
    QCheckBox *thursdayCheckBox;
    QCheckBox *fridayCheckBox;
    QCheckBox *saturdayCheckBox;
    QCheckBox *sundayCheckBox;

    QTimeEdit *startTimeEdit;
    QTimeEdit *endTimeEdit;

    Preferences *preferences;

};

#endif // CLINICPAGEWIDGET_H
