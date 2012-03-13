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

     PatientRecord rec = d.getPatientById("1");
     qDebug() << rec["name"];

     CropImageWidget *image = new CropImageWidget;
     image->show();

}

