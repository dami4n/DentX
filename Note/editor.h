/**
  * Editor
  * Prosty edytor tekstowy
  */

#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

class QVBoxLayout;
class QFontComboBox;
class QComboBox;
class QPushButton;
class QTextEdit;
class QLabel;

class Editor : public QWidget
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = 0);

    /**
      * Metoda zwraca teskt z noteTextEdit
      * @param void
      * @return QString
      */
    QString getText();

    /**
      * Metoda zwraca html z noteTextEdit
      * @param void
      * @return QString
      */
    QString getHtml();

    /**
      * Metoda ustawia wartość noteTextEdit
      * @param QString
      * @return void
      */
    void setText(QString text);

    /**
      * Metoda ustawia czy widget ma być edytowalny
      * @param bool
      * @return void
      */
    void setEditable(bool value);

public slots:
    /**
      * Slot wywoływany po zmianie czcionki
      * @param void
      * @return void
      */
    void fontChanged();

    /**
      * Slot wywoływany po naciśnięciu przycisku 'T'(zmiana koloru)
      * @param void
      * @return void
      */
    void getColor();

    /**
      * Slot wywoływany po każdej zmianie wartości noteTextEdit
      * @param void
      * @return void
      */
    void noteTextChanged();

private:
    /**
      * Metoda odpowiedzialna za stworzenie GUI edutora.
      * @param void
      * @return void
      */
    void createEditor();

    /**
      *Tworzy layout widgetu
      * @param void
      * @return void
      */
    void createLayout();

    QTextEdit *noteTextEdit; /*!< Tekst notatki */
    QFontComboBox *fontComboBox; /*!< Dostępne czcionki */
    QComboBox *fontSizeComboBox; /*!< Rozmiar czcionki */
    QPushButton *BPushButton; /*!< Pogrubienie */
    QPushButton *UPushButton; /*!< Podkreślenie */
    QPushButton *IPushButton; /*!< Kursywa */
    QPushButton *colorTextPushButton; /*!< Kolor czcionki */
    QFont currentFont; /*!< Aktualnie wybrana czcionka */
    QColor currentFontColor; /*!< Aktualnie wybrany kolor */

};

#endif // EDITOR_H
