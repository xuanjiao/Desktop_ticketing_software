#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QStyleFactory>

#include "user.h"
#include "databasedialog.h"
#include "databasesetting.h"
#include "usersettingdialog.h"
#include "serialportsettingdialog.h"
#include "docdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

#define STOP_SIGNAL "0"
#define START_SIGNAL "1"
#define GENERATE_SIGNAL "2"

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadImage();
    bool connectToDatabase();
    bool searchUserInDatabase(QString RFID,User &user);
    void displayUserInfo(User user);
    void clearTextEdits();
    void closeAll();
    void stopRunning();
    void stopDevice();
    void delay();
    bool sendSignalToDevice(QString signal);
    DatabaseSetting getDatabaseSetting();
    DatabaseSetting databaseSetting;
    QSqlDatabase getDatabase();
    bool isDatabaseSettingFinish;
    bool isSerialportSettingFinish;
    bool running;
    QSerialPort port;
    QSqlDatabase db;
private slots:
    void readRFID();
    void on_QuitButton_clicked();
    void on_DatabaseButton_clicked();
    void on_UserSettingButtton_clicked();
    void on_StartButton_clicked();
    void on_StopButton_clicked();
    void on_SerialButton_clicked();
    void on_QuestionButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
