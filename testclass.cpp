#include "Database/databasepatient.h"
#include "Image/imageviewer.h"
#include <QList>
#include <QMap>
#include <QDebug>
#include "testclass.h"

TestClass::TestClass(QObject *parent) :
    QObject(parent)
{
     DatabasePatient d;

     PatientRecord rec = d.getPatientById("1");
     qDebug() << rec["name"];

     ImageViewer *image;
     image = new ImageViewer;
     image->loadFromFile("megan.jpg");
     image->show();

}

