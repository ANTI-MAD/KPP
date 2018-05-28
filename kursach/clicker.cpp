#include "clicker.h"

Clicker::Clicker()
{

}

Clicker::~Clicker()
{

}

void Clicker::doubleClicked(const QModelIndex &index, QFileSystemModel * model, QListView *listView)
{
    QFileInfo fileInfo = model->fileInfo(index);
    if (fileInfo.fileName() == "..") {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView->setRootIndex(model->index(dir.absolutePath()));
    }
    else if (fileInfo.fileName() == ".") {
        listView->setRootIndex(model->index(""));
    }
    else if (fileInfo.isDir()) {
        listView->setRootIndex(index);
    }
}

QString Clicker::clicked(const QModelIndex &index, QFileSystemModel *model)
{
    QFileInfo fileInfo = model->fileInfo(index);
    fileName = fileInfo.fileName();
    return fileName;
}
