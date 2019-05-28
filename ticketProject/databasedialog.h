#ifndef DATABASEDIALOG_H
#define DATABASEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QMainWindow>
#include <QSettings>
#include <QProcess>

#include "databasesetting.h"
#include "mainwindow.h"
#include "user.h"

namespace Ui {
class DatabaseDialog;
}

class DatabaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseDialog(QWidget *parent = 0);
    ~DatabaseDialog();
    bool setUpDatabase(QString hostName,QString databaseName, QString portName, QString userName, QString password);
    void loadLastSetting();
    DatabaseSetting getDatabaseSetting();

private slots:
    void on_OKButton_clicked();
    void on_SkipButton_clicked();

private:
    Ui::DatabaseDialog *ui;
};

#endif // DATABASEDIALOG_H
