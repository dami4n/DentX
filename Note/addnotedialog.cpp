#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "notewidget.h"

#include "addnotedialog.h"

AddNoteDialog::AddNoteDialog(QWidget *parent) :
    QDialog(parent)
{
    createGui();
    createLayout();

    setWindowTitle( tr("Dodaj notatkę") );
}

void AddNoteDialog::createGui()
{
    noteWidget = new NoteWidget;
    noteWidget->setToday();

    okButton = new QPushButton( tr("Ok") );
    cancelButton = new QPushButton( tr("Anuluj") );

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void AddNoteDialog::createLayout()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addStretch();
    buttonLayout->setDirection(QBoxLayout::RightToLeft);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(noteWidget);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void AddNoteDialog::okClicked()
{
    if( noteWidget->getTopic().isEmpty() )
    {
        QMessageBox::warning(this, tr("Puste pole"),
                             tr("Pole 'temat' musi być uzupełnione"));
    }
    else
    {
        accept();
    }
}

Note AddNoteDialog::getNote() const
{
    return noteWidget->getNote();
}
