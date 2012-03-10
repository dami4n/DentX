#ifndef TIMESHEET_H
#define TIMESHEET_H

#include <QWidget>
#include <QList>
#include <QMap>
#include <QDateTime>
#include <QDate>

class QTableWidget;
class QStringList;
class QTableWidgetItem;
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QToolButton;
class QCalendarWidget;
class QFrame;

class Timesheet : public QWidget
{
    Q_OBJECT
public:
    explicit Timesheet(QWidget *parent = 0);

   /**
     * Metoda ustawia kolor dla pól specjalnych tabeli
     * @param QColor
     * @return void
     */
    void setSpecialCellColor(QColor newColor);

   /**
     * Metoda włącza/wyłącza selekcje w tabeli
     * @param bool
     * @return void
     */
    void selectionEnabled(bool value);

   /**
     * Metoda ustawia kolor selekcji
     * @param QColor
     * @return void
     */
    void setSelectionColor(QColor color);

   /**
     * Metoda dodaje nowy typ wizyty
     * @param QString, QColor
     * @return void
     */
    void addVisitType(QString type, QColor color);


    /**
     * Metoda zapisuje wizyty w bazie danych
     * @param void
     * @return void
     */
    void save();

    /**
     * Metoda wczytuje wizyty z bazy danych
     * @param void
     * @return void
     */
    void load();

private slots:
    /**
      * Slot wywoływany po zmianie typu wizyty
      * @param QString
      * @return void
      */
    void visitTypeChanged(QString name);

    /**
      * Slot wywoływany po kliknięciu na 'nowa wizyta'
      * @param void
      * @return void
      */
    void newVisit();

    /**
      * Slot aktywuje/dezaktywuje button nowej wizyty
      * @param void
      * @return void
      */
    void lineEditChanged();

    /**
      * Slot wywoływany po kliknięciu 'ok', po dodadniu wizyty
      * @param void
      * @return void
      */
    void okClicked();

    /**
      * Slot przesuwający grafik na poprzedni tydzień
      * @param void
      * @return void
      */
    void leftClicked();

    /**
      * Slot przesuwający grafik na następny tydzień
      * @param void
      * @return void
      */
    void rightClicked();

    /**
      * Slot ustawia daty w grafiku
      * @param void
      * @return void
      */
    void dateSelectionChanged();

    /**
      * Slot pokazuje/ukrywa kalendarz
      * @param void
      * @return void
      */
    void selectDateClicked();


    // chyba się nie przyda
    void setButtonDate(QDateTime time);

private:
    void createColorComboBox();
    void createHorizontalLabels();
    void createVerticalLabels(int start, int end);
    void createTable();
    void createLayout();
    void createVisitTypeMap();
    void createSearchPatient();
    void createToolButton();
    void createDateLabel();
    void createCalendar();
    void createLine();
    void setLabels(QDate date);
    void saveDay(QDateTime day);
    QString saveDayToString(QString day);

    QDate getFirstDayOfWeek(QDate day);


    QList<QTableWidgetItem*> dayList;
    QMap<QString, QColor> visitTypeMap;

    QStringList dayStringList;
    QTableWidget *tableWidget;
    QColor color;
    QColor selectionColor;
    QComboBox *visitTypeComboBox;
    QLineEdit *searchPatientLineEdit;
    QLabel *visitTypeLabel;
    QLabel *searchPatientLabel;
    QPushButton *newVisitButton;

    QPushButton *calendarButton;
    QToolButton *leftToolButton;
    QToolButton *rightToolButton;

    QCalendarWidget *pushCalendar;

    QFrame *lineUp;
    QFrame *lineDown;

};

#endif // TIMESHEET_H
