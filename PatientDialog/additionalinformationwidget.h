/**
  * AdditionalInformationWidget
  * Widget służący do wprowadzania dodatkowych informacji o pacjencie
  */

#ifndef ADDITIONALINFORMATIONWIDGET_H
#define ADDITIONALINFORMATIONWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include "patient.h"

class QLabel;
class QGroupBox;

class AdditionalInformationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdditionalInformationWidget(QWidget *parent = 0);

    // akcesory
    QString getPharmaceuticals() { return pharmaceuticalsTextEdit->toPlainText(); }
    QString getDisorders() { return disordersTextEdit->toPlainText(); }
    QString getAllergy() { return allergyTextEdit->toPlainText(); }
    QString getNote() { return noteTextEdit->toPlainText(); }

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
      * Metoda tworzy główny layout widgetu
      * @param void
      * @return void
      */
    void createLayout();

    /**
      * Metoda tworzy GUI widgetu
      * @param void
      * @return void
      */
    void createAdditionalInformation();

    QTextEdit *pharmaceuticalsTextEdit;
    QTextEdit *allergyTextEdit;
    QTextEdit *disordersTextEdit;
    QTextEdit *noteTextEdit;

    QLabel *pharmaceuticalsLabel;
    QLabel *allergyLabel;
    QLabel *disordersLabel;
    QLabel *noteLabel;

    QGroupBox *additionalInformationGroupBox;

};

#endif // ADDITIONALINFORMATIONWIDGET_H
