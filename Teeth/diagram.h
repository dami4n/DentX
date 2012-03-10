/**
  * Diagram
  * Klasa tworząca widget zawierający diargam zębowy
  */

#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QWidget>
#include <QMap>

class Teeth;
class QHBoxLayout;
class QGridLayout;
class QFrame;
class QLabel;
class QPixmap;

class Diagram : public QWidget
{
    Q_OBJECT
public:
    explicit Diagram(QWidget *parent = 0);

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

private slots:

private:
    /**
      * Metoda tworząca zęby
      * @param void
      * @return void
      */
    void createTeeth();

    /**
      * Metoda tworząca główny layout widgetu
      * @param void
      * @return void
      */
    void createLayout();

    /**
      * Metoda tworzy QLabel z numerem zęba, wyświetlane nad/pod zebem
      * @param void
      * @return void
      */
    void createLabels();

    /**
      * Metoda tworząca 'odstępy' pomiędzy lewymi a prawymi zębami
      * @param void
      * @return void
      */
    void createSpaceLine();

    QMap<int, Teeth*> teeth; /*!< Mapa zawierająca numer zęba i odpowiadający mu ząb */
    QMap<int, QLabel*> labels; /*!< Mapa zawierająca numer zęba i QLabel z numerem zęba */

    QGridLayout *upLayout; /*!< Layout zawierający uzębienie górne */
    QGridLayout *downLayout; /*!< Layout zawierający uzębienie dolne */

    QPixmap *pixmap; /*!< Pixmapa dla QLabel, mała kreseczka oddzielająca zęby */
    QFrame *lineUp; /*!< QFrame oddzielające górne uzębienie */
    QFrame *lineDown; /*!< QFrame oddzielające dolne uzębienie */

};

#endif // DIAGRAM_H
