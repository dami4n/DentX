#ifndef DIAGRAMMILKTEETH_H
#define DIAGRAMMILKTEETH_H

#include <QWidget>
#include <QMap>

class Teeth;
class QHBoxLayout;
class QGridLayout;
class QLabel;
class QPixmap;
class QFrame;

class DiagramMilkTeeth : public QWidget
{
    Q_OBJECT
public:
    explicit DiagramMilkTeeth(QWidget *parent = 0);

    /**
      * Metoda zapisuje stan diagramu do QString.
      * Metoda wywołuje 'save' dla każdego zęba a nastąpnie łączy otrzymane
      * ciągi(oddzielając je znakiem '|') w jeden.
      * @param void
      * @return QString
      */
    QString save();

    /**
      * Metoda wczytuje stan diagramy z zadanego ciągu.
      * @param QString
      * @return void
      */
    void read(const QString &text);

private:
    void createTeeth();
    void createLayout();
    void createLabels();
    void createSpaceLine();

    QMap<int, Teeth*> teeth;
    QMap<int, QLabel*> labels;

    QGridLayout *upLayout;
    QGridLayout *downLayout;

    QPixmap *pixmap;
    QFrame *lineUp;
    QFrame *lineDown;

};

#endif // DIAGRAMMILKTEETH_H
