#ifndef RADIOGRAPH_H
#define RADIOGRAPH_H

#include <QListView>

class Radiograph : public QListView
{
    Q_OBJECT
public:
    explicit Radiograph(QWidget *parent = 0);

signals:

public slots:
    void doubleClicked(const QModelIndex &index);

private:
    void showPhoto(const QString& fileName);

};

#endif // RADIOGRAPH_H
