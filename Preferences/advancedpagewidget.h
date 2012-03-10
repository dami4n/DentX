#ifndef ADVANCEDPAGEWIDGET_H
#define ADVANCEDPAGEWIDGET_H

#include <QWidget>
#include <QCheckBox>

class Preferences;

class AdvancedPageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AdvancedPageWidget(QWidget *parent = 0);

    bool getDynamicSearch() { return dynamicSearchCheckBox->isChecked(); }
    void readSettings();

private:
    void createGui();
    void createLayout();

    QCheckBox *dynamicSearchCheckBox;

    Preferences *preferences;

};

#endif // ADVANCEDPAGEWIDGET_H
