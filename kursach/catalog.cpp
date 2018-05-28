#include "catalog.h"

Catalog::Catalog()
{

}

Catalog::~Catalog()
{

}

void Catalog::renameCatalog(QString fileName, QDir dir)
{
   QString newFileName;
   bool bOk;
   newFileName = QInputDialog::getText(0, "Файловый менеджер", "Переименование", QLineEdit::Normal, "", &bOk);
   dir.rename(fileName, newFileName);
}

void Catalog::makeCatalog(QDir dir)
{
    QString fileName;
    bool bOk;
    fileName = QInputDialog::getText(0, "Файловый менеджер", "Создать новую папку", QLineEdit::Normal, "", &bOk);
    dir.mkdir(fileName);
}

void Catalog::destroyCatalog(QDir dir)
{
    removeFolder(dir);
}

void Catalog::copyCatalog(QDir &sDir, QDir &dDir)
{
    QFileInfoList diffList = QFileInfoList();
    contentDifference(sDir, dDir, diffList);

    foreach(QFileInfo diffInfo, diffList){
        QString backupPath = diffInfo.filePath().replace(sDir.absolutePath(), dDir.absolutePath());
        if (diffInfo.isFile()){
            QFile::remove(backupPath);
            QFile::copy(diffInfo.absoluteFilePath(), backupPath);
        }
        if (diffInfo.isDir()){
            dDir.mkdir(backupPath);
        }
    }
}

void contentDifference(QDir &sDir, QDir &dDir, QFileInfoList &diffList)
{
    foreach(QFileInfo sInfo, sDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)){
        bool fileExists = false;
        foreach(QFileInfo dInfo, dDir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)){
            if (sInfo.fileName() == dInfo.fileName()) {
                if (sInfo.isDir() || sInfo.lastModified() <= dInfo.lastModified())
                    fileExists = true;
                break;
            }
        }
        if (!fileExists)
            diffList.append(sInfo);
        if (sInfo.isFile())
            continue;
        if (fileExists){
            sDir.cd(sInfo.fileName());
            dDir.cd(sInfo.fileName());
            contentDifference(sDir, dDir, diffList);
            sDir.cdUp();
            dDir.cdUp();
        }
        else {
            sDir.cd(sInfo.fileName());
            recursiveContentList(sDir, diffList);
            sDir.cdUp();
        }
    }
}

void recursiveContentList(QDir &dir, QFileInfoList &contentList)
{
    foreach(QFileInfo info, dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot, QDir::Name|QDir::DirsFirst)){
        contentList.append(info);
        if (info.isDir() && dir.cd(info.fileName())){
            recursiveContentList(dir, contentList);
            dir.cdUp();
        }
    }
}

int removeFolder(QDir & dir)
{
  int res = 0;
  //Получаем список каталогов
  QStringList lstDirs = dir.entryList(QDir::Dirs |
                  QDir::AllDirs |
                  QDir::NoDotAndDotDot);
  //Получаем список файлов
  QStringList lstFiles = dir.entryList(QDir::Files);

  //Удаляем файлы
  foreach (QString entry, lstFiles)
  {
   QString entryAbsPath = dir.absolutePath() + "/" + entry;
   QFile::setPermissions(entryAbsPath, QFile::ReadOwner | QFile::WriteOwner);
   QFile::remove(entryAbsPath);
  }

  //Для папок делаем рекурсивный вызов
  foreach (QString entry, lstDirs)
  {
   QString entryAbsPath = dir.absolutePath() + "/" + entry;
   QDir dr(entryAbsPath);
   removeFolder(dr);
  }

  //Удаляем обрабатываемую папку
  if (!QDir().rmdir(dir.absolutePath()))
  {
    res = 1;
  }
  return res;
}
