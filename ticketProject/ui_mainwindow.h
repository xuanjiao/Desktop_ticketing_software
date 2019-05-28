/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *TextLableLayout;
    QVBoxLayout *LabelLayout;
    QLabel *RFIDLabel;
    QLabel *NameLabel;
    QLabel *PeriodLabel;
    QLabel *PaymentLabel;
    QVBoxLayout *TextLayout;
    QLineEdit *RFIDText;
    QLineEdit *NameText;
    QLineEdit *PeriodText;
    QLineEdit *PaymentText;
    QWidget *layoutWidget1;
    QHBoxLayout *QuitLayout;
    QPushButton *StartButton;
    QPushButton *StopButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *SerialButton;
    QPushButton *UserSettingButtton;
    QPushButton *DatabaseButton;
    QPushButton *QuitButton;
    QPushButton *QuestionButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *PictureLabel;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(542, 365);
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        MainWindow->setFont(font);
        MainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        MainWindow->setAcceptDrops(false);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 40, 231, 171));
        TextLableLayout = new QHBoxLayout(layoutWidget);
        TextLableLayout->setSpacing(6);
        TextLableLayout->setContentsMargins(11, 11, 11, 11);
        TextLableLayout->setObjectName(QStringLiteral("TextLableLayout"));
        TextLableLayout->setContentsMargins(0, 0, 0, 0);
        LabelLayout = new QVBoxLayout();
        LabelLayout->setSpacing(6);
        LabelLayout->setObjectName(QStringLiteral("LabelLayout"));
        RFIDLabel = new QLabel(layoutWidget);
        RFIDLabel->setObjectName(QStringLiteral("RFIDLabel"));

        LabelLayout->addWidget(RFIDLabel);

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
        TextLayout->setSpacing(6);
        TextLayout->setObjectName(QStringLiteral("TextLayout"));
        RFIDText = new QLineEdit(layoutWidget);
        RFIDText->setObjectName(QStringLiteral("RFIDText"));
        RFIDText->setFocusPolicy(Qt::NoFocus);

        TextLayout->addWidget(RFIDText);

        NameText = new QLineEdit(layoutWidget);
        NameText->setObjectName(QStringLiteral("NameText"));
        NameText->setFocusPolicy(Qt::NoFocus);

        TextLayout->addWidget(NameText);

        PeriodText = new QLineEdit(layoutWidget);
        PeriodText->setObjectName(QStringLiteral("PeriodText"));
        PeriodText->setFocusPolicy(Qt::NoFocus);

        TextLayout->addWidget(PeriodText);

        PaymentText = new QLineEdit(layoutWidget);
        PaymentText->setObjectName(QStringLiteral("PaymentText"));
        PaymentText->setFocusPolicy(Qt::NoFocus);

        TextLayout->addWidget(PaymentText);


        TextLableLayout->addLayout(TextLayout);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(280, 220, 188, 32));
        QuitLayout = new QHBoxLayout(layoutWidget1);
        QuitLayout->setSpacing(6);
        QuitLayout->setContentsMargins(11, 11, 11, 11);
        QuitLayout->setObjectName(QStringLiteral("QuitLayout"));
        QuitLayout->setContentsMargins(0, 0, 0, 0);
        StartButton = new QPushButton(layoutWidget1);
        StartButton->setObjectName(QStringLiteral("StartButton"));

        QuitLayout->addWidget(StartButton);

        StopButton = new QPushButton(layoutWidget1);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        QuitLayout->addWidget(StopButton);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 120, 155, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SerialButton = new QPushButton(layoutWidget2);
        SerialButton->setObjectName(QStringLiteral("SerialButton"));

        verticalLayout_2->addWidget(SerialButton);

        UserSettingButtton = new QPushButton(layoutWidget2);
        UserSettingButtton->setObjectName(QStringLiteral("UserSettingButtton"));

        verticalLayout_2->addWidget(UserSettingButtton);

        DatabaseButton = new QPushButton(layoutWidget2);
        DatabaseButton->setObjectName(QStringLiteral("DatabaseButton"));

        verticalLayout_2->addWidget(DatabaseButton);

        QuitButton = new QPushButton(centralWidget);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setGeometry(QRect(400, 270, 69, 32));
        QuestionButton = new QPushButton(centralWidget);
        QuestionButton->setObjectName(QStringLiteral("QuestionButton"));
        QuestionButton->setGeometry(QRect(500, 10, 16, 21));
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/logo/qestion.png"), QSize(), QIcon::Normal, QIcon::Off);
        QuestionButton->setIcon(icon);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 61, 51));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 50, 47, 13));
        PictureLabel = new QLabel(centralWidget);
        PictureLabel->setObjectName(QStringLiteral("PictureLabel"));
        PictureLabel->setGeometry(QRect(50, 220, 121, 111));
        PictureLabel->setMinimumSize(QSize(0, 71));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 542, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Log X", 0));
        RFIDLabel->setText(QApplication::translate("MainWindow", "RFID", 0));
        NameLabel->setText(QApplication::translate("MainWindow", "Name", 0));
        PeriodLabel->setText(QApplication::translate("MainWindow", "Period", 0));
        PaymentLabel->setText(QApplication::translate("MainWindow", "Payment", 0));
        StartButton->setText(QApplication::translate("MainWindow", "Start", 0));
        StopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        SerialButton->setText(QApplication::translate("MainWindow", "Serial port setting", 0));
        UserSettingButtton->setText(QApplication::translate("MainWindow", "User setting", 0));
        DatabaseButton->setText(QApplication::translate("MainWindow", "Database setting", 0));
        QuitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        QuestionButton->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Log X", 0));
        label_2->setText(QApplication::translate("MainWindow", " software", 0));
        PictureLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
