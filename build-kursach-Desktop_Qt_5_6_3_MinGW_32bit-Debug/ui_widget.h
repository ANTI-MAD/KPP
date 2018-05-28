/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListView *lvSource;
    QListView *lvBackup;
    QPushButton *btnDestroy;
    QPushButton *btnBackup;
    QPushButton *btnRename;
    QPushButton *btnMake;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(752, 350);
        lvSource = new QListView(Widget);
        lvSource->setObjectName(QStringLiteral("lvSource"));
        lvSource->setGeometry(QRect(0, 0, 311, 291));
        lvBackup = new QListView(Widget);
        lvBackup->setObjectName(QStringLiteral("lvBackup"));
        lvBackup->setGeometry(QRect(350, 0, 311, 291));
        btnDestroy = new QPushButton(Widget);
        btnDestroy->setObjectName(QStringLiteral("btnDestroy"));
        btnDestroy->setGeometry(QRect(440, 310, 75, 23));
        btnBackup = new QPushButton(Widget);
        btnBackup->setObjectName(QStringLiteral("btnBackup"));
        btnBackup->setGeometry(QRect(20, 310, 141, 23));
        btnRename = new QPushButton(Widget);
        btnRename->setObjectName(QStringLiteral("btnRename"));
        btnRename->setGeometry(QRect(180, 310, 101, 23));
        btnMake = new QPushButton(Widget);
        btnMake->setObjectName(QStringLiteral("btnMake"));
        btnMake->setGeometry(QRect(300, 310, 121, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        btnDestroy->setText(QApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        btnBackup->setText(QApplication::translate("Widget", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        btnRename->setText(QApplication::translate("Widget", "\320\237\320\265\321\200\320\265\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        btnMake->setText(QApplication::translate("Widget", "\320\232\320\260\321\202\320\260\320\273\320\276\320\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
