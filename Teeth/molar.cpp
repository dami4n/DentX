#include <QtGui>
#include "molar.h"

Molar::Molar()
{
    createPolygons();

}

void Molar::createPolygons()
{
    QVector<QPoint> up_points;
    up_points.push_back(QPoint(49, -49));
    up_points.push_back(QPoint(-49, -49));
    up_points.push_back(QPoint(-20, -20));
    up_points.push_back(QPoint(20, -20));

    QVector<QPoint> down_points;
    down_points.push_back(QPoint(-20, 20));
    down_points.push_back(QPoint(20, 20));
    down_points.push_back(QPoint(49, 49));
    down_points.push_back(QPoint(-49, 49));

    QVector<QPoint> left_points;
    left_points.push_back(QPoint(-49, -49));
    left_points.push_back(QPoint(-49, 49));
    left_points.push_back(QPoint(-20, 20));
    left_points.push_back(QPoint(-20, -20));

    QVector<QPoint> right_points;
    right_points.push_back(QPoint(20, 20));
    right_points.push_back(QPoint(20, -20));
    right_points.push_back(QPoint(49, -49));
    right_points.push_back(QPoint(49, 49));

    QVector<QPoint> center_points;
    center_points.push_back(QPoint(-20, -20));
    center_points.push_back(QPoint(-20, 20));
    center_points.push_back(QPoint(20, 20));
    center_points.push_back(QPoint(20, -20));

    up_p = QPolygon (up_points);
    down_p = QPolygon (down_points);
    left_p = QPolygon (left_points);
    right_p = QPolygon (right_points);
    center_p = QPolygon (center_points);

}

void Molar::paintPart()
{
    paintGrid();

    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setWindow(-50, -50, 100, 100);

    QColor tmpColor = color;

    if( part.contains(Left) )
    {
        color = part[Left];
        brush.setColor(color);
        painter.setBrush( brush );
        painter.drawPolygon(left_p);
    }

    if( part.contains(Right) )
    {
        color = part[Right];
        brush.setColor(color);
        painter.setBrush( brush );
        painter.drawPolygon(right_p);
    }

    if( part.contains(Up) )
    {
        color = part[Up];
        brush.setColor(color);
        painter.setBrush( brush );
        painter.drawPolygon(up_p);
    }

    if( part.contains(Down) )
    {
        color = part[Down];
        brush.setColor(color);
        painter.setBrush( brush );
        painter.drawPolygon(down_p);
    }

    if( part.contains(Center) )
    {
        color = part[Center];
        brush.setColor(color);
        painter.setBrush( brush );
        painter.drawPolygon(center_p);
    }

    color = tmpColor;

    update();
}

void Molar::paintGrid()
{
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush( Qt::white);
    painter.drawRect( pixmap.rect() );

    painter.setPen(Qt::black);

    painter.setWindow( -50, -50, 100, 100);

    painter.drawRect( -49,-49, 98, 98);
    painter.drawRect( -20, -20, 40, 40);

    painter.drawLine(-49,-49, -20, -20);
    painter.drawLine( 49, -49, 20, -20);
    painter.drawLine(-49,49, -20, 20);
    painter.drawLine( 49, 49, 20, 20);

    update();
}
