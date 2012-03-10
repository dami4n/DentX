#ifndef DATABASEPAGEWIDGET_H
#define DATABASEPAGEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

class QLabel;
class Preferences;

class DatabasePageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DatabasePageWidget(QWidget *parent = 0);

    int getDatabaseType();
    QString getHostname() { return hostnameLineEdit->text(); }
    QString getDatabaseName() { return databaseNameLineEdit->text(); }
    QString getUserName() { return userNameLineEdit->text(); }
    QString getPasswordName() { return passwordLineEdit->text(); }

    void readSettings();


private slots:
    void setSqlite(bool value);
    void databaseComboboxChanged(int value);

private:
    void createGui();
    void createLayout();

    QLabel *databaseTypeLabel;

    QComboBox *databaseTypeComboBox;

    QLineEdit *hostnameLineEdit;
    QLineEdit *databaseNameLineEdit;
    QLineEdit *userNameLineEdit;
    QLineEdit *passwordLineEdit;

    Preferences *preferences;

};

#endif // DATABASEPAGEWIDGET_H
