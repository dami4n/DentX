#include <QPrinter>
#include <QStringBuilder>
#include <QString>
#include <QPainter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QDebug>
#include <QtSvg>
#include <QtGui>

#include "patient.h"

#include "Teeth/diagramdialog.h"

#include "pdfcreator.h"

PdfCreator::PdfCreator(QObject *parent) :
    QObject(parent)
{
    createPrinter();

}

void PdfCreator::createPrinter()
{
    printer = new QPrinter(QPrinter::HighResolution);
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setPageSize(QPrinter::A4);

}

void PdfCreator::createPatientPage(const Patient patient)
{
    // dodać Qt::escape żeby oczyścić dane pacjenta ze znaczników

    QString html;

    html = "<html><head><body>"
           "<h1><center>Karta pacjenta</center></h1>"
           "<br><br><br><br>"
           "<b>Dane adresowe</b>"
           "<hr>"
           "<p>Imię: <b>" % patient.name % "</b>" %
           "<p>Nazwisko: <b>" % patient.lastName % "</b>" %
           "<p>Data rejestracji: <b>" % patient.registrationDate.toString() % "</b>" %
           "<p>PESEL: <b>" % patient.PESEL % "</b>" %
           "<p>Miasto: <b>" % patient.city % "</b>" %
           "<p>Adres: <b>" % patient.getAddress() % "</b>" %
           "<p>Kod pocztowy: <b>" % patient.zipCode % "</b>" %
           "<p>Telefon: <b>" % patient.phone % "</b></p>" %
           "<br><br><br>"
           "<b>Informacje dodatkowe</b>"
           "<hr>"
           "<p>Przyjmowane lekarstwa: <b>" % patient.pharmaceuticals % "</b>" %
           "<p>Alergie: <b>" % patient.allergy % "</b>" %
           "<p>Choroby: <b>" % patient.disorders % "</b>" %
           "<p>Informacje dodatkowe: <b>" % patient.note % "</b></p>" %
           "<br><br><br>"
           "<b>Badanie przedmiotowe</b>"
           "<hr>"
           "<p>Zgryz: <b>" % patient.dentalArticulation % "</b>" %
           "<p>Staw skroniowo-żuchwowy: <b>" % patient.joint % "</b>" %
           "<p>Narażenia tkanek zmineralizowanych: <b>" % patient.exposure % "</b>" %
           "<p>Barwa błony śluzowej: <b>" % patient.color % "</b>" %
           "<p>Wykwity pierwotne: <b>" % patient.efflorescencePre % "</b>" %
           "<p>Wykwity wtórne: <b>" % patient.efflorescenceSec % "</b>" %
           "<p>Ogniskowe zmiany morfologiczne: <b>" % patient.morfologicalChanges % "</b>" %
           "<p>Nalot na języku: <b>" % patient.tongue % "</b>" %
           "<p>Zaburzenia morfologiczne zębów: <b>" % patient.morfologicalDisorder % "</b>" %
           "<p>OHI: <b>" % patient.ohi % "</b>" %
           "<p>PLI: <b>" % patient.pli % "</b>" %
           "<p>API: <b>" % patient.api % "</b>" %
           "<p>Ilość śliny stymulowanej: <b>" % patient.salivaS % "</b>" %
           "<p>Ilość śliny niestymulowanej: <b>" % patient.salivaNS % "</b>" %
           "</body></head></html>";


    printHtml(html);
}




void PdfCreator::printHtml(const QString &html)
{
    qDebug() << html;

//    DiagramDialog *scr = new DiagramDialog(0);

//    WId w = scr->winId();
//    QPixmap pm = QPixmap::grabWindow(w, 0, 0, scr->width(), scr->height());
//    pm.save("nowy.png");

    QPrintDialog printDialog(printer, 0);
    if( printDialog.exec() )
    {
        QTextDocument textDocument;
        textDocument.setHtml(html);

//        textDocument.addResource(QTextDocument::ImageResource, QUrl("Dummy"), pm);

        textDocument.print(printer);
    }
}
