#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "notewidget.h"

#include "shownotedialog.h"

ShowNoteDialog::ShowNoteDialog(QWidget *parent) :
    QDialog(parent)
{
    createGui();
    createLayout();
}

ShowNoteDialog::ShowNoteDialog(Note note, QWidget *parent) :
    QDialog(parent)
{
    createGui();
    createLayout();
    setNote(note);
}


void ShowNoteDialog::createGui()
{
    noteWidget = new NoteWidget;
    noteWidget->setEditable(false);

    okButton = new QPushButton( tr("Ok") );
    okButton->setEnabled(false);
    cancelButton = new QPushButton( tr("Anuluj") );

    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void ShowNoteDialog::createLayout()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(okButton);
    buttonLayout->addStretch();
    buttonLayout->setDirection(QBoxLayout::RightToLeft);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(noteWidget);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void ShowNoteDialog::setNote(Note note)
{
   noteWidget->setNote(note);
}

void ShowNoteDialog::setNote(QString topic, QString text)
{
   noteWidget->setNote(topic, text);
}
