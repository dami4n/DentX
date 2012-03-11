#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QPixmap>
#include <QtGui>
#include "imageviewer.h"

#include "cropimagewidget.h"

CropImageWidget::CropImageWidget(QWidget *parent) :
    QWidget(parent)
{
    createImageViewer();

    pixmap = QPixmap(size());

    createLayout();

    paint();

    setWindowTitle( tr("Utwórz miniature") );
}

void CropImageWidget::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(imageViewer);

    setLayout(mainLayout);
}

void CropImageWidget::createImageViewer()
{
    imageViewer = new ImageViewer;
    imageViewer->loadFromFile("megan.jpg");
}

void CropImageWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.drawPixmap(0,0, pixmap);
    painter.setWindow( -50, -50, 100, 100);
}

void CropImageWidget::paint()
{
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush( Qt::white);
    painter.drawRect( pixmap.rect() );

    painter.setPen(Qt::black);

    painter.setWindow( -50, -50, 100, 100);
    painter.drawRect( -49,-49, 98, 98);

    update();
}
