/********************************************************************************
** Form generated from reading UI file 'serialportsettingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTSETTINGDIALOG_H
#define UI_SERIALPORTSETTINGDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortSettingDialog
{
public:
    QPushButton *PortButton;
    QWidget *layoutWidget;
    QVBoxLayout *PortBaudLayout;
    QLabel *PortLabel;
    QLabel *BaudrateLabel;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QComboBox *PortComboBox;
    QComboBox *BaudComboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *OKButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *SerialPortSettingDialog)
    {
        if (SerialPortSettingDialog->objectName().isEmpty())
            SerialPortSettingDialog->setObjectName(QStringLiteral("SerialPortSettingDialog"));
        SerialPortSettingDialog->resize(400, 300);
        SerialPortSettingDialog->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        PortButton = new QPushButton(SerialPortSettingDialog);
        PortButton->setObjectName(QStringLiteral("PortButton"));
        PortButton->setGeometry(QRect(130, 60, 165, 32));
        PortButton->setFocusPolicy(Qt::NoFocus);
        layoutWidget = new QWidget(SerialPortSettingDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 100, 58, 51));
        PortBaudLayout = new QVBoxLayout(layoutWidget);
        PortBaudLayout->setObjectName(QStringLiteral("PortBaudLayout"));
        PortBaudLayout->setContentsMargins(0, 0, 0, 0);
        PortLabel = new QLabel(layoutWidget);
        PortLabel->setObjectName(QStringLiteral("PortLabel"));

        PortBaudLayout->addWidget(PortLabel);

        BaudrateLabel = new QLabel(layoutWidget);
        BaudrateLabel->setObjectName(QStringLiteral("BaudrateLabel"));

        PortBaudLayout->addWidget(BaudrateLabel);

        layoutWidget_2 = new QWidget(SerialPortSettingDialog);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(129, 99, 171, 56));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PortComboBox = new QComboBox(layoutWidget_2);
        PortComboBox->setObjectName(QStringLiteral("PortComboBox"));
        PortComboBox->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(PortComboBox);

        BaudComboBox = new QComboBox(layoutWidget_2);
        BaudComboBox->setObjectName(QStringLiteral("BaudComboBox"));

        verticalLayout->addWidget(BaudComboBox);

        layoutWidget1 = new QWidget(SerialPortSettingDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(130, 160, 161, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        OKButton = new QPushButton(layoutWidget1);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(OKButton);

        CancelButton = new QPushButton(layoutWidget1);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(CancelButton);


        retranslateUi(SerialPortSettingDialog);

        QMetaObject::connectSlotsByName(SerialPortSettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SerialPortSettingDialog)
    {
        SerialPortSettingDialog->setWindowTitle(QApplication::translate("SerialPortSettingDialog", "Dialog", 0));
        PortButton->setText(QApplication::translate("SerialPortSettingDialog", "show available port", 0));
        PortLabel->setText(QApplication::translate("SerialPortSettingDialog", "Port", 0));
        BaudrateLabel->setText(QApplication::translate("SerialPortSettingDialog", "Baudrate", 0));
        OKButton->setText(QApplication::translate("SerialPortSettingDialog", "OK", 0));
        CancelButton->setText(QApplication::translate("SerialPortSettingDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialPortSettingDialog: public Ui_SerialPortSettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTSETTINGDIALOG_H
