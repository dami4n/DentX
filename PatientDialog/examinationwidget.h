/**
  * ExaminationWidget
  * Widget służący do wprowadzania informacji o badaniu przedmiotowym pacjenta
  */

#ifndef EXAMINATIONWIDGET_H
#define EXAMINATIONWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include "patient.h"

class QLabel;

class QGroupBox;
class QVBoxLayout;

class ExaminationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ExaminationWidget(QWidget *parent = 0);

    // akcesory
    QString getDentalArticulation() { return dentalArticulationComboBox->currentText(); }
    QString getJoint() { return jointComboBox->currentText(); }
    QString getExposure() { return exposureComboBox->currentText(); }
    QString getColor() { return colorComboBox->currentText(); }
    QString getEfflorescencePre() { return efflorescencePreComboBox->currentText() ; }
    QString getEfflorescenceSec() { return efflorescenceSecComboBox->currentText(); }
    QString getMorfologicalChanges() { return morfologicalChangesComboBox->currentText(); }
    QString getTongue() { return tongueComboBox->currentText(); }
    QString getMorfologicalDisorder() { return morfologicalDisorderComboBox->currentText(); }
    QString getOhi() { return ohiComboBox->currentText(); }
    QString getPli() { return pliComboBox->currentText(); }
    QString getApi() { return apiComboBox->currentText(); }
    QString getStimulateSaliva() { return stimulateSalivaLineEdit->text(); }
    QString getNonStimulateSaliva() { return nonStimulateSalivaLineEdit->text(); }

    /**
      * Metoda ustawia widget jako edytowalny/nieedytowalny
      * @param void
      * @return void
      */
    void setEditable(bool value);

    /**
      * Metoda wczytuje do widgetu dane z pacjenta
      * @param void
      * @return void
      */
    void setPatient(Patient patient);

private:
    /**
      * Metoda tworzy GUI widgetu
      * @param void
      * @return void
      */
    void createExamination();

    /**
      * Metoda tworzy główny layout widgetu
      * @param void
      * @return void
      */
    void createLayout();

    QVBoxLayout *testLayout;

    QComboBox *dentalArticulationComboBox;
    QComboBox *jointComboBox;
    QComboBox *exposureComboBox;
    QComboBox *colorComboBox;
    QComboBox *efflorescencePreComboBox;
    QComboBox *efflorescenceSecComboBox;
    QComboBox *morfologicalChangesComboBox;
    QComboBox *tongueComboBox;
    QComboBox *morfologicalDisorderComboBox;
    QComboBox *ohiComboBox;
    QComboBox *pliComboBox;
    QComboBox *apiComboBox;

    QLabel *dentalArticulationLabel;
    QLabel *jointLabel;
    QLabel *exposureLabel;
    QLabel *colorLabel;
    QLabel *efflorescencePreLabel;
    QLabel *efflorescenceSecLabel;
    QLabel *morfologicalChangesLabel;
    QLabel *tongueLabel;
    QLabel *morfologicalDisorderLabel;
    QLabel *ohiLabel;
    QLabel *pliLabel;
    QLabel *apiLabel;
    QLabel *stimulateSalivaLabel;
    QLabel *nonStimulateSalivaLabel;

    QLineEdit *stimulateSalivaLineEdit;
    QLineEdit *nonStimulateSalivaLineEdit;

};

#endif // EXAMINATIONWIDGET_H
