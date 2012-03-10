/**
  * DiagramDialog
  * Klasa odpowiedzialna za wyświetlenie dialogu z diagramami zębów pacjenta i historią wizyt
  */

#ifndef DIAGRAMDIALOG_H
#define DIAGRAMDIALOG_H

#include <QDialog>
#include "diagram.h"
#include "diagrammilkteeth.h"

class History;
class ColorButtons;
class ActionTabs;
class QGroupBox;
class QGridLayout;
class QVBoxLayout;
class QHBoxLayout;
class QListView;
class QPushButton;
class QLabel;

class DiagramDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DiagramDialog(int newId, QWidget *parent = 0);


private slots:
    /**
      * Slot wywoływany przy kliknięciu przycisku 'ok'
      * @param void
      * @return void
      */
    void okClicked();

    void clicked(QString);

    void setColor(QColor color, bool part);
    void newAppointment();
    void deleteAppointment();
    void saveAppointment();
    void saveActionTabs();

    void setBackgroundColor(QColor);

    /**
      * Metoda włącza/wyłącza przycisk 'zapisz'
      * @param bool
      * @return void
      */
    void saveEnable(bool value);

protected:
    void closeEvent(QCloseEvent *);

private:
    void createDiagram();
    void createMainLayout();
    void createHistory();
    void createButtons();
    void createColorButtons();
    void createModel();
    void createActionTabs();
    void createLabel();

    QVBoxLayout *mainLayout;
    QHBoxLayout *buttonsLayout;

    QPushButton *okButton; /*!< OK */
    QPushButton *cancelButton; /*!< Anuluj */
    QPushButton *newAppointmentButton; /*!< Nowa wizyta */
    // QPushButton *deleteAppointmentButton; /*!< Usuń wizyte */
    QPushButton *saveAppointmentButton; /*!< Zapisz wizytę */

    QGroupBox *teethGroupBox;
    QGroupBox *milkTeethGroupBox;
    QGroupBox *historyGroupBox;

    int id;
    QLabel *nameLabel;
    QLabel *userImageLabel;

    Diagram *diagram;
    DiagramMilkTeeth *diagramMilkTeeth;
    History *history;
    ColorButtons *colorButtons;
    ActionTabs *actionTabs;
};

#endif // DIAGRAMDIALOG_H
