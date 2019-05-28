/********************************************************************************
** Form generated from reading UI file 'docdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCDIALOG_H
#define UI_DOCDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DocDialog
{
public:
    QTextBrowser *textBrowser;
    QListWidget *listWidget;
    QPushButton *QuitButton;

    void setupUi(QDialog *DocDialog)
    {
        if (DocDialog->objectName().isEmpty())
            DocDialog->setObjectName(QStringLiteral("DocDialog"));
        DocDialog->resize(678, 449);
        textBrowser = new QTextBrowser(DocDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(260, 30, 401, 361));
        listWidget = new QListWidget(DocDialog);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 70, 201, 261));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setResizeMode(QListView::Fixed);
        QuitButton = new QPushButton(DocDialog);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setGeometry(QRect(580, 410, 75, 23));

        retranslateUi(DocDialog);

        QMetaObject::connectSlotsByName(DocDialog);
    } // setupUi

    void retranslateUi(QDialog *DocDialog)
    {
        DocDialog->setWindowTitle(QApplication::translate("DocDialog", "Document", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("DocDialog", "1. How to connect to database", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("DocDialog", "1.1 connect to provided database", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("DocDialog", "1.2 connect to remote database", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("DocDialog", "1.3 connect to new created database", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("DocDialog", "2. How to configure serial port option", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("DocDialog", "3. How to add a user in database", 0));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("DocDialog", "4. How to remove a user in database", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        QuitButton->setText(QApplication::translate("DocDialog", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class DocDialog: public Ui_DocDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCDIALOG_H
