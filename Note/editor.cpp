#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QFontComboBox>
#include <QComboBox>
#include <QFontDatabase>
#include <QString>
#include <QStringBuilder>
#include <QPushButton>
#include <QTextEdit>
#include <QColorDialog>
#include <QFont>
#include <QColor>

#include "editor.h"

Editor::Editor(QWidget *parent) :
    QWidget(parent)
{
    createEditor();
    createLayout();
}

void Editor::createLayout()
{
    QHBoxLayout *fontSettingLayout = new QHBoxLayout;
    fontSettingLayout->addWidget(fontComboBox);
    fontSettingLayout->addWidget(fontSizeComboBox);
    fontSettingLayout->addWidget(BPushButton);
    fontSettingLayout->addWidget(UPushButton);
    fontSettingLayout->addWidget(IPushButton);
    fontSettingLayout->addWidget(colorTextPushButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(fontSettingLayout);
    mainLayout->addWidget(noteTextEdit);
    mainLayout->setMargin(0);
    setLayout(mainLayout);
}

void Editor::createEditor()
{
    currentFontColor = Qt::black;

    fontComboBox = new QFontComboBox;
    fontComboBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    fontSizeComboBox = new QComboBox;
    fontSizeComboBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QFontDatabase fontDatabase;
    foreach(int size, fontDatabase.standardSizes())
        fontSizeComboBox->addItem(QString::number(size));

    fontSizeComboBox->setCurrentIndex(8);

    BPushButton = new QPushButton( tr("B") );
    UPushButton = new QPushButton( tr("U") );
    IPushButton = new QPushButton( tr("I") );

    // standardowe buttony były za duże
    int textWidth = BPushButton->fontMetrics().boundingRect(BPushButton->text()).width();
    BPushButton->setMinimumWidth(textWidth + 25);
    UPushButton->setMinimumWidth(textWidth + 25);
    IPushButton->setMinimumWidth(textWidth + 25);

    BPushButton->setCheckable(true);
    UPushButton->setCheckable(true);
    IPushButton->setCheckable(true);

    BPushButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    UPushButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    IPushButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    colorTextPushButton = new QPushButton( tr("T") );
    colorTextPushButton->setMinimumWidth( textWidth + 25);
    connect(colorTextPushButton, SIGNAL(clicked()), this, SLOT(getColor()));

    noteTextEdit = new QTextEdit;
    noteTextEdit->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    noteTextEdit->setFocus();

    connect(fontComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(fontChanged()));
    connect(fontSizeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(fontChanged()));
    connect(BPushButton, SIGNAL(clicked()), this, SLOT(fontChanged()));
    connect(UPushButton, SIGNAL(clicked()), this, SLOT(fontChanged()));
    connect(IPushButton, SIGNAL(clicked()), this, SLOT(fontChanged()));
    connect(noteTextEdit, SIGNAL(textChanged()), this, SLOT(noteTextChanged()));

    fontChanged();
}

/* TODO: utrzymanie focusa na QTextEdit */

void Editor::fontChanged()
{
    currentFont = fontComboBox->currentFont();
    currentFont.setPointSize( fontSizeComboBox->currentText().toInt() );

    if(BPushButton->isChecked())
        currentFont.setBold(true);
    if(UPushButton->isChecked())
        currentFont.setUnderline(true);
    if(IPushButton->isChecked())
        currentFont.setItalic(true);

    noteTextEdit->setTextColor(currentFontColor);
    noteTextEdit->setCurrentFont(currentFont);

    getText();
}

void Editor::getColor()
{
    currentFontColor = QColorDialog::getColor(currentFontColor, this);

    if( currentFontColor.isValid() )
    {
        QString color = "QPushButton { color: "
                        % currentFontColor.name()
                        %  "}";

        //qDebug() << color;

        colorTextPushButton->setStyleSheet(color);

        fontChanged();
    }
}

void Editor::noteTextChanged()
{
    if( noteTextEdit->toPlainText().isEmpty() )
    {
        fontChanged();
    }
}

QString Editor::getHtml()
{
    //qDebug() << noteTextEdit->toHtml();
    return noteTextEdit->toHtml();
}

QString Editor::getText()
{
    return noteTextEdit->toPlainText();
}

void Editor::setText(QString text)
{
    noteTextEdit->setHtml(text);
}

void Editor::setEditable(bool value)
{
    noteTextEdit->setReadOnly(!value);
    BPushButton->setEnabled(value);
    UPushButton->setEnabled(value);
    IPushButton->setEnabled(value);
    UPushButton->setEnabled(value);
    colorTextPushButton->setEnabled(value);
    fontSizeComboBox->setEnabled(value);
    fontComboBox->setEnabled(value);
}
