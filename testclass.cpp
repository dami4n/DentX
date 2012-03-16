#include "Database/databasepatient.h"
#include "Image/imageviewer.h"
#include "Image/cropimagewidget.h"
#include <QList>
#include <QMap>
#include <QDebug>
#include "Image/croplabel.h"

#include "testclass.h"

TestClass::TestClass(QObject *parent) :
    QObject(parent)
{
     DatabasePatient d;
     PatientRecord r = d.getPatientById("1");
     r["name"] = "Michał";
     d.updatePatient(r);

     PatientRecord rec = d.getPatientById("1");
     qDebug() << rec["name"];

     ImageViewer *image = new ImageViewer("megan.jpg");
     //image->show();

}

