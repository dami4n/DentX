#include <QLabel>
#include <QVBoxLayout>
#include "finishpage.h"

FinishPage::FinishPage(QWidget *parent) :
    QWizardPage(parent)
{
    setTitle( tr("Konfiguracja zakończona") );

    QLabel *introLabel = new QLabel( tr("Konfiguracja została pozytywnie ukończona."
                                        "Aby kontunować kliknij 'Zakończ'"));

    introLabel->setWordWrap(true);

    setPixmap(QWizard::WatermarkPixmap,
                          QPixmap(":/icons/wizard.jpg"));


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(introLabel);

    setLayout(layout);
}
