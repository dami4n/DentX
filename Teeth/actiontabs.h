#ifndef ACTIONTABS_H
#define ACTIONTABS_H

#include <QWidget>

class QTabWidget;
class QTextEdit;
class ColorButtons;
class DescriptionWidget;
class Radiograph;

class ActionTabs : public QWidget
{
    Q_OBJECT
public:
    explicit ActionTabs(QWidget *parent = 0);

     ColorButtons *colorButtons;
     QString getDiagnosis() const;
     QString getPlan() const;

     void setPlan(QString value);
     void setDiagnosis(QString value);

private:
    void createButtonsTab();
    void createDescriptionTab();
    void createDiagnosisTab();
    void createPlanTextEdit();
    void createRadiograph();
    void createTabs();

    QTabWidget *tabWidget;
    QTextEdit *diagnosisTextEdit;
    QTextEdit *planTextEdit;
    Radiograph *radiograph;

    DescriptionWidget *descriptionWidget;

};

#endif // ACTIONTABS_H
