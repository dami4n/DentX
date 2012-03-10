#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QDialog>
#include <QString>
#include <QTextCursor>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QStringBuilder>
#include "databasedebugdialog.h"

DatabaseDebugDialog::DatabaseDebugDialog(QWidget *parent) :
    QDialog(parent)
{
    createGUI();

    resize(600, 450);
}

void DatabaseDebugDialog::createGUI()
{
    queryButton = new QPushButton(tr("query"));
    connect(queryButton, SIGNAL(clicked()), this, SLOT(queryClicked()));

    queryLineEdit = new QLineEdit;
    queryLineEdit->setText("SELECT * FROM patient");

    queryResultTextEdit = new QTextEdit;
    queryResultTextEdit->setReadOnly(true);

    QHBoxLayout *queryLayout = new QHBoxLayout;
    queryLayout->addWidget(queryLineEdit);
    queryLayout->addWidget(queryButton);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(queryResultTextEdit);
    mainLayout->addLayout(queryLayout);

    QTimer::singleShot(0,queryLineEdit,SLOT(setFocus()));

    setLayout(mainLayout);
    setWindowTitle(tr("Tryb debug bazy danych"));
}

void DatabaseDebugDialog::queryClicked()
{
    QString queryString = queryLineEdit->text();
    query(queryString);
}

void DatabaseDebugDialog::query(const QString queryString)
{
    QSqlQuery query;

    bool value = query.exec(queryString);

    int col = query.record().count();

    QString result = "<font color='red'><b>" % query.lastQuery() % "</b></font>";

    if( !value )
    {
        QString err = query.lastError().text();
        result = result % "<p>" % err;
    }

    while (query.next())
    {
           if((query.at() + 1) % 2 == 0 )
                result = result % "<p><font color = green>";
           else
               result = result % "<p><font color = blue>";

           for(int i = 0; i < col; ++i)
           {
                result = result % query.value(i).toString() % " ";
           }

           result = result % "</font>";
    }

    if(queryResultTextEdit->toPlainText().isEmpty())
        result = queryResultTextEdit->toHtml() % result;
    else
        result = queryResultTextEdit->toHtml() % "<br><br><br><br><hr><hr>" % result;

    QTextCursor c =  queryResultTextEdit->textCursor();
    c.movePosition(QTextCursor::End);
    queryResultTextEdit->setTextCursor(c);
    queryResultTextEdit->setHtml(result);
    queryResultTextEdit->ensureCursorVisible();
    queryResultTextEdit->setTextCursor(c);
}
