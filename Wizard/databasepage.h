#ifndef DATABASEPAGE_H
#define DATABASEPAGE_H

#include <QWizardPage>

class QComboBox;
class QLineEdit;
class QLabel;
class QPushButton;
class QFormLayout;

class DatabasePage : public QWizardPage
{
    Q_OBJECT
public:
    explicit DatabasePage(QWidget *parent = 0);

private slots:
    void showSqlite(bool value);
    void showMySql(bool value);
    void databaseComboboxChanged(int value);


private:
    void createGui();
    void createLayout();

    QLabel *databaseTypeLabel;
    QLabel *pathLabel;
    QLabel *hostLabel;
    QLabel *databaseNameLabel;
    QLabel *userNameLabel;
    QLabel *passwordLabel;

    QFormLayout *formLayout;

    QComboBox *databaseTypeComboBox;

    QLineEdit *hostnameLineEdit;
    QLineEdit *databaseNameLineEdit;
    QLineEdit *userNameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *pathLineEdit;
    QPushButton *getPathButton;

};

#endif // DATABASEPAGE_H
