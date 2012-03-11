#include <QLabel>
#include <QHBoxLayout>
#include <QImage>
#include <QScrollArea>

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

void ImageViewer::resizeEvent(QResizeEvent *)
{
    imageLabel->adjustSize();
}
