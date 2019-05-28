/********************************************************************************
** Form generated from reading UI file 'databasedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEDIALOG_H
#define UI_DATABASEDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseDialog
{
public:
    QLabel *HintLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *HostNameLabel;
    QLabel *DatabaseNameLabel;
    QLabel *PortLabel;
    QLabel *UserNameLabel;
    QLabel *PasswordLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *HostNameEdit;
    QLineEdit *DatabaseNameEdit;
    QLineEdit *PortEdit;
    QLineEdit *UserNameEdit;
    QLineEdit *PasswordEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *OKButton;
    QPushButton *SkipButton;

    void setupUi(QDialog *DatabaseDialog)
    {
        if (DatabaseDialog->objectName().isEmpty())
            DatabaseDialog->setObjectName(QStringLiteral("DatabaseDialog"));
        DatabaseDialog->resize(400, 300);
        DatabaseDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        HintLabel = new QLabel(DatabaseDialog);
        HintLabel->setObjectName(QStringLiteral("HintLabel"));
        HintLabel->setGeometry(QRect(60, 30, 311, 21));
        layoutWidget = new QWidget(DatabaseDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 60, 99, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        HostNameLabel = new QLabel(layoutWidget);
        HostNameLabel->setObjectName(QStringLiteral("HostNameLabel"));

        verticalLayout->addWidget(HostNameLabel);

        DatabaseNameLabel = new QLabel(layoutWidget);
        DatabaseNameLabel->setObjectName(QStringLiteral("DatabaseNameLabel"));

        verticalLayout->addWidget(DatabaseNameLabel);

        PortLabel = new QLabel(layoutWidget);
        PortLabel->setObjectName(QStringLiteral("PortLabel"));

        verticalLayout->addWidget(PortLabel);

        UserNameLabel = new QLabel(layoutWidget);
        UserNameLabel->setObjectName(QStringLiteral("UserNameLabel"));

        verticalLayout->addWidget(UserNameLabel);

        PasswordLabel = new QLabel(layoutWidget);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        verticalLayout->addWidget(PasswordLabel);

        layoutWidget1 = new QWidget(DatabaseDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(170, 60, 181, 171));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        HostNameEdit = new QLineEdit(layoutWidget1);
        HostNameEdit->setObjectName(QStringLiteral("HostNameEdit"));
        HostNameEdit->setFocusPolicy(Qt::WheelFocus);

        verticalLayout_2->addWidget(HostNameEdit);

        DatabaseNameEdit = new QLineEdit(layoutWidget1);
        DatabaseNameEdit->setObjectName(QStringLiteral("DatabaseNameEdit"));
        DatabaseNameEdit->setFocusPolicy(Qt::WheelFocus);

        verticalLayout_2->addWidget(DatabaseNameEdit);

        PortEdit = new QLineEdit(layoutWidget1);
        PortEdit->setObjectName(QStringLiteral("PortEdit"));
        PortEdit->setFocusPolicy(Qt::WheelFocus);

        verticalLayout_2->addWidget(PortEdit);

        UserNameEdit = new QLineEdit(layoutWidget1);
        UserNameEdit->setObjectName(QStringLiteral("UserNameEdit"));
        UserNameEdit->setFocusPolicy(Qt::WheelFocus);

        verticalLayout_2->addWidget(UserNameEdit);

        PasswordEdit = new QLineEdit(layoutWidget1);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setFocusPolicy(Qt::WheelFocus);

        verticalLayout_2->addWidget(PasswordEdit);

        layoutWidget2 = new QWidget(DatabaseDialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(120, 240, 167, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        OKButton = new QPushButton(layoutWidget2);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setFocusPolicy(Qt::TabFocus);

        horizontalLayout->addWidget(OKButton);

        SkipButton = new QPushButton(layoutWidget2);
        SkipButton->setObjectName(QStringLiteral("SkipButton"));
        SkipButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(SkipButton);


        retranslateUi(DatabaseDialog);

        QMetaObject::connectSlotsByName(DatabaseDialog);
    } // setupUi

    void retranslateUi(QDialog *DatabaseDialog)
    {
        DatabaseDialog->setWindowTitle(QApplication::translate("DatabaseDialog", "Dialog", 0));
        HintLabel->setText(QApplication::translate("DatabaseDialog", "Please fill in the information of your database", 0));
        HostNameLabel->setText(QApplication::translate("DatabaseDialog", "Host name", 0));
        DatabaseNameLabel->setText(QApplication::translate("DatabaseDialog", "Database name", 0));
        PortLabel->setText(QApplication::translate("DatabaseDialog", "Port ", 0));
        UserNameLabel->setText(QApplication::translate("DatabaseDialog", "User name", 0));
        PasswordLabel->setText(QApplication::translate("DatabaseDialog", "Password", 0));
        OKButton->setText(QApplication::translate("DatabaseDialog", "OK", 0));
        SkipButton->setText(QApplication::translate("DatabaseDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class DatabaseDialog: public Ui_DatabaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEDIALOG_H
