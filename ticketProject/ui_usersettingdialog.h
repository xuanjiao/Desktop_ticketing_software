/********************************************************************************
** Form generated from reading UI file 'usersettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSETTINGDIALOG_H
#define UI_USERSETTINGDIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserSettingDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *TextLableLayout;
    QVBoxLayout *LabelLayout;
    QLabel *NameLabel;
    QLabel *PeriodLabel;
    QLabel *PaymentLabel;
    QVBoxLayout *TextLayout;
    QLineEdit *NameText;
    QLineEdit *PeriodText;
    QLineEdit *PaymentText;
    QTableView *tableView;
    QLabel *InfoLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *AddButton;
    QPushButton *RemoveButton;
    QSpacerItem *verticalSpacer;
    QPushButton *QuitButton;
    QLabel *InfoLabel_2;

    void setupUi(QDialog *UserSettingDialog)
    {
        if (UserSettingDialog->objectName().isEmpty())
            UserSettingDialog->setObjectName(QStringLiteral("UserSettingDialog"));
        UserSettingDialog->resize(631, 279);
        UserSettingDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        layoutWidget = new QWidget(UserSettingDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 80, 191, 111));
        TextLableLayout = new QHBoxLayout(layoutWidget);
        TextLableLayout->setObjectName(QStringLiteral("TextLableLayout"));
        TextLableLayout->setContentsMargins(0, 0, 0, 0);
        LabelLayout = new QVBoxLayout();
        LabelLayout->setObjectName(QStringLiteral("LabelLayout"));
        NameLabel = new QLabel(layoutWidget);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));

        LabelLayout->addWidget(NameLabel);

        PeriodLabel = new QLabel(layoutWidget);
        PeriodLabel->setObjectName(QStringLiteral("PeriodLabel"));

        LabelLayout->addWidget(PeriodLabel);

        PaymentLabel = new QLabel(layoutWidget);
        PaymentLabel->setObjectName(QStringLiteral("PaymentLabel"));

        LabelLayout->addWidget(PaymentLabel);


        TextLableLayout->addLayout(LabelLayout);

        TextLayout = new QVBoxLayout();
        TextLayout->setObjectName(QStringLiteral("TextLayout"));
        NameText = new QLineEdit(layoutWidget);
        NameText->setObjectName(QStringLiteral("NameText"));

        TextLayout->addWidget(NameText);

        PeriodText = new QLineEdit(layoutWidget);
        PeriodText->setObjectName(QStringLiteral("PeriodText"));

        TextLayout->addWidget(PeriodText);

        PaymentText = new QLineEdit(layoutWidget);
        PaymentText->setObjectName(QStringLiteral("PaymentText"));

        TextLayout->addWidget(PaymentText);


        TextLableLayout->addLayout(TextLayout);

        tableView = new QTableView(UserSettingDialog);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(380, 50, 231, 201));
        InfoLabel = new QLabel(UserSettingDialog);
        InfoLabel->setObjectName(QStringLiteral("InfoLabel"));
        InfoLabel->setGeometry(QRect(40, 20, 191, 51));
        layoutWidget1 = new QWidget(UserSettingDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 50, 124, 201));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        AddButton = new QPushButton(layoutWidget1);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(AddButton);

        RemoveButton = new QPushButton(layoutWidget1);
        RemoveButton->setObjectName(QStringLiteral("RemoveButton"));
        RemoveButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(RemoveButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        QuitButton = new QPushButton(layoutWidget1);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(QuitButton);

        InfoLabel_2 = new QLabel(UserSettingDialog);
        InfoLabel_2->setObjectName(QStringLiteral("InfoLabel_2"));
        InfoLabel_2->setGeometry(QRect(390, 10, 251, 31));
        layoutWidget->raise();
        layoutWidget->raise();
        tableView->raise();
        InfoLabel->raise();
        InfoLabel_2->raise();

        retranslateUi(UserSettingDialog);

        QMetaObject::connectSlotsByName(UserSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *UserSettingDialog)
    {
        UserSettingDialog->setWindowTitle(QApplication::translate("UserSettingDialog", "Dialog", 0));
        NameLabel->setText(QApplication::translate("UserSettingDialog", "Name", 0));
        PeriodLabel->setText(QApplication::translate("UserSettingDialog", "Period", 0));
        PaymentLabel->setText(QApplication::translate("UserSettingDialog", "Payment", 0));
        InfoLabel->setText(QApplication::translate("UserSettingDialog", "Please enter the information\n"
" of the new user and click \n"
" \"Add User\" button", 0));
        AddButton->setText(QApplication::translate("UserSettingDialog", "Add User", 0));
        RemoveButton->setText(QApplication::translate("UserSettingDialog", "Remove User", 0));
        QuitButton->setText(QApplication::translate("UserSettingDialog", "Quit", 0));
        InfoLabel_2->setText(QApplication::translate("UserSettingDialog", "Please choose one user and click \n"
"  \"Remove User\" button", 0));
    } // retranslateUi

};

namespace Ui {
    class UserSettingDialog: public Ui_UserSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSETTINGDIALOG_H
