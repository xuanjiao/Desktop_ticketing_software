#ifndef SERIALPORTSETTINGDIALOG_H
#define SERIALPORTSETTINGDIALOG_H

#include <QSerialPort>
#include <QSerialPortInfo>

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class SerialPortSettingDialog;
}

class SerialPortSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortSettingDialog(QWidget *parent = 0);
    ~SerialPortSettingDialog();
    qint32 getBaudRate();
    bool serialPortInit(QString portName,qint32 baudRate);
private slots:
    void on_PortButton_clicked();
    void on_OKButton_clicked();
    void on_CancelButton_clicked();

private:
    Ui::SerialPortSettingDialog *ui;
};

#endif // SERIALPORTSETTINGDIALOG_H
