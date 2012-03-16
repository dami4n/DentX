#include <QDebug>
#include <Image/imageviewer.h>

#include "radiograph.h"

Radiograph::Radiograph(QWidget *parent) :
    QListView(parent)
{
    showPhoto(" ");
}

void Radiograph::doubleClicked(const QModelIndex &index)
{


}

void Radiograph::showPhoto(const QString &fileName)
{
    ImageViewer *image = new ImageViewer("megan.jpg");
    //image->show();
    qDebug() << "Hello";
}
