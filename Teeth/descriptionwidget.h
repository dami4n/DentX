#ifndef DESCRIPTIONWIDGET_H
#define DESCRIPTIONWIDGET_H

#include <QWidget>

class QTableView;
class QToolButton;
class QSqlQueryModel;

class DescriptionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DescriptionWidget(QWidget *parent = 0);

private slots:
    void addDescriptionClicked();

private:
    void createGui();
    void createTable();
    void updateColumnName();
    void createLayout();

    QTableView *tableView;
    QSqlQueryModel *model;

    QToolButton *addToolButton;
    QToolButton *removeToolButton;

};

#endif // DESCRIPTIONWIDGET_H
