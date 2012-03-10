#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>

class QLabel;

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = 0);

    void loadFromFile(const QString& image);
private:
    void createImageLabel();

    QLabel *imageLabel;


};

#endif // IMAGEVIEWER_H
