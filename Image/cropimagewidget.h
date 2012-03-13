#ifndef CROPIMAGEWIDGET_H
#define CROPIMAGEWIDGET_H

#include <QWidget>

class CropLabel;
class QToolBar;
class QAction;

class CropImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CropImageWidget(QWidget *parent = 0);


private:
    void createLayout();
    void createToolBar();
    void createImageViewer();

    CropLabel *cropLabel;
    QToolBar *toolBar;
    QAction *okAction;
    QAction *backAction;

};

#endif // CROPIMAGEWIDGET_H
