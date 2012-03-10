#include <QPushButton>
#include <QLabel>
#include <QIcon>
#include <QTextCodec>
#include <QToolBar>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QString>
#include <QFileDialog>
#include <QDialog>
#include <QCloseEvent>
#include <QAction>
#include <QMenu>
#include <QKeySequence>
#include <QDebug>
#include <QStatusBar>
#include <QMenuBar>
#include <QApplication>
#include "mainwindow.h"
#include "Database/database.h"
#include "Database/databasedebugdialog.h"
#include "Note/addnotedialog.h"
#include "Note/shownotedialog.h"
#include "Note/note.h"
#include "Note/notefunction.h"
#include "Note/noteviewer.h"
#include "Preferences/preferencesdialog.h"
#include "Preferences/preferences.h"
#include "PatientDialog/addpatientdialog.h"
#include "Xml/xmlwriter.h"
#include "Cardfile/cardfile.h"
#include "SpeedDial/speeddial.h"
#include "Timesheet/timesheet.h"
#include "Reminder/addreminderdialog.h"
#include "Reminder/reminderviewer.h"
#include "Reminder/reminderfunction.h"
#include "Reminder/reminder.h"
#include "demo.h"
#include <QDebug>
#include <QtSql>
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QTextDocument>
#include "Pdf/pdfcreator.h"

#include "testclass.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    createPreferences();

    setTextCodec();
    createDatabase();

//    Demo demo;
//    demo.createExampleUser();
//    demo.createExampleNote();

    createActions();
    createMenus();
    createStatusBar();
    createToolBars();
    createCardFile();
    createSpeedDial();
    createTimesheet();
    createNoteViewer();
    createReminderViewer();
    createStackedLayout();

    setWindowTitle( tr("DentX") );
    setWindowIcon( QIcon(":/icons/twitter.png")); // tę ikone się zmieni

    resize( 800, 600 );

    TestClass *t = new TestClass(this);

}

void MainWindow::createPreferences()
{
    preferences = Preferences::getInstance();
    preferences->setDatabaseType(Preferences::SQLITE);
   // preferences->load();

    // wczytaj geometrie
    if( preferences->getAlwaysMax() )
        showMaximized();
    if( preferences->getSavePosition() )
        restoreGeometry( preferences->getGeometry() );

    connect(preferences, SIGNAL(movableToolBarChanged()),
            this, SLOT(toolbarChanged()));
    connect(preferences, SIGNAL(dynamicSearchChanged()),
            this, SLOT(dynamicSearchChanged()));

}


void MainWindow::setTextCodec()
{
    // ustawia w aplikacji polskie znaki

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}


void MainWindow::createDatabase()
{
    // tworzy w bazie danych tabele jeżeli nie istnieją
    // w przypadku problemów wyświetla dialogi z informacją

    Database database;

    if( database.createDatabase() == -1 )
    {
        QMessageBox::warning(this, tr("Błąd bazy danych"), "Otwarcie bazy danych nie powiodło się.");
        return;
    }
    if( database.createTablePatinets() == -1 )
        QMessageBox::warning(this, tr("Błąd bazy danych"), "Błąd tworzenia tabeli.");
    if( database.createTableNote() == -1 )
        QMessageBox::warning(this, tr("Błąd bazy danych"), "Błąd tworzenia tabeli.");
    if( database.createTableReminder() == -1 )
        QMessageBox::warning(this, tr("Błąd bazy danych"), "Błąd tworzenia tabeli.");
    if( database.createTableHistory() == -1 )
        QMessageBox::warning(this, tr("Błąd bazy danych"), "Błąd tworzenia tabeli.");
    if( database.createTableTeethDescription() == -1 )
        QMessageBox::warning(this, tr("Błąd bazy danych"), "Błąd tworzenia tabeli.");

}

void MainWindow::createToolBars()
{
    // dodaje akcje(z ikonami) do toolBar'u

    toolBar = addToolBar( tr("&DentX"));
    toolBar->addAction(speedDialAction);
    toolBar->addAction(catalogueAction);
    toolBar->addAction(timesheetAction);    
    toolBar->addAction(reminderViewerAction);
    toolBar->addAction(noteViewerAction);
    toolBar->addSeparator();    
    toolBar->addAction(addPatientAction);
    toolBar->addAction(addNoteAction);
    toolBar->addAction(addReminderAction);    
    toolBar->addSeparator();
    toolBar->addAction(exitAction);

}

void MainWindow::createStatusBar()
{
    (void*)statusBar();
}

void MainWindow::createCardFile()
{
      cardFileWidget = new QWidget;

      cardFile = new CardFile;

      QVBoxLayout *cardFileLayout = new QVBoxLayout;
      cardFileLayout->addWidget( cardFile );
      cardFileWidget->setLayout(cardFileLayout);

}

void MainWindow::createTimesheet()
{
    timesheetWidget = new QWidget;

    timeSheet = new Timesheet;

    QVBoxLayout *timesheetLayout = new QVBoxLayout;
    timesheetLayout->addWidget( timeSheet );
    timesheetWidget->setLayout(timesheetLayout);

}

void MainWindow::createNoteViewer()
{
    noteViewerWidget = new QWidget;

    noteViewer = new NoteViewer;

    QVBoxLayout *noteViewerLayout = new QVBoxLayout;
    noteViewerLayout->addWidget(noteViewer);

    noteViewerWidget->setLayout(noteViewerLayout);

}

void MainWindow::createReminderViewer()
{
    reminderViewer = new ReminderViewer;

    reminderViewerWidget = new QWidget;

    QVBoxLayout *reminderViewerLayout = new QVBoxLayout;
    reminderViewerLayout->addWidget(reminderViewer);

    reminderViewerWidget->setLayout(reminderViewerLayout);
}

void MainWindow::createSpeedDial()
{
    speedDialWidget = new QWidget;

    speedDial = new SpeedDial;
    connect(speedDial, SIGNAL(showButtonClicked()), this, SLOT(catalogue()));
    connect(speedDial, SIGNAL(addNoteButtonClicked()), this, SLOT(addNote()));
    connect(speedDial, SIGNAL(addPatientButtonClicked()), this, SLOT(addPatient()));

    QVBoxLayout *speedDialLayout = new QVBoxLayout;
    speedDialLayout->addWidget(speedDial);

    speedDialWidget->setLayout(speedDialLayout);

}

void MainWindow::createStackedLayout()
{
    stackedLayout = new QStackedLayout;
    stackedLayout->addWidget(cardFileWidget);
    stackedLayout->addWidget(timesheetWidget);
    stackedLayout->addWidget(noteViewerWidget);
    stackedLayout->addWidget(speedDialWidget);
    stackedLayout->addWidget(reminderViewerWidget);

    mainWindowWidget = new QWidget;
    mainWindowWidget->setLayout(stackedLayout);

    setCentralWidget(mainWindowWidget);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("O programie."),
                       tr("<center><h2>DentX 0.1</h2></center>"
                          "<center><p>Copyright &copy; 2011 </center><br>"
                          "Program ułatwiający zarządzanie gabinetem dentystycznym<br>"
                          "<center><b>Autorzy:</b> :):):) <br>"
                          "<b>Ikony w programie:</b> <a href=\"http://www.smashingmagazine.com\">http://www.smashingmagazine.com "
                          "</b> <a \"http://min.frexy.com\">http://min.frexy.com "));

    // todo icon - http://marcelomarfil.deviantart.com
    // http://www.centigrade.de/ Free Medical Stock Icons: The Centigrade MedicalSeries
    // http://commons.wikimedia.org/wiki/Crystal_Clear

}

void MainWindow::catalogue()
{
  // ustawia 'katalog pacjentów' jako aktualnie widoczny widget

  stackedLayout->setCurrentWidget(cardFileWidget);

}

void MainWindow::timesheet()
{
    // ustawia 'grafik wizyt' jako aktualnie widoczny widget

    stackedLayout->setCurrentWidget(timesheetWidget);
}

void MainWindow::notesViewer()
{
    // ustawia 'notatki' jako aktualnie widoczny widget

    stackedLayout->setCurrentWidget(noteViewerWidget);
}

void MainWindow::remindersViewer()
{
    // ustawia 'notatki' jako aktualnie widoczny widget

    stackedLayout->setCurrentWidget(reminderViewerWidget);
}


void MainWindow::speeddial()
{
    // ustawia 'ekran startowy' jako aktualnie widoczny widget

    stackedLayout->setCurrentWidget(speedDialWidget);
}


void MainWindow::exportToXml()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Plik do zapisu"),
                                                    tr("pacjenci.xml"));

    if( !fileName.isEmpty() )
    {
        XmlWriter xmlWriter;

        int fileSave = xmlWriter.writePatientsToXmlFile(fileName);

        if( fileSave == 0 )
            return;
        if( fileSave == -1)
        {
            QMessageBox::warning(this, tr("Bląd zapisu"),
                                tr("Nie można otworzyć pliku do zapisu"));
            return;
       }
    }
}

void MainWindow::importFromXml()
{

}


void MainWindow::addNote()
{
    // dialog z dodawaniem nowych notatek


    AddNoteDialog addNoteDialog;

    NoteFunction noteFunction;

    if( addNoteDialog.exec() == QDialog::Accepted )
    {
        Note note = addNoteDialog.getNote();

        qDebug() << "Note: " << note.text;

        noteFunction.addNoteToDatabase(note);

        // to miało działać autoamtycznie z sygnałem z NoteFunction
        // tymczasowo działa ręcznie
        noteViewer->changed();
    }
}

void MainWindow::addReminder()
{
    AddReminderDialog *addReminderDialog = new AddReminderDialog;

    ReminderFunction reminderFunction;

    if( addReminderDialog->exec() == QDialog::Accepted )
    {
        Reminder reminder = addReminderDialog->getReminder();

        reminderFunction.addReminderToDatabase(reminder);

        reminderViewer->changed();
    }
}


void MainWindow::closeEvent(QCloseEvent *)
{
    qDebug() << "Zamykanie";

    preferences->saveGeometry( saveGeometry() );
    preferences->writeSettings();

}

void MainWindow::debugDatabase()
{
      DatabaseDebugDialog debug;
      debug.exec();
}

void MainWindow::addPatient()
{
    AddPatientDialog *addPatientDialog = new AddPatientDialog;

    if( addPatientDialog->exec() == QDialog::Accepted )
    {
        Patient patient;
        patient = addPatientDialog->getPatient();
        cardFile->addPatient(patient);

        QMessageBox::information(this, tr("DentX"),
            tr("Pacjent został dodany do katalogu"));

    }
}

void MainWindow::options()
{
      PreferencesDialog preferences;
      preferences.exec();

}


void MainWindow::cut()
{
    // nie wiem czy będzie potrzebne
}

void MainWindow::paste()
{
    // nie wiem czy będzie potrzebne
}

void MainWindow::copy()
{
    // nie wiem czy będzie potrzebne
}

void MainWindow::help()
{
    // wyświetlanie dialogu pomocy
}

void MainWindow::setFullscreen(bool value)
{
    if( value )
        showFullScreen();
    else
        showNormal();
}

void MainWindow::setStatusBarVisible(bool value)
{
    statusBar()->setVisible(value);
}


void MainWindow::createActions()
{
    speedDialAction = new QAction( trUtf8("Ekran startowy"), this );
    speedDialAction->setIcon(QIcon(":/icons/Add.png"));
    speedDialAction->setStatusTip( tr("Pokaż ekran startowy") );
    speedDialAction->setIconVisibleInMenu(true);
    connect(speedDialAction, SIGNAL(triggered()), this, SLOT(speeddial()));

    // file
    catalogueAction = new QAction( trUtf8("&Katalog pacjentów"), this );
    catalogueAction->setIcon(QIcon(":/icons/cardfile.png"));
    catalogueAction->setShortcut(tr("Ctrl+K"));
    catalogueAction->setStatusTip( tr("Przeglądaj katalog pacjentów") );
    connect(catalogueAction, SIGNAL(triggered()), this, SLOT(catalogue()));

    timesheetAction = new QAction( tr("&Grafik wizyt") , this );
    timesheetAction->setIcon(QIcon(":/icons/timesheet.png"));
    timesheetAction->setShortcut( tr("Ctrl+G") );
    timesheetAction->setStatusTip( tr("Wyświetl grafik wizyt") );
    connect(timesheetAction, SIGNAL(triggered()), this, SLOT(timesheet()));

    addPatientAction = new QAction( tr("&Dodaj nowego pacjenta"), this );
    addPatientAction->setShortcut( tr("Ctrl+D") );
    addPatientAction->setIcon(QIcon(":/icons/addPatient.png"));
    addPatientAction->setStatusTip( tr("Dodaj nowego pacjenta do bazy danych") );
    connect(addPatientAction, SIGNAL(triggered()), this, SLOT(addPatient()));

    exitAction = new QAction( tr("&Wyjście z programu"), this );
    exitAction->setShortcut( tr("Ctrl+W") );
    exitAction->setIcon(QIcon(":/icons/Exit.png"));
    exitAction->setStatusTip("Zamknij program");
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()) );


    // edit
    cutAction = new QAction( tr("Wy&tnij"), this );
    cutAction->setStatusTip( tr("Wytnij zaznaczoną treść do schowka") );
    cutAction->setShortcut(QKeySequence::Cut);
    connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));
    cutAction->setEnabled(false);

    copyAction = new QAction( tr("Kopiuj"), this );
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip( tr("Skopiuj zaznaczoną treść do schowka") );
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));
    copyAction->setEnabled(false);

    pasteAction = new QAction( tr("Wklej"), this );
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip( tr("Wklej treść ze schowka") );
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()) );
    pasteAction->setEnabled(false);

    // view
    showFullscreenAction = new QAction( tr("Pełen ekran"), this );
    showFullscreenAction->setShortcut(QKeySequence(Qt::Key_F11));
    showFullscreenAction->setStatusTip( tr("Pokaż na pełnym ekranie"));
    showFullscreenAction->setCheckable(true);
    connect(showFullscreenAction, SIGNAL(triggered(bool)), this, SLOT(setFullscreen(bool)));

    statusBarVisibleAction = new QAction( tr("Pokaż pasek statusu"), this);
    statusBarVisibleAction->setShortcut(QKeySequence(Qt::Key_F10));
    statusBarVisibleAction->setStatusTip( tr("Ukrywa pasek statusu") );
    statusBarVisibleAction->setCheckable(true);
    statusBarVisibleAction->setChecked(true);
    connect(statusBarVisibleAction, SIGNAL(triggered(bool)), this, SLOT(setStatusBarVisible(bool)));

    // note
    addNoteAction = new QAction( tr("Doda&j nową notatkę"), this );
    addNoteAction->setStatusTip( tr("Dodaj nową notatkę") );
    addNoteAction->setIcon(QIcon(":/icons/edit.png"));
    addNoteAction->setShortcut( tr("Ctrl+j") );
    connect(addNoteAction, SIGNAL(triggered()), this, SLOT(addNote()) );

    addReminderAction = new QAction( tr("Dodaj przypomnienie"), this);
    addReminderAction->setStatusTip( tr("Dodaj nowe przypomnienie") );
    addReminderAction->setIcon(QIcon(":/icons/History.png"));
    connect(addReminderAction, SIGNAL(triggered()), this, SLOT(addReminder()));

    noteViewerAction = new QAction( tr("P&rzeglądaj notatki"), this );
    noteViewerAction->setStatusTip( tr("Przeglądaj dostępne notatki") );
    noteViewerAction->setIcon( QIcon(":/icons/note.png"));
    noteViewerAction->setShortcut( tr("Ctrl+r") );
    connect(noteViewerAction, SIGNAL(triggered()), this, SLOT(notesViewer()) );

    reminderViewerAction = new QAction( tr("P&rzeglądaj przypomnienia"), this );
    reminderViewerAction->setStatusTip( tr("Przeglądaj dostępne przypomnienia") );
    reminderViewerAction->setIcon( QIcon(":/icons/Task.png"));
    reminderViewerAction->setShortcut( tr("Ctrl+r") );
    connect(reminderViewerAction, SIGNAL(triggered()), this, SLOT(remindersViewer()) );


    //options
    exportToXmlAction = new QAction( tr("Ekportuj do pliku XML"), this);
    exportToXmlAction->setStatusTip( tr("Ekportuj do pliku Xml"));
    connect(exportToXmlAction, SIGNAL(triggered()), this, SLOT(exportToXml()));

    importFromXmlAction = new QAction( tr("Importuj z pliku XML"), this);
    importFromXmlAction->setStatusTip( tr("Importuj pacjentów z pliku XML"));
    connect(importFromXmlAction, SIGNAL(triggered()), this, SLOT(importFromXml()));

    optionsAction = new QAction( tr("&Ustawienia"), this );
    optionsAction->setStatusTip( tr("Ustawienia programu") );
    optionsAction->setIcon(QIcon(":/icons/configure.png"));
    optionsAction->setShortcut(tr("Ctrl + U") );
    connect(optionsAction, SIGNAL(triggered()), this, SLOT(options()));


    // help
    helpAction = new QAction( tr("&Pomoc"), this );
    helpAction->setShortcut( tr("Ctrl+P") );
    helpAction->setStatusTip( tr("Wyświetl pliki pomocy"));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(help()) );

    debugDatabaseAction = new QAction( tr("&Tryb Debug bazy danych"), this );
    debugDatabaseAction->setStatusTip(tr("Tryb debug bazy danych") );
    connect(debugDatabaseAction, SIGNAL(triggered()), this, SLOT(debugDatabase()));

    aboutAction = new QAction( tr("&O programie"), this);
    aboutAction->setShortcut( tr("Ctrl+O"));
    aboutAction->setStatusTip("Wyświetl informacje o programie");
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()) );

    aboutQtAction = new QAction( tr("Informacje o QT..."), this );
    aboutQtAction->setStatusTip( tr("Wyświetla informacje o QT") );
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()) );
}


void MainWindow::createMenus()
{
    // file
    fileMenu = menuBar()->addMenu( tr("&Plik") );
    fileMenu->addAction(catalogueAction);
    fileMenu->addAction(timesheetAction);
    fileMenu->addAction(addPatientAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);


    // edit
    editMenu = menuBar()->addMenu( tr("&Edycja") );
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    // view
    viewMenu = menuBar()->addMenu( tr("&Widok") );
    viewMenu->addAction(showFullscreenAction);
    viewMenu->addAction(statusBarVisibleAction);

    // note
    noteMenu = menuBar()->addMenu( tr("&Notatki") );
    noteMenu->addAction(addNoteAction);
    noteMenu->addAction(addReminderAction);
    noteMenu->addAction(noteViewerAction);


    // options
    optionsMenu = menuBar()->addMenu( tr("&Opcje") );
    optionsMenu->addAction(exportToXmlAction);
    optionsMenu->addAction(importFromXmlAction);
    optionsMenu->addSeparator();
    optionsMenu->addAction(optionsAction);


    // help
    helpMenu = menuBar()->addMenu( tr("&Pomoc") );
    helpMenu->addAction(helpAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
    helpMenu->addSeparator();
    helpMenu->addAction(debugDatabaseAction);
}


void MainWindow::toolbarChanged()
{
    toolBar->setMovable( !preferences->getMovableToolBar() );
}

void MainWindow::dynamicSearchChanged()
{
    cardFile->setDynamicSearch( ! preferences->getDynamicSearch() );
}

