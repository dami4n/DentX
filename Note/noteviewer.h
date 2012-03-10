#ifndef NOTEVIEWER_H
#define NOTEVIEWER_H

#include <QWidget>
#include <QModelIndex>

class QTableView;
class QSqlQueryModel;
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class Preferences;

// TODO usuwanie notatek

class NoteViewer : public QWidget
{
    Q_OBJECT
public:
    explicit NoteViewer(QWidget *parent = 0);

    enum { ALL, TODAY, LASTWEEK, LASTMONTH };

public slots:
    void changed();
    void search();

private slots:
    void showNote(QModelIndex);
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
    QComboBox *showNoteComboBox;

    QPushButton *searchButton;

    Preferences *preferences;
};

#endif // NOTEVIEWER_H
