#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>

class PersonalDetailWidget;
class AdditionalInformationWidget;
class ExaminationWidget;
class QTabWidget;
class QPushButton;
class QLabel;
class QVBoxLayout;

class PatientDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PatientDialog(QWidget *parent = 0);

protected slots:
    /**
      * Slot wywoływany przy akceptacji dodania pacjenta
      * Sprawdza on poprawność wprowadzonych danych
      * @param void
      * @return void
      */
    void okClicked();

    /**
      * Slot pozwalający uruchomić dialog diagramu zębowego
      * @param void
      * @return void
      */
    void showTeethDiagram();

private:
    /**
      * Metoda tworzy nowego pacjenta
      * @param void
      * @return void
      */
    void createPatient();

    /**
      * Metoda sprawdza poprawność wprowadzonego numeru PESEL
      * @param QString
      * @return bool
      */
    bool checkPesel(QString pesel);

    /**
      * Metoda tworzy GUI związane z zakładkami
      * @param void
      * @return void
      */
    void createTabs();

    /**
      * Metoda tworzy główny layout dialogu
      * @param void
      * @return void
      */
    void createLayout();


    void createImageLabel();

    /**
      * Metoda tworzy przyciski dialogu
      * @param void
      * @return void
      */
    void createButtons();



    QTabWidget *tabWidget;

    QPushButton *showTeethDiagramButton;
    QPushButton *okButton;
    QPushButton *cancelButton;

    PersonalDetailWidget *personalDetailWidget;
    AdditionalInformationWidget *additionalInformationWidget;
    ExaminationWidget *examinationWidget;

    QLabel *userImageLabel;

    QVBoxLayout *mainLayout;


};

#endif // PATIENTDIALOG_H
