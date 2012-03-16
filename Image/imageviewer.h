#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>

class QLabel;
class QScrollArea;
class QScrollBar;

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = 0);
    explicit ImageViewer(const QString& fileName, QWidget *parent = 0);

    void loadFromFile(const QString& image);
    void setNormalSize();
    void zoomIn();
    void zoomOut();

protected:
    void mouseDoubleClickEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *);

signals:
    void clicked();

private:
    void init();
    void createLayout();
    void createImageLabel();
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);


    double scaleFactor;
    QLabel *imageLabel;
    QScrollArea *scrollArea;

};

#endif // IMAGEVIEWER_H
