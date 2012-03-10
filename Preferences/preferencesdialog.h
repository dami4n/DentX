/**
  * PreferencesDialog
  * Klasa reprezentująca dialog z ustawieniami programu.
  */

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>

// posortować alfabetycznie
class QCheckBox;
class QPushButton;
class QGroupBox;
class QHBoxLayout;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;
class QStackedLayout;
class GeneralPageWidget;
class LookPageWidget;
class AdvancedPageWidget;
class DatabasePageWidget;
class ClinicPageWidget;
class Preferences;

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    PreferencesDialog(QWidget *parent = 0);

private slots:

    /**
      * Slot wywoływany po naciśnięciu przycisku 'Zastosuj'
      * @param void
      * @return void
      */
    void applyClicked();

    /**
      * Slot wywoływany po naciśnięciu przycisku 'ok'
      * @param void
      * @return void
      */
    void okClicked();

protected:
  //  void keyPressEvent(QKeyEvent *);

private:
    /**
      * Metoda tworzy ustawienia podstawowe
      * @param void
      * @return void
      */
    void createMainPage();

    /**
      * Metoda tworzy ustawienia wyglądu
      * @param void
      * @return void
      */
    void createLookPage();

    /**
      * Metoda tworzy ustawienia zaawanasowane
      * @param void
      * @return void
      */
    void createAdvancedPage();

    /**
      * Metoda tworzy ustawienia bazy danych
      * @param void
      * @return void
      */
    void createDatabasePage();


    /**
      * Metoda tworzy ustawienia gabinetu
      * @param void
      * @return void
      */
    void createClinicPage();

    /**
      * Metoda tworzy layout dialogu
      * @param void
      * @return void
      */
    void createLayout();

    /**
      * Metoda tworzy stos layout'ów
      * @param void
      * @return void
      */
    void createStackedLayout();

    /**
      * Metoda tworzy przyciski dialogu
      * @param void
      * @return void
      */
    void createButtons();

    void createPrefernces();

    Preferences *preferences;

    QStackedLayout *stackedLayout; /*!< */
    QListWidget *listWidget; /*!< Lista widgetow */

    GeneralPageWidget *mainPage; /*!< Widget na którym znajdują się ustawienia podstawowe */
    LookPageWidget *lookPage; /*!< Widget na którym znajdują się ustawienia wyglądu  */
    AdvancedPageWidget *advancedPage; /*!< Widget na którym znajdują się ustawienia zaawansowane */
    DatabasePageWidget *databasePage;  /*!< Widget na którym znajdują się ustawienia bazy danych */
    ClinicPageWidget *clinicPage;  /*!< Widget na którym znajdują się ustawienia gabinetu */

    QPushButton *okButton; /*!< Przycisk OK */
    QPushButton *cancelButton; /*!< Przycisk Anuluj */
    QPushButton *applyButton; /*!< Przycisk Zastosuj */

    QHBoxLayout *buttonsLayout; /*!< Layout przycisków */

    QCheckBox *runMaximized; /*!< Uruchom zmaksymalizowany */

    //cardfile
    bool dynamicSearch; /*!< Dynamiczne wyszukiwanie */
    bool verticalHeader; /*!< ukrycie/pokazanie header'u tabeli */

    //timesheet
    QColor specialCellColor; /*!< kolor komórek specjanych */

};

#endif // PREFERENCESDIALOG_H
