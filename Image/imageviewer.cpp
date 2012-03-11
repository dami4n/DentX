#include <QLabel>
#include <QHBoxLayout>
#include <QImage>
#include <QScrollArea>
#include <QDebug>

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
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);
    imageLabel->adjustSize();

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setWidgetResizable(true);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(scrollArea);

    setLayout(mainLayout);
}

void ImageViewer::loadFromFile(const QString &fileName)
{
    QImage image(fileName);
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void ImageViewer::mouseDoubleClickEvent(QMouseEvent *)
{
    emit clicked();
}

void ImageViewer::setNormalSize()
{
    resize(imageLabel->pixmap()->size());
}
