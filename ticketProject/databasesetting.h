#ifndef DATABASESETTING_H
#define DATABASESETTING_H
#include <QDebug>
#include <iostream>
#include <QString>


class DatabaseSetting
{
public:
    DatabaseSetting();
    void setHostName(QString hostName);
    void setDatabaseName(QString databaseName);
    void setUserName(QString userName);
    void setPortName(QString portName);
    void setPassport(QString password);
    QString getHostName();
    QString getDatabaseName();
    QString getPortName();
    QString getUserName();
    QString getPassword();
    void showInfo();
private:
    QString hostName;
    QString databaseName;
    QString userName;
    QString portName;
    QString password;
};

#endif // DATABASESETTING_H
