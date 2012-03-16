#ifndef CARDFILE_H
#define CARDFILE_H

#include <QWidget>
#include <QStringList>
#include <QModelIndex>
#include <QMap>
#include "Database/databasepatient.h"

#include "patient.h"

class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QSqlTableModel;
class QSqlDatabase;
class CardfileTable;

class CardFile : public QWidget
{
    Q_OBJECT
public:
    explicit CardFile(QWidget *parent = 0);

    /**
     * Metoda zwraca aktualną ilość elementów w tabeli
     * @param void
     * @return int
     */
    int rowCount();

    /**
     * Metoda wczytuje pacjenta po reprezentującym go id
     * @param Patient
     * @return int
     */
    PatientRecord getPatientById(int id);

    void setDynamicSearch(bool);
    void addPatient(Patient patient);

public slots:
    void searchClicked();
    void searchChanged(QString);
    void searchComboxChanged(int);

    /**
      * Metoda pozwala wyszukiwać pacjentów w tabeli
      * @param void
      * @return void
      */
    void search(int column, QString searchText);

    /**
      * Metoda odświeżająca tabele
      * @param void
      * @return void
      */
    void updateModel();

private slots:
   void lineEditChanged();

   /**
     * Slot wywoływany podwójnym kliknieciem na pacjenta w tabeli.
     * Wyświetla dialog z informacjami o pacjencie.
     * @param void
     * @return void
     */
   void itemDoubleClicked(QModelIndex);

   /**
     * Slot wyświetla dialog z informacjami o pacjencie.
     * @param void
     * @return void
     */
   void showPatientMenuClicked();

   /**
     * Slot wyświetla dialog z informacjami o pacjencie.
     * @param int, bool
     * @return void
     */
   void showPatient(int patientID, bool edit);

   /**
     * Slot pozwalający generować dokumenty pdf z informacjami o pacjencie
     * @param void
     * @return void
     */
   void generatePdf();

   /**
     * Slot wyświetlający diagram zębowy pacjenta
     * @param void
     * @return void
     */
   void showTeethDialog();


   /**
     * Slot wyświetlający dialog edycji danych pacjenta
     * @param void
     * @return void
     */
   void showEditPatientDialog();

   /**
     * Slot drukuje karte pacjenta
     * @param void
     * @return void
     */
   void printPatient();

private:
    void createGui();
    void setMessageLabel();

    /**
      * Metoda aktualizująca dane wybranego pacjenta
      * @param int, Patient
      * @return void
      */
    void editPatient(Patient patient);

    /**
      * Metoda tworzy model dla CardfileTable
      * @param void
      * @return void
      */
    void createModel();

    /**
      * Metoda tworzy CardfileTable
      * @param void
      * @return void
      */
    void createTable();

    /**
      * Metoda tworzy QStringList labels z nazwami kolumn
      * @param void
      * @return void
      */
    void createLabels();

    /**
      * Metoda tworzy słownik nazw kolumn wyświetlanych
      * i nazw kolumn z bazy danych
      * @param void
      * @return void
      */
    void createDictionary();

    /**
      * Metoda aktualizuje nazwy kolumn.
      * Podmienia rzeczywiste nazwy column z bazy danych
      * na ich polskie odpowienidki wczytywane z QStringList labels
      * @param void
      * @return void
      */
    void updateColumnName();

    /**
      * Metoda tworzy główny layout widgetu
      * @param void
      * @return void
      */
    void createLayout();

    /**
      * Metoda tworzy menu kontekstowe tabeli
      * @param void
      * @return void
      */
    void createContextMenu();


    QAction *generatePdfAction;
    QAction *showPatientAction;
    QAction *showTeethDialogAction;
    QAction *editPatientAction;
    QAction *printPatientAction;
    QAction *addVisitAction;
    QAction *showVisitAction;
    QAction *showPhotosAction;
    QAction *addPrescriptionAction;
    QAction *showPrescriptionAction;

    QSqlTableModel *model;
    QSqlDatabase *db;

    QMap<QString, QString> dictionary;

    CardfileTable *cardfileTable;


    QStringList labels;

    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QLabel *messageLabel;
    QLabel *searchLabel;
    QLabel *searchImageLabel;
    QComboBox *searchComboBox;

};

#endif // CARDFILE_H
