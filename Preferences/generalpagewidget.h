#ifndef GENERALPAGEWIDGET_H
#define GENERALPAGEWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>

class QLabel;

class Preferences;

class GeneralPageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GeneralPageWidget(QWidget *parent = 0);

    int getLanguage();
    bool getSavePosition() { return savePositionRadioButton->isChecked(); }
    bool getAlwaysMax() { return alwaysMaxRadioButton->isChecked(); }
    bool getCloseCheck() { return closeCheckBox->isChecked(); }

    void readSettings();

private:
    void createGui();
    void createLayout();

    QComboBox *languageComboBox;
    QRadioButton *savePositionRadioButton;
    QRadioButton *alwaysMaxRadioButton;
    QCheckBox *closeCheckBox;

    Preferences *preferences;

};

#endif // GENERALPAGEWIDGET_H
