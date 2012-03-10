/**
  * Teeth
  * Klasa abstrakcyjna reprezentująca 'ząb' na diagramie
  */

#ifndef TEETH_H
#define TEETH_H

#include <QWidget>
#include <QMap>
#include <QColor>

class Teeth : public QWidget
{
    Q_OBJECT
public:
    explicit Teeth(QWidget *parent = 0);

    enum { Left, Right, Up, Down, Center }; /*!< Stałe reprezentujące częsci zęba */
    static QColor color; /*!< Zmienna statyczna symbolizująca aktualnie wybrany kolor */
    static bool partEnabled; /*!< Zmienna określająca czy ząb w czasie kliknięcia ma być dzielony na cześci czy traktowany jako całosći */

    /**
      * Metoda zwraca idealny rozmiar widgetu
      * @param void
      * @return QSize
      */
    QSize sizeHint();

    /**
      * Metoda zwraca ciąg opisujący ząb.
      * Metoda pobiera nazwy kolorów kolejno
      * z części lewej, prawej, środkowej, dolnej, górnej
      * i łączy je w ciąg znaków oddzielając znakiem ':'
      * @param void
      * @return QString
      */
    QString save();

    /**
      * Metoda wczytuje wartości z ciągu.
      * Metoda rozbija ciąg nazw kolorów oddzielonych znakiem ':'
      * a następnie wczytuje je do mapy poprzez funcje add(int, QColor)
      * w kolejności lewy, prawy, środkowy, górny, dolny
      * @param QString
      * @return int
      */
    int read(const QString value);

    /**
      * Metoda 'zeruje' ząb(ustawia kolor na biały)
      * @param void
      * @return int
      */
    int clearAll();

    void setName(int name, int type);

public slots:
    void addDescriptionSlot();

signals:
    void addDescriptionClicked(int, int);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *);

    /**
      * Metoda wirtualna odpowiedzialna za rysowanie siatki zęba
      * @param void
      * @return void
      */
    virtual void paintGrid() = 0;

    /**
      * Metoda wirtualna 'kolorująca' poszczególne części zęba
      * @param void
      * @return void
      */
    virtual void paintPart() = 0;

    /**
      * Metoda wirtualna tworząca obszary zęba
      * @param void
      * @return void
      */
    virtual void createPolygons() = 0;

    /**
      * Metoda odpowiedzalna za wybranie 'koloru' danej cześci zęba
      * @param int, QColor
      * @return void
      */
    void add(int p, QColor);

    /**
      * Metoda wypełnia mape kolorem białym
      * @param void
      * @return void
      */
    void initMap();

    /**
      * Metoda tworzy menu kontekstowe widgetu
      * @param void
      * @return void
      */
    void createMenu();

    QBrush brush; /*!< Aktualnie wybrany kolor wypełnienia obszaru */
    QBrush white; /*!< Brush z ustawionym białym kolorem */ // nie pamiętam po co to

    QPixmap pixmap; /*!< Przechowuje aktualny wygląd widgetu */

    QPolygon up_p; /*!< Figura opisująca górny obszar zęba */
    QPolygon down_p; /*!< Figura opisująca dolny obszar zęba */
    QPolygon left_p; /*!< Figura opisująca lewy obszar zęba */
    QPolygon right_p; /*!< Figura opisująca prawy obszar zęba */
    QPolygon center_p; /*!< Figura opisująca środkowy obszar zęba */

    QMap<int, QColor> part; /*!< Mapa zawierająca obszar zęba i aktualnie przypisany mu kolor */

    bool whole; /*!< Czy zaznaczony cały ząb bez podziału na części */

    QAction *addDescriptionAction; /*!< Akcja 'dodaj opis' */

    int name;
    int type;
};


#endif // TEETH_H
