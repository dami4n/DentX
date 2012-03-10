#include <QAbstractItemView>
#include <QHeaderView>
#include <QColor>
#include <QPalette>
#include "cardfiletable.h"

CardfileTable::CardfileTable(QWidget *parent) :
    QTableView(parent)
{
    setTableOptions();

}

void CardfileTable::setTableOptions()
{
    setAlternatingRowColors(true);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setShowGrid(true);
    horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    resizeColumnsToContents();

    connect( horizontalHeader(), SIGNAL(sectionClicked(int)),
             this, SLOT(sortByColumn(int)));
}

void CardfileTable::setTableColor(QColor alternateBaseColor, QColor baseColor)
{
    // to nie działa pod GNOME ??

    setAutoFillBackground(true);

    QPalette pal = palette();
    pal.setColor(QPalette::AlternateBase, alternateBaseColor );
    pal.setColor(QPalette::Base, baseColor );
    setPalette(pal);
}

void CardfileTable::setTableColor(QColor alternateBaseColor)
{
    // to nie działa pod GNOME ??

    setAutoFillBackground(true);

    QPalette pal = palette();
    pal.setColor(QPalette::AlternateBase, alternateBaseColor );
    setPalette(pal);
}

void CardfileTable::hideVerticalHeader( bool value )
{
    if( value )
    {
        verticalHeader()->hide();
    }
    else
    {
        verticalHeader()->show();
    }
}








