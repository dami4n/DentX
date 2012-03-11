#ifndef CROPIMAGEWIDGET_H
#define CROPIMAGEWIDGET_H

#include <QWidget>

class ImageViewer;

class CropImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CropImageWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    void createLayout();
    void createImageViewer();
    void paint();

    QPixmap pixmap;
    ImageViewer *imageViewer;

};

#endif // CROPIMAGEWIDGET_H
