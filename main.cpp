/**
  * @mainpage
  * @par About Dentix
  * Soon more info.
  * @author
  * @date 11.11.2011
  * @version 1.0
  * @par Contact:
  * If you have any question, sugestion, etc., please mail me.
  * @par TODO:
  * See @ref todo
*/

#include <QApplication>
#include <QSplashScreen>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QTextCodec>
#include "mainwindow.h"
#include <QDebug>
#include "Wizard/wizard.h"

//#include <windows.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

//    NoteDialog n;
//    n.show();

//    QTranslator qtTranslator;
//    qtTranslator.load("qt_" + QLocale::system().name(),
//             QLibraryInfo::location(QLibraryInfo::TranslationsPath));
//    a.installTranslator(&qtTranslator);

//    QTranslator myappTranslator;
//    qDebug() << myappTranslator.load("superapp_en");
//    a.installTranslator(&myappTranslator);


    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/icons/splash.jpg"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Uruchamianie okna..."), topRight, Qt::black);
    sleep(1);
    MainWindow w;
    splash->showMessage(QObject::tr("Ładowanie modułów..."), topRight, Qt::black);
    //sleep(2);
    splash->showMessage(QObject::tr("Tworzenie połączenia z bazą danych..."), topRight, Qt::black);
    //sleep(2);
    w.show();
    splash->finish(&w);
    delete splash;

//    Wizard x;
//    x.show();

    return a.exec();
}

// dodać obsługe zdjęć pacjenta
// dodać obsługe mail
// oznaczanie na zdjęciach rentgenowskich


/*

- przy wyszukiwaniu pacjenta po wciśnieciu enter, focus na qtableview + obsługa góra/dół

-przechwycenie focusa do searchLineEdit po zamknięciu dialogu showPatientDialog
- Gdzie metoda dodająca pacjenta do bazy
- Jak zrobić opcje programu?

-format daty
-kolory tabeli

 */
