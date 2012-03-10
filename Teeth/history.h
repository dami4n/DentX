/**
  * History
  * Widget odpowiedzialny za wyświetlanie historii wizyt pacjenta
  */

#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QMap>
#include <QStringList>
#include <QDateTime>
#include <QModelIndex>


class QListView;
class QVBoxLayout;
class QStringListModel;


class History : public QWidget
{
    Q_OBJECT
public:
    explicit History(QWidget *parent = 0);

    /**
      * Metoda dodaje nową wizytę
      * @param int, QString, QString
      * @return int
      */
    int addNewAppointment(int id, QString milk, QString second);

    /**
      * Metoda tworzy model dla ListView
      * @param QString
      * @return void
      */
    void createModel(const int newId);

    /**
      * Metoda zwraca zapisany diagram zębowy(mleczne) dla podanej daty
      * @param QString
      * @return QString
      */
    QString getMilk(const QString data) const;


    /**
      * Metoda zwraca zapisany diagram zębowy(stałe) dla podanej daty
      * @param QString
      * @return QString
      */
    QString getSecond(const QString data) const;

    /**
      * Metoda zapisująca wizyte do bazy danych
      * @param int, QString, QString, QString, QString,
      * @return bool
      */
    bool save(int, QString, QString, QString, QString);

    /**
      * Metoda tworzy nową wizyte w bazie danych
      * @param QString, QString
      * @return bool
      */
    bool createNewAppintment(int, QString, QString);

    /**
      * Metoda zwraca ilość elementów w hisotrii
      * @param void
      * @return int
      */
    int sizeHistory() const;

    /**
      * Metoda zwraca ID wybranej aktualnie wizyty
      * @param void
      * @return QString
      */

    QString getId();

    /**
      * Metoda zwraca plan wybranej aktualnie wizyty
      * @param void
      * @return QString
      */

    QString getPlan();

    /**
      * Metoda zwraca rozpoznanie wybranej aktualnie wizyty
      * @param void
      * @return QString
      */

    QString getDiagnosis();

public slots:
    /**
      * Slot usuwający zaznaczoną wizyte
      * @param void
      * @return void
      */
    void deleteSelected();

private slots:
    /**
      * Slot wywoływany przy kliknięciu na wizyte w QListView
      * Emituje sygnał z datą wizyty która została kliknięta
      * @param QModelIndex
      * @return void
      */
    void clicked(QModelIndex);

signals:
    /**
      * Sygnał emitowany przy kliknięciu na wizyte w QListView
      * @param QString
      * @return void
      */
    void clicked(QString);

private:
    /**
      * Tworzy widget ListView wyświetlający historie wizyt
      * @param void
      * @return void
      */
    void createListView();

    /**
      * Metoda tworzy główny layout widgetu
      * @param void
      * @return void
      */
    void createMainLayout();

    /**
      * Metoda wczytuje wizyty do QListView
      * @param void
      * @return void
      */
    void createStringList();

    int id;

    QStringList stringList; /*!< Zawiera liste z datami wizyt */

    QMap<QString, QString> secondTeethMap; /*!< Zawiera diagramy zębowe(stałe) dla wizyt pacjenta */
    QMap<QString, QString> milkTeethMap; /*!< Zawiera diagramy zębowe(mleczne) dla wizyt pacjenta */
    QList<QDateTime> dateList; /*!< Lista zawierająca daty wizyt */

    QListView *listView; /*!< Wyświetla historie wizyt pacjenta */
    QVBoxLayout *mainLayout; /*!< Layout główny widgetu */
    QStringListModel *model; /*!< Model dla ListView */

};

#endif // HISTORY_H
