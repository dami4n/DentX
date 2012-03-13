#include <QMouseEvent>
#include <QDebug>
#include <QPainter>

#include "croplabel.h"

CropLabel::CropLabel(QWidget *parent) :
    QLabel(parent)
{
    selected = false;
    setBackgroundRole(QPalette::Base);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    setScaledContents(true);
    adjustSize();

}


void CropLabel::mousePressEvent(QMouseEvent *event)
{
    // start
    if( selectionRect.contains(event->pos()) )
    {
        selected = true;
        clicked = event->pos();
    }
    else
    {
        selectionActive = true;
        selectionRect.setTopLeft( event->pos() );
        selectionRect.setBottomRight( event->pos() );
    }
}

void CropLabel::mouseReleaseEvent(QMouseEvent *event)
{
    //end
    selectionActive = false;
    selected = false;
}

void CropLabel::mouseMoveEvent(QMouseEvent *event)
{
    if( selectionActive )
    {
       selectionRect.setBottomRight( event->pos() );
       repaint();

    }
    else
    {
      if( selected )
      {
          QRect tmp(selectionRect);
          tmp.translate(event->pos() - clicked);
          bool value = rect().contains(tmp);
          if( value )
          {
            selectionRect.translate(event->pos() - clicked);
            repaint();
          }
          clicked = event->pos();
      }
    }
}

void CropLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QLabel::paintEvent(event);

    painter.setPen(QPen(QBrush(QColor(0,0,0,180)),1,Qt::DashLine));
    painter.setBrush(QBrush(QColor(255,255,255,60)));
    painter.drawPolygon(selectionRect);
}

