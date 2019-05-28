#ifndef USERSETTINGDIALOG_H
#define USERSETTINGDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>

#include "user.h"
#include "mainwindow.h"

namespace Ui {
class UserSettingDialog;
}

class UserSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserSettingDialog(QWidget *parent = 0);
    ~UserSettingDialog();
    bool getUserFromEdits(User& user);
    bool addUser(User user);
    bool removeUserFromTable();
    bool searchRFIDinDatabase(QString RFID);
    bool initTable();

private slots:
    void on_AddButton_clicked();
    void on_QuitButton_clicked();
    void readNewRFID();
    void on_RemoveButton_clicked();

private:
    Ui::UserSettingDialog *ui;
    QSqlTableModel model;
    bool getRFID;
};

#endif // USERSETTINGDIALOG_H
