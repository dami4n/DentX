#include <QLabel>
#include <QHBoxLayout>
#include <QImage>

#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QWidget(parent)
{
    createImageLabel();
}

void ImageViewer::createImageLabel()
{
    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setScaledContents(true);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(imageLabel);

    setLayout(mainLayout);
}

void ImageViewer::loadFromFile(const QString &fileName)
{
    QImage image(fileName);
    imageLabel->setPixmap(QPixmap::fromImage(image));
}
