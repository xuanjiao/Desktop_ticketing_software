#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MSG_SIZE 64

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowIcon(QIcon(QStringLiteral(":/logo/logo/winIcon.ico")));
    this->running = 1;
    ui->setupUi(this);
    this->isDatabaseSettingFinish = false;
    this->isSerialportSettingFinish = false;
    this->loadImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_QuestionButton_clicked()
{
    DocDialog *docDialog = new DocDialog();
    docDialog->show();
}

/* when user setting button is clicked, it open user setting dialog
 */
void MainWindow::on_UserSettingButtton_clicked()
{
    if(this->isDatabaseSettingFinish == false){
        QMessageBox::warning(this,"error","please set up database by clicking [show database setting] button");
    }else if(this->isSerialportSettingFinish == false){
        QMessageBox::warning(this,"error","please set up serial port by clicking [serial port setting] button");
    }else{
        disconnect(&this->port, SIGNAL(readyRead()), this, SLOT(readRFID()));
        UserSettingDialog *userSettingDialog = new UserSettingDialog(this);
        userSettingDialog->show();
    }
}

/*
 * the application send start signal to device. the device start sending RFID
 *  start receiving RFID from device
 */
void MainWindow::on_StartButton_clicked()
{
    if(this->isDatabaseSettingFinish == false){
         QMessageBox::warning(this,"error","please set up database by clicking [show database setting] button");
    }else if(this->isSerialportSettingFinish == false){
        QMessageBox::warning(this,"error","please set up serial port by clicking [serial port setting] button");
    }else{
             this->sendSignalToDevice(START_SIGNAL);
             connect(&this->port, SIGNAL(readyRead()), this, SLOT(readRFID()));
    }
}

void MainWindow::on_StopButton_clicked()
{
    this->stopDevice();
    disconnect(&this->port, SIGNAL(readyRead()), this, SLOT(readRFID()));
}

void MainWindow::on_SerialButton_clicked()
{
    SerialPortSettingDialog *serialPortSettingDialog = new SerialPortSettingDialog(this);
    serialPortSettingDialog->show();
}


void MainWindow::on_QuitButton_clicked()
{
    this->running = false;
    this->closeAll();
}

// load logo picture to the GUI window
void MainWindow::loadImage(){
   ui->PictureLabel->setScaledContents(true);
   QPixmap pix (200,200);
   pix.load(":/logo/logo/logo.png");
   pix.scaled(Qt::KeepAspectRatio,Qt::FastTransformation);
   ui->PictureLabel->setPixmap(pix);
}


/*
 * get database setting that stored in database setting object
 * set the database driver, host name, database name, user name, password and port according to the database to be connected
 * connect to the database, if failed pop a warning message
 */
bool MainWindow::connectToDatabase(){
    bool connect = false;

    db = QSqlDatabase::addDatabase("QMYSQL");
    QString hostName = this->databaseSetting.getHostName();
    QString databaseName = this->databaseSetting.getDatabaseName();
    int portName = this->databaseSetting.getPortName().toInt();
    QString userName = this->databaseSetting.getUserName();
    QString password = this->databaseSetting.getPassword();
   // qDebug()<<"host name: "<<hostName<<",database name: "<<databaseName<<",port name:"<<portName<<"user name: "<<userName<<"password: "<<password;

    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setPort(portName);
    db.setUserName(userName);
    db.setPassword(password);


    if(db.open()){
       // qDebug()<<"connected to database!";
        connect = true;
    }else{
        qDebug()<<"database open error: "<< db.lastError();
         qDebug()<<"host name: "<<db.hostName()<<",database name: "<<db.databaseName()<<",port name:"<<db.hostName()<<"user name: "<<db.userName()<<"password: "<<db.password();
    }
    return connect;
}

/*
 * query given RFID in database
 * if RFID exist in database, return ture and store the user information in incomming user object
 * if RFID not exist in database, return false
 */
bool MainWindow::searchUserInDatabase(QString RFID,User &user){

        bool flag = false;
        QString name;
        int period = 0;
        bool payment = false;
        QString search ="SELECT * FROM mydb.tickets WHERE RFID = :RFID ";
        QSqlQuery qry;
        qry.prepare(search);
        qry.bindValue(":RFID",RFID);
        if(qry.exec()){
            while(qry.next()){
              flag = true;
              name = qry.value(0).toString();
              period = qry.value(2).toInt();
              payment = qry.value(3).toBool();
              user.setRFID(RFID);
              user.setName(name);
              user.setPeriod(period);
              user.setPayment(payment);
              qDebug()<<"find user:"<< name <<"rows effected"<<qry.numRowsAffected();
            }
        }else{
            QString error = qry.lastError().text();
            QMessageBox::warning(this,"Error",error,"OK");
            qDebug()<<"error text"<<error;
        }
    return flag;
}

/* call this function if disconnect to the database
 * send stop signal to device and make it stop sending data
 */
void MainWindow::stopDevice(){
    this->sendSignalToDevice(STOP_SIGNAL);
    qDebug()<<"stop device!";
}


/*
 * send signal to device from the serial port.
 * If succeed, return 1. if failed, return 0
 */
bool MainWindow::sendSignalToDevice(QString signal){
    bool flag= false;
    QByteArray sendData = signal.toLatin1();
    if( this->port.write(sendData) == -1){
        QString error = "send signal to device failed ";
        error.append(this->port.errorString());
        QMessageBox::warning(this,"Error",error,"OK");
    }else{
        flag = true;
    }
    return flag;
}

/* whenever data arrive at serial port, the signal ReadyRead will be generated. The system will call this slot function automaticlly.
 * it read RFID form device
 * connect database and query RFID
 * if RFID is not exist in database, clear TestEdits of RFID, name, period and payment
 */
void MainWindow::readRFID(){
    static QByteArray allData;
    QByteArray dataTemp =this->port.readAll();
    if( dataTemp.data()[dataTemp.length() - 1] != '\n'){
        qDebug()<<"read "<<dataTemp<<" not finish";
        allData += dataTemp;
    }else{
        allData += dataTemp;
        allData.resize(allData.size() - 2);
        qCritical() << allData;
        qDebug()<<"read "<< allData.size() <<" bytes new RFID: "<<allData;
        QString RFID = allData;
        allData.clear();
        if( connectToDatabase() == true ){
                User user;
                    if( this->searchUserInDatabase(RFID,user)){

                         // found matching user information in database
                         qDebug()<<"find user in database";
                        this->displayUserInfo(user);
                    }else{

                        // not found matching user information in database
                         this->clearTextEdits();
                         qDebug()<<"RFID = "<< RFID << ", No RFID information in database";
                    }

        }else{

            //disconnected to database
            QString warning ="Connecting to database failed. Error type: ";
            warning.append(db.lastError().text());
            warning.append("\nPlease reconnect the database");
            QMessageBox::warning(this,"Error",warning,"OK");
            this->stopDevice();
            if(this->running == true){
                this->stopRunning();
            }
        }
    }

}

void MainWindow::displayUserInfo(User user){
    ui->RFIDText->setText(user.getRFID());
    ui->NameText->setText(user.getName());
    ui->PeriodText->setText(QString::number(user.getPeriod()));
    ui->PaymentText->setText(QString::number(user.getPayment()));
    qDebug()<<user.getInfo();
}

void::MainWindow::clearTextEdits(){
    ui->NameText->clear();
    ui->RFIDText->clear();
    ui->PeriodText->clear();
    ui->PaymentText->clear();
}

void MainWindow::closeAll(){
    this->running = false;
    disconnect(&this->port, SIGNAL(readyRead()), this, SLOT(readRFID()));
    this->port.close();
    this->db.close();
    this->close();
}

void MainWindow::stopRunning(){
    this->clearTextEdits();
    this->port.close();
    this->db.close();
    this->running = false;
    qDebug()<<"stop running!";

}

void MainWindow::on_DatabaseButton_clicked()
{
     DatabaseDialog *databasedialog =  new DatabaseDialog(this);
    databasedialog->show();
}

DatabaseSetting MainWindow::getDatabaseSetting(){
    return this->databaseSetting;
}

QSqlDatabase MainWindow::getDatabase(){
    return this->db;

}


