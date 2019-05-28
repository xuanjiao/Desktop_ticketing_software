#include "serialportsettingdialog.h"
#include "ui_serialportsettingdialog.h"

SerialPortSettingDialog::SerialPortSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialPortSettingDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Serial port setting");
}

SerialPortSettingDialog::~SerialPortSettingDialog()
{
    delete ui;
}

/* when show available port button is clicked, the system run this function
 * show port options will be shown in the port combobox
 * baudrate options will be shown in the baudrate combobox
 */
void SerialPortSettingDialog::on_PortButton_clicked()
{
    ui->PortComboBox->clear();
    const QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
    for(int i = 0;i<list.size();i++){
        ui->PortComboBox->addItem(list[i].portName());
    }
    ui->BaudComboBox->clear();
    ui->BaudComboBox->addItem("1200");
    ui->BaudComboBox->addItem("2400");
    ui->BaudComboBox->addItem("4800");
    ui->BaudComboBox->addItem("9600");
    ui->BaudComboBox->addItem("19200");
    ui->BaudComboBox->addItem("38400");
    ui->BaudComboBox->addItem("57600");
    ui->BaudComboBox->addItem("115200");
}

/* when OK button is clicked, the system run this function
 * it get port name and baudrate from comboboxes
 * it calls serial port initialization function
 * if initialization succeed, close the serialport setting window
 */
void SerialPortSettingDialog::on_OKButton_clicked()
{
    QString portName = ui->PortComboBox->currentText();
    qint32 baudRate = this->getBaudRate();
    if(this->serialPortInit(portName,baudRate)){  
        this->close();
    }
}

/*
 * initialize serial port with given boudrate and port name
 * if succeed, reuturn true and pop success message
 * if failed, return false and pop error message
 */
bool SerialPortSettingDialog::serialPortInit(QString portName,qint32 baudRate){

   MainWindow* p = (MainWindow*) parentWidget();
    qDebug()<<"serial port init start";
    // close the serial port
    if(p->port.isOpen()){
        qDebug()<<"port was open, now close";
        p->port.close();
    }

    // if the port name or baudrate is not valid, end initialize and return false
    bool flag = false;
    if(portName.isEmpty()){
        qDebug()<<"port name is empty\n";
        QMessageBox::warning(this,"Warning","Please choose a port","OK");
        return flag;
    }
    if(baudRate == QSerialPort::UnknownBaud){
        qDebug()<<"baudrate is unknown";
        QMessageBox::warning(this,"Warning","Please choose a baudrate","OK");
    }

    // if the port name and baudrate is valid, configure the serial communication
    p->port.setPortName(portName);
    p->port.setBaudRate(baudRate);
    p->port.setDataBits(QSerialPort::Data8);
    p->port.setParity(QSerialPort::NoParity);
    p->port.setStopBits(QSerialPort::OneStop);
    p->port.setFlowControl(QSerialPort::NoFlowControl);

    // open the port, if error occurs, pop the error message
    if(p->port.open(QSerialPort::ReadWrite)){
        flag = true;
        qDebug()<<"serial port init finished,port name is "<<portName;
        //p->sendSignalToDevice("1");
        p->isSerialportSettingFinish = 1;
        QString success = QString("connected to port [").append(portName).append("] !");
        QMessageBox::information(this,"succeess",success);
    }else{
        QString error= "Port open error: ";
        error.append(p->port.errorString());
        error.append("\nPlease restart the application and reconnect the device");
        qDebug()<<error;
        QMessageBox::warning(this,"Error",error,"OK");
    }
    return flag;
}

/* get chosen baudrate from baudrate combobox
 */
qint32 SerialPortSettingDialog::getBaudRate(){
    qint32 baudrate = 0;
    QString baud_str = ui->BaudComboBox->currentText();
    if(baud_str == "1200")
        baudrate = QSerialPort::Baud1200;
    else if(baud_str == "2400")
        baudrate = QSerialPort::Baud2400;
    else if(baud_str == "4800")
        baudrate = QSerialPort::Baud4800;
    else if(baud_str == "9600")
        baudrate = QSerialPort::Baud9600;
    else if(baud_str == "19200")
        baudrate = QSerialPort::Baud19200;
    else if(baud_str == "38400")
        baudrate = QSerialPort::Baud38400;
    else if(baud_str == "57600")
        baudrate = QSerialPort::Baud57600;
    else if(baud_str == "115200")
        baudrate = QSerialPort::Baud115200;
    else
        baudrate = QSerialPort::UnknownBaud;
    return baudrate;
}

void SerialPortSettingDialog::on_CancelButton_clicked()
{
    this->close();
}
