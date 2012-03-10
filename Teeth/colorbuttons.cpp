#include <QtGui>
#include "colorbuttons.h"

ColorButtons::ColorButtons(QWidget *parent) :
    QWidget(parent)
{
    createColorButtons();
    createLayout();

    createButtonsMap();
    connectButtons();

    setLayout(mainLayout);
}

void ColorButtons::createColorButtons()
{
    clearButton = new QPushButton( tr("Wyczyść") );
    clearButton->setAutoFillBackground(true);
    clearButton->setStyleSheet("background-color: white; color: black");

    clearAllButton = new QPushButton( tr("Wyczyść cały") );
    clearAllButton->setAutoFillBackground(true);
    clearAllButton->setStyleSheet("background-color: white; color: black");

    cariesButton = new QPushButton( tr("Próchnica") );
    cariesButton->setAutoFillBackground(true);
    cariesButton->setStyleSheet("background-color: rgb(255, 0, 0); color: rgb(255,255,255)");

    fillingButton = new QPushButton( tr("Wypełnienie") );
    fillingButton->setAutoFillBackground(true);
    fillingButton->setStyleSheet("background-color: blue; color: white");

    rootButton =new QPushButton( tr("Korzeń") );
    rootButton->setAutoFillBackground(true);
    rootButton->setStyleSheet("background-color: yellow; color: black");

    crownButton = new QPushButton( tr("Korona") );
    crownButton->setAutoFillBackground(true);
    crownButton->setStyleSheet("background-color: purple; color: white");

    calculusButton = new QPushButton( tr("Kamień") );
    calculusButton->setAutoFillBackground(true);
    calculusButton->setStyleSheet("background-color: gray; color: white");

    bridgeButton = new QPushButton( tr("Most") );
    bridgeButton->setAutoFillBackground(true);
    bridgeButton->setStyleSheet("background-color: green; color: white");

    toExtractionButton = new QPushButton( tr("Do usunięcia") );
    toExtractionButton->setAutoFillBackground(true);
    toExtractionButton->setStyleSheet("background-color: rgb(56,0,0); color: white");

    emptyButton = new QPushButton( tr("Brak zęba" ) );
    emptyButton->setAutoFillBackground(true);
    emptyButton->setStyleSheet("background-color: black; color: white");


}

void ColorButtons::createButtonsMap()
{
    colorMap["clear"] = Qt::white;
    colorMap["clearAll"] = Qt::white;
    colorMap["caries"] = Qt::red;
    colorMap["filling"] = Qt::blue;
    colorMap["root"] = Qt::yellow;
    colorMap["crown"] = Qt::darkMagenta;
    colorMap["calculus"] = Qt::gray;
    colorMap["bridge"] = Qt::green;
    colorMap["toExtraction"] = QColor("#380000");
    colorMap["empty"] = Qt::black;

}

void ColorButtons::createLayout()
{
    QHBoxLayout *colorButtonsLayoutUp = new QHBoxLayout;
    colorButtonsLayoutUp->addWidget(clearButton);
    colorButtonsLayoutUp->addWidget(cariesButton);
    colorButtonsLayoutUp->addWidget(fillingButton);
    colorButtonsLayoutUp->addWidget(rootButton);
    colorButtonsLayoutUp->addWidget(emptyButton);
    colorButtonsLayoutUp->addStretch();

    QHBoxLayout *colorButtonsLayoutDown = new QHBoxLayout;
    colorButtonsLayoutDown->addWidget(clearAllButton);
    colorButtonsLayoutDown->addWidget(crownButton);
    colorButtonsLayoutDown->addWidget(calculusButton);
    colorButtonsLayoutDown->addWidget(bridgeButton);
    colorButtonsLayoutDown->addWidget(toExtractionButton);
    colorButtonsLayoutDown->addStretch();

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(colorButtonsLayoutUp);
    mainLayout->addLayout(colorButtonsLayoutDown);
}

void ColorButtons::connectButtons()
{
    signalMapper = new QSignalMapper;

    connect(clearButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(clearAllButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(cariesButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(fillingButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(rootButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(crownButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(calculusButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(bridgeButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(toExtractionButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(emptyButton, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper->setMapping(clearButton, "clear");
    signalMapper->setMapping(clearAllButton, "clearAll");
    signalMapper->setMapping(cariesButton, "caries");
    signalMapper->setMapping(fillingButton, "filling");
    signalMapper->setMapping(rootButton, "root");
    signalMapper->setMapping(crownButton, "crown");
    signalMapper->setMapping(calculusButton, "calculus");
    signalMapper->setMapping(bridgeButton, "bridge");
    signalMapper->setMapping(toExtractionButton, "toExtraction");
    signalMapper->setMapping(emptyButton, "empty");

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(buttonClicked(QString)));

}

void ColorButtons::buttonClicked(const QString &text)
{
    QColor color = colorMap[text];

    if( (text == "root") || text == ("clearAll")
        || (text == "empty") || (text == "toExtraction")  )
        emit colorChanged(color, false);
    else
        emit colorChanged(color, true);
}

