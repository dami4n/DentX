/**
  * CardfileTable
  * Klasa reprezentująca tabele wyświetlającą pacjentów
  */

#ifndef CARDFILETABLE_H
#define CARDFILETABLE_H

#include <QTableView>

class CardfileTable : public QTableView
{
    Q_OBJECT
public:
    explicit CardfileTable(QWidget *parent = 0);

    /**
      * Metoda ukrywa/pokazuje pionowy header tabeli
      * @param bool
      * @return void
      */
    void hideVerticalHeader(bool);

    /**
      * Metoda pozwala ustawić kolor rekordów w tabeli
      * @param QColor, QColor
      * @return void
      */
    void setTableColor(QColor, QColor);

    /**
      * Metoda pozwala ustawić kolor rekordów w tabeli
      * @param QColor
      * @return void
      */
    void setTableColor(QColor);

private:
    /**
      * Metoda ustawia parametry tabeli
      * @param void
      * @return void
      */
    void setTableOptions();


};

#endif // CARDFILETABLE_H
