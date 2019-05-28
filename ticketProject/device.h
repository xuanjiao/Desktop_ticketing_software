#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>
#include <stdio.h>
#include <QDebug>
#include <stdlib.h>
#include <sys/types.h>


#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>

#include "person.h"

class Device
{
public:
    Device();
    bool init(QString portName,QSerialPort port);
    void close();
    QString readData();
};


#endif // DEVICE_H
