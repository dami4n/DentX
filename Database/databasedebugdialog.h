/**
  * DatabaseDebugDialog
  * Klasa wyświetlająca dialog odpowiedzialny za obsługę trybu debug bazy danych
  */

#ifndef DATABASEDEBUGDIALOG_H
#define DATABASEDEBUGDIALOG_H

#include <QDialog>

class QPushButton;
class QLineEdit;
class QTextEdit;
class QVBoxLayout;

class DatabaseDebugDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DatabaseDebugDialog(QWidget *parent = 0);

private:
    /**
      * Metoda tworzy GUI dialogu
      * @param void
      * @return void
      */
    void createGUI();

    /**
      * Metoda wykonująca zapytanie
      * @param QString
      * @return void
      */
    void query(const QString queryString);

    QPushButton *queryButton; /*!< Przycisk 'query' */
    QLineEdit *queryLineEdit; /*!< Zapytanie */
    QTextEdit *queryResultTextEdit; /*!< Wynik zapytania */
    QVBoxLayout *mainLayout; /*!< Layout główny dialogu */

private slots:
    /**
      * Prywatny slot wywoływany po kliknięciu na przycisk 'query'
      * @param void
      * @return void
      */
    void queryClicked();

};

#endif // DATABASEDEBUGDIALOG_H

