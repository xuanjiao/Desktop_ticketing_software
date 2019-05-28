#include "databasesetting.h"

DatabaseSetting::DatabaseSetting()
{
}

void DatabaseSetting::setHostName(QString hostName){
    this->hostName = hostName;
}

void DatabaseSetting::setDatabaseName(QString databaseName){
    this->databaseName = databaseName;
}

void DatabaseSetting::setPortName(QString portName){
    this->portName = portName;
}

void DatabaseSetting::setUserName(QString userName){
    this->userName = userName;
}

void DatabaseSetting::setPassport(QString password){
    this->password = password;
}

QString DatabaseSetting::getHostName(){
    return this->hostName;
}

QString DatabaseSetting::getDatabaseName(){
    return this->databaseName;
}

QString DatabaseSetting::getPortName(){
    return this->portName;
}

QString DatabaseSetting::getUserName(){
    return this->userName;
}

QString DatabaseSetting::getPassword(){
    return this->password;
}

void DatabaseSetting::showInfo(){
    qDebug()<<this->getHostName()<<this->getDatabaseName()<<this->getPortName()<<this->getUserName()<<this->getPassword();
}

