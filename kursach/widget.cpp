#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    model->setFilter(QDir::QDir::AllEntries);
    model->setRootPath("");
    ui->lvBackup->setModel(model);
    ui->lvSource->setModel(model);
    connect(ui->lvBackup, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_lvSource_doubleClicked(QModelIndex)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lvSource_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    Clicker cl;
    cl.doubleClicked(index, model, listView);
    fileName = "";
}

void Widget::on_lvSource_clicked(const QModelIndex &index)
{
    Clicker cl;
    fileName = cl.clicked(index, model);
}

void Widget::on_btnBackup_clicked()
{
    QDir sDir = QDir(model->filePath(ui->lvSource->rootIndex()));
    QDir dDir = QDir(model->filePath(ui->lvBackup->rootIndex()));
    if (fileName == "")
    {
        QMessageBox::warning(0, "Ошибка", "Файл не найден", "Ok", QString(), 0, 1);
    }
    else {
    sDir.cd(fileName);
    Catalog::copyCatalog(sDir, dDir);
    }
}

void Widget::on_btnRename_clicked()
{
    QDir sDir = QDir(model->filePath(ui->lvSource->rootIndex()));
    if (fileName == "")
    {
        QMessageBox::warning(0, "Ошибка", "Файл не найден", "Ok");
    }
    else
        Catalog::renameCatalog(fileName, sDir);
}

void Widget::on_btnMake_clicked()
{
    QDir sDir = QDir(model->filePath(ui->lvSource->rootIndex()));
    Catalog::makeCatalog(sDir);
}

void Widget::on_btnDestroy_clicked()
{
    QDir sDir = QDir(model->filePath(ui->lvSource->rootIndex()));
    if (fileName == "")
    {
        QMessageBox::warning(0, "Ошибка", "Файл не найден", "Ok");
    }
    else
    {
        sDir.cd(fileName);
        Catalog::destroyCatalog(sDir);
    }
}
