/**
  * ColorButtons
  * Widget zawierający kolorowe przyciski odpowiedzialne za wybranie koloru
  */

#ifndef COLORBUTTONS_H
#define COLORBUTTONS_H

#include <QWidget>
#include <QMap>
#include <QColor>

class QPushButton;
class QVBoxLayout;
class QSignalMapper;

class ColorButtons : public QWidget
{
    Q_OBJECT
public:
    explicit ColorButtons(QWidget *parent = 0);

signals:
    /**
      * Sygnał emitowany w przypadku zmiany koloru(poprzez kliknięcie przycisku)
      * @param QColor, bool
      * @return void
      */
    void colorChanged(QColor color, bool part);

private slots:
    /**
      * Slot wywoływany przy kliknięciu przycisku, emitujący sygnał colorChanged()
      * @param QString
      * @return void
      */
    void buttonClicked(const QString &text);

private:
    /**
      * Metoda tworzy przyciski odpowiadające za zmiane 'koloru'
      * @param void
      * @return void
      */
    void createColorButtons();

    /**
      * Metoda tworząca główny layout widgetu
      * @param void
      * @return void
      */
    void createLayout();

    /**
      * Metoda łącząca sygnały z przycisków z QSignalMapper
      * @param void
      * @return void
      */
    void connectButtons();

    /**
      * Metoda tworzy mape colorMap, zawierającą nazwe przycisku i odpowiadający mu kolor
      * @param void
      * @return void
      */
    void createButtonsMap();

    QVBoxLayout *mainLayout; /*!< Layout główny widgetu */

    QSignalMapper *signalMapper; /*!< SignalMapper łączący przyciski odpowiedzialne za zmiane 'koloru' */

    QMap<QString, QColor> colorMap; /*!< Mapa przechowująca nazwę przycisku i odpowiadający mu kolor */

    QPushButton *clearButton; /*!< Wyczyść */
    QPushButton *clearAllButton; /*!< Wyczyść cały ząb */
    QPushButton *cariesButton; /*!< Próchnica */
    QPushButton *fillingButton; /*!< Wypelnienie */
    QPushButton *rootButton; /*!< Korzeń */
    QPushButton *crownButton; /*!< Korona */
    QPushButton *toExtractionButton; /*!< Do ekstrakcji */
    QPushButton *calculusButton; /*!< Kamień nazębny */
    QPushButton *bridgeButton; /*!< Most */
    QPushButton *emptyButton; /*!< Brak zęba */

};

#endif // COLORBUTTONS_H
