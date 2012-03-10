#include <QLabel>
#include <QVBoxLayout>
#include "intropage.h"

IntroPage::IntroPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle( tr("Witaj w kreatorze konfiguracji DentX!") );

    QLabel *introLabel = new QLabel( tr("Ten kreator pomoże Ci skonfigurować program"
                                   " podczas pierwszego uruchomienia."
                                   " Aby kontynuować kliknij przycisk 'Dalej'"));

    introLabel->setWordWrap(true);

    setPixmap(QWizard::WatermarkPixmap,
                          QPixmap(":/icons/wizard.jpg"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(introLabel);

    setLayout(layout);
}
