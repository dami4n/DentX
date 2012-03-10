#include <QtGui>
#include <QStringBuilder>
#include "molar.h"
#include "diagram.h"
#include "incisor.h"

Diagram::Diagram(QWidget *parent) :
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

void Diagram::read(const QString &text)
{
    QStringList list = text.split("|");

    int num = 0;
    for(int i = 1; i <= 4; ++i )
    {
      int s = i * 10;

      teeth[s + 8]->read( list[num++] );
      teeth[s + 7]->read( list[num++] );
      teeth[s + 6]->read( list[num++] );
      teeth[s + 5]->read( list[num++] );
      teeth[s + 4]->read( list[num++] );
      teeth[s + 3]->read( list[num++] );
      teeth[s + 2]->read( list[num++] );
      teeth[s + 1]->read( list[num++] );
    }
}

QString Diagram::save()
{
    QString value[4];

    for(int i = 1; i <= 4; ++i )
    {
      int s = i * 10;

      value[i - 1] =  teeth[s + 8]->save() % "|" %
                      teeth[s + 7]->save() % "|" %
                      teeth[s + 6]->save() % "|" %
                      teeth[s + 5]->save() % "|" %
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

void Diagram::createTeeth()
{
  for(int i = 1; i <= 4; ++i )
  {
    int s = i * 10;

    teeth[s + 8] = new Molar;
    teeth[s + 7] = new Molar;
    teeth[s + 6] = new Molar;
    teeth[s + 5] = new Molar;
    teeth[s + 4] = new Molar;
    teeth[s + 3] = new Incisor;
    teeth[s + 2] = new Incisor;
    teeth[s + 1] = new Incisor;

    teeth[s + 8]->setName(s + 8, 0);
    teeth[s + 7]->setName(s + 7, 0);
    teeth[s + 6]->setName(s + 6, 0);
    teeth[s + 5]->setName(s + 5, 0);
    teeth[s + 4]->setName(s + 4, 0);
    teeth[s + 3]->setName(s + 3, 0);
    teeth[s + 2]->setName(s + 2, 0);
    teeth[s + 1]->setName(s + 1, 0);
  }
}

void Diagram::createLabels()
{
    int s = 10;

    for(int j = 0; j < 4; ++j )
    {
        for(int i = 1; i <= 8; ++i)
        {
           labels[i + s] = new QLabel(QString::number(i + s));
        }
        s +=10;
    }
}

void Diagram::createSpaceLine()
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


void Diagram::createLayout()
{

    // up
      upLayout = new QGridLayout;
      upLayout->setAlignment(Qt::AlignTop);

      upLayout->addWidget(labels[18], 0, 1, Qt::AlignCenter);
      upLayout->addWidget(labels[17], 0, 2, Qt::AlignCenter);
      upLayout->addWidget(labels[16], 0, 3, Qt::AlignCenter);
      upLayout->addWidget(labels[15], 0, 4, Qt::AlignCenter);
      upLayout->addWidget(labels[14], 0, 5, Qt::AlignCenter);
      upLayout->addWidget(labels[13], 0, 6, Qt::AlignCenter);
      upLayout->addWidget(labels[12], 0, 7, Qt::AlignCenter);
      upLayout->addWidget(labels[11], 0, 8, Qt::AlignCenter);

      upLayout->addWidget(teeth[18], 1, 1);
      upLayout->addWidget(teeth[17], 1, 2);
      upLayout->addWidget(teeth[16], 1, 3);
      upLayout->addWidget(teeth[15], 1, 4);
      upLayout->addWidget(teeth[14], 1, 5);
      upLayout->addWidget(teeth[13], 1, 6);
      upLayout->addWidget(teeth[12], 1, 7);
      upLayout->addWidget(teeth[11], 1, 8);

      upLayout->addWidget(lineUp, 1, 9, Qt::AlignCenter);

      upLayout->addWidget(labels[21], 0, 10, Qt::AlignCenter);
      upLayout->addWidget(labels[22], 0, 11, Qt::AlignCenter);
      upLayout->addWidget(labels[23], 0, 12, Qt::AlignCenter);
      upLayout->addWidget(labels[24], 0, 13, Qt::AlignCenter);
      upLayout->addWidget(labels[25], 0, 14, Qt::AlignCenter);
      upLayout->addWidget(labels[26], 0, 15, Qt::AlignCenter);
      upLayout->addWidget(labels[27], 0, 16, Qt::AlignCenter);
      upLayout->addWidget(labels[28], 0, 17, Qt::AlignCenter);

      upLayout->addWidget(teeth[21], 1, 10);
      upLayout->addWidget(teeth[22], 1, 11);
      upLayout->addWidget(teeth[23], 1, 12);
      upLayout->addWidget(teeth[24], 1, 13);
      upLayout->addWidget(teeth[25], 1, 14);
      upLayout->addWidget(teeth[26], 1, 15);
      upLayout->addWidget(teeth[27], 1, 16);
      upLayout->addWidget(teeth[28], 1, 17);

 // down

      downLayout = new QGridLayout;
      downLayout->setAlignment(Qt::AlignTop);

      downLayout->addWidget(labels[48], 1, 1, Qt::AlignCenter);
      downLayout->addWidget(labels[47], 1, 2, Qt::AlignCenter);
      downLayout->addWidget(labels[46], 1, 3, Qt::AlignCenter);
      downLayout->addWidget(labels[45], 1, 4, Qt::AlignCenter);
      downLayout->addWidget(labels[44], 1, 5, Qt::AlignCenter);
      downLayout->addWidget(labels[43], 1, 6, Qt::AlignCenter);
      downLayout->addWidget(labels[42], 1, 7, Qt::AlignCenter);
      downLayout->addWidget(labels[41], 1, 8, Qt::AlignCenter);

      downLayout->addWidget(teeth[48], 0, 1);
      downLayout->addWidget(teeth[47], 0, 2);
      downLayout->addWidget(teeth[46], 0, 3);
      downLayout->addWidget(teeth[45], 0, 4);
      downLayout->addWidget(teeth[44], 0, 5);
      downLayout->addWidget(teeth[43], 0, 6);
      downLayout->addWidget(teeth[42], 0, 7);
      downLayout->addWidget(teeth[41], 0, 8);

      downLayout->addWidget(lineDown, 0, 9, Qt::AlignCenter);

      downLayout->addWidget(labels[31], 1, 10, Qt::AlignCenter);
      downLayout->addWidget(labels[32], 1, 11, Qt::AlignCenter);
      downLayout->addWidget(labels[33], 1, 12, Qt::AlignCenter);
      downLayout->addWidget(labels[34], 1, 13, Qt::AlignCenter);
      downLayout->addWidget(labels[35], 1, 14, Qt::AlignCenter);
      downLayout->addWidget(labels[36], 1, 15, Qt::AlignCenter);
      downLayout->addWidget(labels[37], 1, 16, Qt::AlignCenter);
      downLayout->addWidget(labels[38], 1, 17, Qt::AlignCenter);

      downLayout->addWidget(teeth[31], 0, 10);
      downLayout->addWidget(teeth[32], 0, 11);
      downLayout->addWidget(teeth[33], 0, 12);
      downLayout->addWidget(teeth[34], 0, 13);
      downLayout->addWidget(teeth[35], 0, 14);
      downLayout->addWidget(teeth[36], 0, 15);
      downLayout->addWidget(teeth[37], 0, 16);
      downLayout->addWidget(teeth[38], 0, 17);
}


