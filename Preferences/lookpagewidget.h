#ifndef LOOKPAGEWIDGET_H
#define LOOKPAGEWIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QComboBox>

class Preferences;

class LookPageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LookPageWidget(QWidget *parent = 0);

    bool getMovableToolBar() { return movableToolBarCheckBox->isChecked(); }
    QString getPosition() { return positionComboBox->currentText(); }

    void readSettings();

private:
    void createGui();
    void createLayout();

    QCheckBox *movableToolBarCheckBox;
    QComboBox *positionComboBox;

    Preferences *preferences;


};

#endif // LOOKPAGEWIDGET_H
