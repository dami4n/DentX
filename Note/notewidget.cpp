#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QTextCodec>
#include <QDateTime>
#include "editor.h"
#include "note.h"

#include "notewidget.h"

NoteWidget::NoteWidget(QWidget *parent) :
    QWidget(parent)
{
    createGui();
    createLayout();
}


void NoteWidget::createGui()
{
    noteTopicLabel = new QLabel( tr("Temat:") );
    noteTopicLabel->setAlignment(Qt::AlignTop);
    topicLineEdit = new QLineEdit;
    topicLineEdit->setMaxLength(100); // czy potrzebne?

    dateLabel = new QLabel( tr("Data:") );
    dateLabel->setAlignment(Qt::AlignTop);
    dateLineEdit = new QLineEdit;
    dateLineEdit->setEnabled(false);

    noteTextLabel = new QLabel(tr("Treść: "));
    noteTextLabel->setAlignment(Qt::AlignTop);
    editor = new Editor;
}


void NoteWidget::createLayout()
{
//    QHBoxLayout *topicLayout = new QHBoxLayout;
//    topicLayout->addWidget(noteTopicLabel);
//    topicLayout->addWidget(topicLineEdit);

//    QHBoxLayout *editorLayout = new QHBoxLayout;
//    editorLayout->addWidget(noteTextLabel);
//    editorLayout->addWidget(editor);

//    QHBoxLayout *dateLayout = new QHBoxLayout;
//    dateLayout->addWidget(dateLabel);
//    dateLayout->addWidget(dateLineEdit);

//    QVBoxLayout *mainLayout = new QVBoxLayout;
//    mainLayout->addLayout(topicLayout);
//    mainLayout->addLayout(dateLayout);
//    mainLayout->addLayout(editorLayout);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(noteTopicLabel, 0, 0);
    mainLayout->addWidget(topicLineEdit, 0, 1, 1, 3);
    mainLayout->addWidget(dateLabel, 1, 0);
    mainLayout->addWidget(dateLineEdit, 1, 1, 1, 3);
    mainLayout->addWidget(noteTextLabel, 2, 0);
    mainLayout->addWidget(editor, 2, 1, 1, 3);

    setLayout(mainLayout);
}

Note NoteWidget::getNote()
{
    Note note;
    note.dateAdded = QDateTime::currentDateTime().toString();
    note.text = editor->getText();
    note.textHtml = editor->getHtml();
    note.topic = topicLineEdit->text();

    return note;
}

void NoteWidget::setNote(Note note)
{
    editor->setText(note.text);
    dateLineEdit->setText(note.dateAdded);
    topicLineEdit->setText(note.topic);
}

void NoteWidget::setNote(QString topic, QString text)
{
    editor->setText(text);
    topicLineEdit->setText(topic);
}

void NoteWidget::setEditable(bool value)
{
    editor->setEditable(value);
    topicLineEdit->setReadOnly(!value);
}

void NoteWidget::setToday()
{
    dateLineEdit->setText(QDateTime::currentDateTime().toString());
}

QString NoteWidget::getTopic()
{
    return topicLineEdit->text();
}
