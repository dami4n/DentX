#ifndef CROPLABEL_H
#define CROPLABEL_H

#include <QLabel>

class CropLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CropLabel(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool selectionActive;
    bool selected;
    QRect selectionRect;
    QPoint clicked;

};

#endif // CROPLABEL_H
