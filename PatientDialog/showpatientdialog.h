/**
  * ShowPatientDialog
  * Klasa wyświetlająca informacje o pacjencie
  */

#ifndef SHOWPATIENTDIALOG_H
#define SHOWPATIENTDIALOG_H

#include <QDialog>
#include "patient.h"
#include "addpatientdialog.h"

class QPushButton;
class QCheckBox;
class QHBoxLayout;

class ShowPatientDialog : public AddPatientDialog
{
    Q_OBJECT
public:
    explicit ShowPatientDialog(QWidget *parent = 0);

    /**
      * Metoda wczytuje do dialogu dane z pacjenta
      * @param void
      * @return void
      */
    void setPatient(Patient patient);

    /**
      * Metoda wczytuje do dialogu dane z pacjenta
      * @param bool
      * @return void
      */
    void setEditableCheckBox(bool value);

public slots:

    /**
      * Metoda ustawia dialog jako edytowalny/nieedytowalny
      * @param void
      * @return void
      */
    void setEditable(bool value);

private slots:

    /**
      * Prywatny slot pozwalający uruchomić dialog diagramu zębowego
      * @param void
      * @return void
      */
    void showTeethDiagram();

private:

    void createLayout();

    /**
      * Metoda tworzy przycisk 'zamknij' dialogu
      * @param void
      * @return void
      */
    void createButtons();

    /**
      * Metoda tworzy checkBox 'edycja' dialogu
      * @param void
      * @return void
      */
    void createEditableCheckBox();

    QPushButton *closeButton;
    QPushButton *showTeethDiagramButton;
    QCheckBox *isEditableCheckBox;
    QHBoxLayout *controlButtonLayout;

    Patient patient;

};

#endif // SHOWPATIENTDIALOG_H
