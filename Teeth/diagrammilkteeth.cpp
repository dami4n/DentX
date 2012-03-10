#include <QtGui>
#include "diagrammilkteeth.h"
#include "molar.h"
#include "incisor.h"

DiagramMilkTeeth::DiagramMilkTeeth(QWidget *parent) :
    QWidget(parent)
{
    createTeeth();
    createSpaceLine();
    createLabels();
    createLayout();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(upLayout);
    layout->addLayout(downLayout);

    setLayout(layout);

    resize(700 ,300);

}

void DiagramMilkTeeth::createTeeth()
{
  for(int i = 1; i <= 4; ++i )
  {
    int s = i * 10 + 40;

    teeth[s + 5] = new Molar;
    teeth[s + 4] = new Molar;
    teeth[s + 3] = new Incisor;
    teeth[s + 2] = new Incisor;
    teeth[s + 1] = new Incisor;

    teeth[s + 5]->setName(s + 5, 1);
    teeth[s + 4]->setName(s + 4, 1);
    teeth[s + 3]->setName(s + 3, 1);
    teeth[s + 2]->setName(s + 2, 1);
    teeth[s + 1]->setName(s + 1, 1);

  }
}

void DiagramMilkTeeth::createLabels()
{
    int s = 50;

    for(int j = 0; j < 4; ++j )
    {
        for(int i = 1; i <= 5; ++i)
        {
           labels[i + s] = new QLabel(QString::number(i + s));
        }
        s +=10;
    }
}

QString DiagramMilkTeeth::save()
{
    QString value[4];

    for(int i = 1; i <= 4; ++i )
    {
      int s = i * 10 + 40;

      value[i - 1] =  teeth[s + 5]->save() % "|" %
                      teeth[s + 4]->save() % "|" %
                      teeth[s + 3]->save() % "|" %
                      teeth[s + 2]->save() % "|" %
                      teeth[s + 1]->save();
    }

    QString ret = value[0] % "|" %
                  value[1] % "|" %
                  value[2] % "|" %
                  value[3];

    return ret;
}

void DiagramMilkTeeth::read(const QString &text)
{
    QStringList list = text.split("|");

    int num = 0;
    for(int i = 1; i <= 4; ++i )
    {
      int s = i * 10 + 40;

      teeth[s + 5]->read( list[num++] );
      teeth[s + 4]->read( list[num++] );
      teeth[s + 3]->read( list[num++] );
      teeth[s + 2]->read( list[num++] );
      teeth[s + 1]->read( list[num++] );

    }

}

void DiagramMilkTeeth::createSpaceLine()
{

    lineUp = new QFrame;
    lineUp->setLineWidth(2);
    lineUp->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lineUp->setFrameShape(QFrame::VLine);

    lineDown = new QFrame;
    lineDown->setLineWidth(2);
    lineDown->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    lineDown->setFrameShape(QFrame::VLine);

}


void DiagramMilkTeeth::createLayout()
{

    // up
      upLayout = new QGridLayout;
      upLayout->setAlignment(Qt::AlignTop);

      upLayout->addWidget(labels[55], 0, 1, Qt::AlignCenter);
      upLayout->addWidget(labels[54], 0, 2, Qt::AlignCenter);
      upLayout->addWidget(labels[53], 0, 3, Qt::AlignCenter);
      upLayout->addWidget(labels[52], 0, 4, Qt::AlignCenter);
      upLayout->addWidget(labels[51], 0, 5, Qt::AlignCenter);

      upLayout->addWidget(teeth[55], 1, 1);
      upLayout->addWidget(teeth[54], 1, 2);
      upLayout->addWidget(teeth[53], 1, 3);
      upLayout->addWidget(teeth[52], 1, 4);
      upLayout->addWidget(teeth[51], 1, 5);

      upLayout->addWidget(lineUp, 1, 9, Qt::AlignCenter);

      upLayout->addWidget(labels[61], 0, 10, Qt::AlignCenter);
      upLayout->addWidget(labels[62], 0, 11, Qt::AlignCenter);
      upLayout->addWidget(labels[63], 0, 12, Qt::AlignCenter);
      upLayout->addWidget(labels[64], 0, 13, Qt::AlignCenter);
      upLayout->addWidget(labels[65], 0, 14, Qt::AlignCenter);

      upLayout->addWidget(teeth[61], 1, 10);
      upLayout->addWidget(teeth[62], 1, 11);
      upLayout->addWidget(teeth[63], 1, 12);
      upLayout->addWidget(teeth[64], 1, 13);
      upLayout->addWidget(teeth[65], 1, 14);

 // down

      downLayout = new QGridLayout;
      downLayout->setAlignment(Qt::AlignTop);

      downLayout->addWidget(labels[75], 1, 1, Qt::AlignCenter);
      downLayout->addWidget(labels[74], 1, 2, Qt::AlignCenter);
      downLayout->addWidget(labels[73], 1, 3, Qt::AlignCenter);
      downLayout->addWidget(labels[72], 1, 4, Qt::AlignCenter);
      downLayout->addWidget(labels[71], 1, 5, Qt::AlignCenter);

      downLayout->addWidget(teeth[75], 0, 1);
      downLayout->addWidget(teeth[74], 0, 2);
      downLayout->addWidget(teeth[73], 0, 3);
      downLayout->addWidget(teeth[72], 0, 4);
      downLayout->addWidget(teeth[71], 0, 5);

      downLayout->addWidget(lineDown, 0, 9, Qt::AlignCenter);

      downLayout->addWidget(labels[81], 1, 10, Qt::AlignCenter);
      downLayout->addWidget(labels[82], 1, 11, Qt::AlignCenter);
      downLayout->addWidget(labels[83], 1, 12, Qt::AlignCenter);
      downLayout->addWidget(labels[84], 1, 13, Qt::AlignCenter);
      downLayout->addWidget(labels[85], 1, 14, Qt::AlignCenter);

      downLayout->addWidget(teeth[81], 0, 10);
      downLayout->addWidget(teeth[82], 0, 11);
      downLayout->addWidget(teeth[83], 0, 12);
      downLayout->addWidget(teeth[84], 0, 13);
      downLayout->addWidget(teeth[85], 0, 14);

}







