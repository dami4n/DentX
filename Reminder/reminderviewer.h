#ifndef REMINDERVIEWER_H
#define REMINDERVIEWER_H

#include <QWidget>
#include <QModelIndex>

class QTableView;
class QSqlQueryModel;
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class Preferences;

class ReminderViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ReminderViewer(QWidget *parent = 0);

    enum {NOW, TODAY, WEEK, MONTH, YEAR, ALL };

public slots:
    void changed();
    void search();

private slots:
    void showReminder(QModelIndex);
    void setTime(int time);

private:
    void createTableView();
    void createLayout();
    void updateColumnsName();
    void createSearchGUI();
    void setFilter(QString);

    QTableView *tableView;
    QSqlQueryModel *model;

    QString dateFilterString;

    QLabel *showLabel;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QComboBox *showReminderComboBox;

    QPushButton *searchButton;

      Preferences *preferences;

};

#endif // REMINDERVIEWER_H
