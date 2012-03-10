/**
  * PdfCreator
  * Klasa generująca dokumnety pdf.
  * Klasa pozwala na zapisanie karty pacjneta w formacie PDF
  */

#ifndef PDFCREATOR_H
#define PDFCREATOR_H

#include <QObject>
#include "patient.h"

class QPrinter;

class PdfCreator : public QObject
{
    Q_OBJECT
public:
    explicit PdfCreator(QObject *parent = 0);

    void createPrinter();
    void createPatientPage(const Patient patient);
    void createPrescription(const Patient patient);
    void printHtml(const QString &html);

    QPrinter *printer;

};

#endif // PDFCREATOR_H
