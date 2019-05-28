#ifndef USER_H
#define USER_H
#include <iostream>
#include <QString>

#define NAME_SIZE 20

class User
{
private:
    QString RFID;
    QString name;
    int period;
    bool payment;
public:
    User();
    User(QString RFID, QString name, int period,bool payment);
    QString getRFID();
    QString getName();
    int getPeriod();
    bool getPayment();
    QString getInfo();
    void setRFID(QString RFID);
    void setName(QString name);
    void setPeriod(int period);
    void setPayment(bool payment);
};


#endif // USER_H
