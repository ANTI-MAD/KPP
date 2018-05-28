#ifndef CLICKER_H
#define CLICKER_H

#include <QFile>
#include <QDir>
#include <QListView>
#include <QFileSystemModel>

class Clicker
{
public:
    Clicker();
    ~Clicker();

    void doubleClicked(const QModelIndex &index, QFileSystemModel * model, QListView* listView);
    QString clicked(const QModelIndex &index, QFileSystemModel * model);
private:
    QString fileName;
};

#endif // CLICKER_H
