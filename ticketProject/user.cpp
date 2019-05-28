#include "user.h"

User::User(){
    this->setRFID("0");
    this->setName("default");
    this->setPeriod(0);
    this->setPayment(0);
}

User::User(QString RFID, QString name, int period,bool payment){
    this->setRFID(RFID);
    this->setName(name);
    this->setPeriod(period);
    this->setPayment(payment);
}

QString User::getInfo(){
    QString str;
    QString period_str= QString::number(this->getPeriod(),32);
    QString payment_str= QString::number(this->getPayment(),32);
    str.append("RFID: ");
    str.append(this->getRFID());
    str.append("\nName: ");
    str.append(this->name);
    str.append("\nPeriod:");
    str.append(period_str);
    str.append("\nPayment:");
    str.append(payment_str);
    str.append("\n");
    return str;
}

QString User::getRFID(){
    return this->RFID;
}

QString User::getName(){
    return this->name;
}

int User::getPeriod(){
    return this->period;
}

bool User::getPayment(){
    return this->payment;
}

void User::setRFID(QString RFID){
    this->RFID = RFID;
}

void User::setName(QString name){
    this->name = name;
}

void User::setPeriod(int period){
    this->period = period;
}

void User::setPayment(bool payment){
    this->payment = payment;
}

