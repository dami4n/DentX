#include <QLabel>
#include <QHBoxLayout>
#include <QImage>
#include <QScrollArea>
#include <QDebug>
#include <QWheelEvent>
#include <QScrollBar>

#include "imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QWidget(parent)
{
    init();
}

ImageViewer::ImageViewer(const QString &fileName, QWidget *parent) :
        QWidget(parent)
{
     init();
     loadFromFile(fileName);
}

void ImageViewer::init()
{
    createImageLabel();
    createLayout();
}

void ImageViewer::createImageLabel()
{
    scaleFactor = 1.0;

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);


    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    scrollArea->setWidgetResizable(false);

    imageLabel->adjustSize();

}

void ImageViewer::createLayout()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(scrollArea);
    mainLayout->setMargin(0);

    setLayout(mainLayout);
    resize(500, 400);
}

void ImageViewer::loadFromFile(const QString &fileName)
{
    QImage image(fileName);
    imageLabel->setPixmap(QPixmap::fromImage(image));
    setNormalSize();
}

void ImageViewer::mouseDoubleClickEvent(QMouseEvent *)
{
    emit clicked();
}

void ImageViewer::wheelEvent(QWheelEvent *event)
{

    if( event->delta() > 0 && scaleFactor < 3.0)
    {
        qDebug() << "IN";
        zoomIn();
    }
    else
    {
        if( scaleFactor > 0.33 )
        {
            qDebug() << "OUT";
            zoomOut();
        }
    }
}

void ImageViewer::setNormalSize()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void ImageViewer::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void ImageViewer::zoomIn()
{
     scaleImage(1.1);
}

void ImageViewer::zoomOut()
{
     scaleImage(0.90);
}
