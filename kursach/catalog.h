#ifndef CATALOG_H
#define CATALOG_H

#include <QWidget>
#include <QDir>
#include <QDateTime>
#include <QInputDialog>

class Catalog
{
public:
    Catalog();
    ~Catalog();

    void renameCatalog(QString fileName, QDir dir);
    void makeCatalog(QDir dir);
    void destroyCatalog(QDir dir);
    void copyCatalog(QDir &sDir, QDir &dDir);
};

//Ищет отсутствующие или неактуальные элементы в резервной директории
void contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffList);
//Наполняет список всех вложенных директорий и файлов
void recursiveContentList(QDir &dir, QFileInfoList &contentList);
//Удаляет каталог
int removeFolder(QDir & dir);

#endif // CATALOG_H
