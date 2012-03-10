#ifndef ADDDESCRIPTIONDIALOG_H
#define ADDDESCRIPTIONDIALOG_H

#include <QDialog>
#include <QStringList>

class QComboBox;
class QTextEdit;
class QLabel;
class QPushButton;

class AddDescriptionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddDescriptionDialog(QWidget *parent = 0);

    enum { SECOND, MILK };
    void setTeeth(int name, int type);
    void addToDatabase(QString, QString);

private slots:
    void teethTypeChanged(int type);

private:
    void createStringList();
    void createComboBox();
    void createTextEdit();
    void createButtons();
    void createLayout();

    QComboBox *teethTypeComboBox;
    QComboBox *teethNumberComboBox;

    QLabel *teethLabel;
    QLabel *descriptionLabel;

    QTextEdit *descriptionTextEdit;

    QStringList teethSecondList;
    QStringList teethMilkList;

    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // ADDDESCRIPTIONDIALOG_H
