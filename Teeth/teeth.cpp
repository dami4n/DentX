#include <QtGui>
#include "adddescriptiondialog.h"

#include "teeth.h"

QColor Teeth::color = Qt::green;
bool Teeth::partEnabled = true;

Teeth::Teeth(QWidget *parent):
        QWidget(parent)
{
    pixmap = QPixmap(30, 30);

    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    white.setColor(Qt::white);
    white.setStyle(Qt::SolidPattern);
    brush.setStyle(Qt::SolidPattern);

    initMap();
    createMenu();

    setMinimumSize(30, 30);    

    resize(pixmap.size());
}

void Teeth::createMenu()
{
    addDescriptionAction = new QAction( tr("Dodaj opis"), this);
    addDescriptionAction->setIcon(QIcon(":/icons/add_green.png"));

    setContextMenuPolicy(Qt::ActionsContextMenu);
    addAction(addDescriptionAction);

    connect(addDescriptionAction, SIGNAL(triggered()), this, SLOT(addDescriptionSlot()));
}

void Teeth::addDescriptionSlot()
{
    emit addDescriptionClicked(name, type);
}

void Teeth::initMap()
{
    whole = false;

    part[Left] = Qt::white;
    part[Right] = Qt::white;
    part[Center] = Qt::white;
    part[Down] = Qt::white;
    part[Up] = Qt::white;

}

void Teeth::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0, pixmap);
    painter.setWindow( -50, -50, 100, 100);

}

void Teeth::mousePressEvent(QMouseEvent *event)
{
    if( event->button() == Qt::LeftButton )
    {
        brush.setColor(color);

        QPainter painter;
        painter.begin(&pixmap);
        painter.setWindow(-50, -50, 100, 100);

        QPoint point = painter.deviceTransform().inverted().map(event->pos());


        if( partEnabled )
        {
            // jeśli wcześniej mieliśmy zaznaczony cały ząb
            // bez podziału na części to przy kliknięciu na ząb
            // z podziałem na częsci czyścimy cały ząb
            if(whole)
            {
                whole = false;
                clearAll();
            }


            if( up_p.containsPoint(point, Qt::OddEvenFill) )
            {
                add(Up, color);
            }
            else if( down_p.containsPoint( point, Qt::OddEvenFill ))
            {
                add(Down, color);
            }
            else if( left_p.containsPoint( point, Qt::OddEvenFill ))
            {
                add(Left, color);
            }
            else if( right_p.containsPoint( point, Qt::OddEvenFill ))
            {
                add(Right, color);
            }
            else if( center_p.containsPoint( point, Qt::OddEvenFill ))
            {
                add(Center, color);
            }

        }
        else
        {
            add(Up, color);
            add(Down, color);
            add(Left, color);
            add(Right, color);
            add(Center, color);

            whole = true;
        }

        painter.end();
        paintPart();
    }
}

void Teeth::resizeEvent(QResizeEvent *)
{
    int side = qMin(width(), height());

    pixmap = pixmap.scaled(side, side);
    paintPart();
}

QSize Teeth::sizeHint()
{
    return pixmap.size();
}

void Teeth::add(int p, QColor c)
{
    part[p] = c;

}

QString Teeth::save()
{

    QString ret = QString::number(whole) % ":" %
                  part[Left].name()   % ":" %
                  part[Right].name()  % ":" %
                  part[Center].name() % ":" %
                  part[Down].name()   % ":" %
                  part[Up].name();

    return ret;
}

int Teeth::read(const QString value)
{
    QStringList list = value.split(':');

    if( list.size() != 6 )
        return -1; // nieprawidłowe dane

    QString bool_whole  = list[0];
    whole = bool_whole.toInt();

    QColor left(list[1]);
    QColor right(list[2]);
    QColor center(list[3]);
    QColor down(list[4]);
    QColor up(list[5]);

    add(Left, left);
    add(Right, right);
    add(Center, center);
    add(Down, down);
    add(Up, up);

    paintPart();

    return 0;
}

int Teeth::clearAll()
{
    QColor white(Qt::white);

    part[Left] = white;
    part[Right] = white;
    part[Center] = white;
    part[Down] = white;
    part[Up] = white;

    return 0;
}

void Teeth::setName(int n, int t)
{
    name = n;
    type = t;
}


