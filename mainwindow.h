#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QStackedLayout;
class QTableWidget;
class QTextEdit;
class QVBoxLayout;
class NoteViewer;
class ReminderViewer;
class CardFile;
class SpeedDial;
class Timesheet;
class Preferences;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    /**
      * Event wywoływany przy zamknięciu aplikacji
      * @param void
      * @return void
      */
    void closeEvent(QCloseEvent *);


public slots:
    /**
      * Slot wyświetlający informacje o programie
      * @param void
      * @return void
      */
    void about();

    /**
      * Slot wyświetlający dialog dodania notatki
      * @param void
      * @return void
      */
    void addNote();

    /**
      * Slot wyświetlający dialog dodania przypomnienia
      * @param void
      * @return void
      */
    void addReminder();


    /**
      * Slot wyświetlający dialog dodania nowego pacjenta
      * @param void
      * @return void
      */
    void addPatient();

    /**
      * Slot wyświetlający katalog pacjentów
      * @param void
      * @return void
      */
    void catalogue();

    /**
      * Slot wyświetlający ekran startowy
      * @param void
      * @return void
      */
    void speeddial();

    /**
      * Slot kopiujący zawartość do schowka
      * @param void
      * @return void
      */
    void copy();

    /**
      * Slot wycinający zawartość do schowka
      * @param void
      * @return void
      */
    void cut();

    /**
      * Slot wklejający zawartość ze schowka
      * @param void
      * @return void
      */
    void paste();


    /**
      * Slot odpowiedzialny za eksport bazy do pliku XML
      * @param void
      * @return void
      */
    void exportToXml();

    /**
      * Slot odpowiedzialny za import bazy z pliku XML
      * @param void
      * @return void
      */
    void importFromXml();

    /**
      * Slot wyświetlający pomoc w programie
      * @param void
      * @return void
      */
    void help();

    /**
      * Slot wyświetlający dialog z preferencjami programu
      * @param void
      * @return void
      */
    void options();

    /**
      * Slot wyświetlający przypomnienia
      * @param void
      * @return void
      */
    void notesViewer();

    /**
      * Slot wyświetlający przypomnienia
      * @param void
      * @return void
      */
    void remindersViewer();


    /**
      * Slot włączający/wyłączający tryb pełnego ekranu
      * @param void
      * @return void
      */
    void setFullscreen(bool);


    /**
      * Slot włączający/wyłączający tryb pełnego ekranu
      * @param void
      * @return void
      */
    void setStatusBarVisible(bool);

    /**
      * Slot wyświetlający grafik wizyt
      * @param void
      * @return void
      */
    void timesheet();

    /**
      * Slot wyświetlający dialog pozwalający debugować baze danych
      * Umożliwia wydawanie zapytań do bazy danych
      * @param void
      * @return void
      */
    void debugDatabase();


    /**
      * Slot wywoływany po zmianie ustawień toolbara
      * @param void
      * @return void
      */
    void toolbarChanged();

    /**
      * Slot wywoływany po zmianie ustawień wyszukiwania
      * @param void
      * @return void
      */
    void dynamicSearchChanged();

private:
    /**
      * Metoda ustawia polskie znaki w aplikacji
      * @param void
      * @return void
      */
    void setTextCodec();

    /**
      * Metoda odpowiedzialna za tworzenie/otwieranie bazy danych
      * @param void
      * @return void
      */


    void createDatabase();

    /**
      * Metoda tworząca akcje aplikacji
      * @param void
      * @return void
      */
    void createActions();

    /**
      * Metoda tworzy menu aplikacji
      * @param void
      * @return void
      */
    void createMenus();

    /**
      * Metoda tworzy StatusBar aplikacji
      * @param void
      * @return void
      */
    void createStatusBar();

    /**
      * Metoda tworzy ToolBar aplikacji
      * @param void
      * @return void
      */
    void createToolBars();

    /**
      * Metoda tworzy katalog pacjentów
      * @param void
      * @return void
      */
    void createCardFile();

    /**
      * Metoda tworzy grafik wizyt
      * @param void
      * @return void
      */
    void createTimesheet();

    /**
      * Metoda tworzy zakładkę wyświetlającą notatki
      * @param void
      * @return void
      */
    void createNoteViewer();

    /**
      * Metoda tworzy zakładkę wyświetlającą przypomnienia
      * @param void
      * @return void
      */
    void createReminderViewer();

    /**
      * Metoda tworzy zakładkę z ekranem startowym
      * @param void
      * @return void
      */
    void createSpeedDial();


    void createStackedLayout();
    void createPreferences();

    // main menu
    QMenu *fileMenu; /*!< Plik */
    QMenu *editMenu; /*!< Edycja */
    QMenu *viewMenu; /*!< Widok */
    QMenu *noteMenu; /*!< Notatki */
    QMenu *optionsMenu; /*!< Opcje */
    QMenu *helpMenu; /*!< Pomoc */

    QAction *speedDialAction;

    // file menu
    QAction *catalogueAction; /*!< Katalog pacjentów */
    QAction *timesheetAction; /*!< Grafik wizyt */
    QAction *addPatientAction; /*!< Dodaj pacjenta */
    QAction *exitAction; /*!< Wyjście */

    // edit menu
    QAction *cutAction; /*!< Wytnij */
    QAction *pasteAction; /*!< Wklej */
    QAction *copyAction; /*!< Kopiuj */

    // view menu
    QAction *showFullscreenAction; /*!< Pełen ekran */
    QAction *statusBarVisibleAction; /*!< Pokaż pasek statusu */

    // note menu
    QAction *addNoteAction; /*!< Dodaj notatkę */
    QAction *addReminderAction; /*!< Dodaj przypomnienie */
    QAction *noteViewerAction; /*!< Pokaż notatki */
    QAction *reminderViewerAction; /*!< Pokaż notatki */

    // options menu
    QAction *exportToXmlAction; /*!< Eksport pacjentów do XML */
    QAction *importFromXmlAction; /*!< Import pacjnetów z XML */
    QAction *optionsAction;  /*!<  */

    // help menu
    QAction *helpAction; /*!< Pomoc */
    QAction *aboutAction; /*!< O programie */
    QAction *aboutQtAction; /*!< O QT */
    QAction *debugDatabaseAction; /*!< Debug bazy danych  */

    // stacked layouts
    QStackedLayout *stackedLayout;

    // toolbar
    QToolBar *toolBar;

    // Widgets
    QWidget *mainWindowWidget;
    QWidget *speedDialWidget;
    QWidget *cardFileWidget;
    QWidget *timesheetWidget;
    QWidget *noteViewerWidget;
    QWidget *reminderViewerWidget;

    CardFile *cardFile;
    NoteViewer *noteViewer;
    ReminderViewer *reminderViewer;
    SpeedDial *speedDial;
    Timesheet *timeSheet;
    Preferences *preferences;

    QVBoxLayout *speedDialLayout;

};

#endif // MAINWINDOW_H
