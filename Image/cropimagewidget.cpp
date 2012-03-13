#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolBar>
#include <QtGui>
#include "imageviewer.h"
#include "croplabel.h"

#include "cropimagewidget.h"

CropImageWidget::CropImageWidget(QWidget *parent) :
    QWidget(parent)
{
    createImageViewer();
    createToolBar();
    createLayout();
    setWindowTitle( tr("Utwórz miniature") );
}

void CropImageWidget::createLayout()
{
    QHBoxLayout *toolBarLayout = new QHBoxLayout;
    toolBarLayout->addStretch();
    toolBarLayout->addWidget(toolBar);
    toolBarLayout->setMargin(0);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(cropLabel);
    mainLayout->addLayout(toolBarLayout);
    mainLayout->setMargin(0);


    setLayout(mainLayout);
}

void CropImageWidget::createImageViewer()
{
    cropLabel = new CropLabel;
    QImage image("xray.jpg");
    resize(image.size());

    cropLabel->setPixmap(QPixmap::fromImage(image));
}

void CropImageWidget::createToolBar()
{
    okAction = new QAction( tr("&Akceptuj"), this);
    okAction->setIcon(QIcon(":/icons/ok.png"));
    okAction->setStatusTip(tr("Akceptuj kadrowanie"));

    backAction = new QAction( tr("&Confij"), this);
    backAction->setIcon(QIcon(":/icons/Cancel.png"));

    toolBar = new QToolBar;
    toolBar->setIconSize(QSize(16,16));
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBar->setBackgroundRole(QPalette::Dark);
    toolBar->addAction(backAction);
    toolBar->addAction(okAction);
}
