#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>

class QLabel;
class QScrollArea;

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = 0);

    void loadFromFile(const QString& image);

protected:
    void resizeEvent(QResizeEvent *);

private:
    void createImageLabel();

    QLabel *imageLabel;
    QScrollArea *scrollArea;

};

#endif // IMAGEVIEWER_H
