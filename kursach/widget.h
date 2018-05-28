#ifndef WIDGET_H
#define WIDGET_H

#include "catalog.h"
#include "clicker.h"
#include <QWidget>
#include <QFileSystemModel>
#include <QDir>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget, public Catalog
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_lvSource_doubleClicked(const QModelIndex &index);

    void on_lvSource_clicked(const QModelIndex &index);

    void on_btnBackup_clicked();

    void on_btnRename_clicked();

    void on_btnMake_clicked();

    void on_btnDestroy_clicked();

private:
    QString fileName;
    Ui::Widget *ui;
    QFileSystemModel * model;
};

//Ищет отсутствующие или неактуальные элементы в резервной директории
void contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffList);
//Наполняет список всех вложенных директорий и файлов
void recursiveContentList(QDir &dir, QFileInfoList &contentList);
int removeFolder(QDir & dir);
#endif // WIDGET_H
