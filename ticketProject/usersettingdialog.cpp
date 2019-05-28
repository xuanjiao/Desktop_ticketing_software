#include "usersettingdialog.h"
#include "ui_usersettingdialog.h"


UserSettingDialog::UserSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSettingDialog)
{
    MainWindow* p = (MainWindow*) parentWidget();
    ui->setupUi(this);
    disconnect(&p->port, SIGNAL(readyRead()), p, SLOT(readRFID()));
    this->setWindowTitle("User Setting");
    initTable();

}

bool UserSettingDialog::initTable(){
    bool flag = false;
    this->model.setTable("tickets");
    if(this->model.select())
        flag=1;
    ui->tableView->setModel(&model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    qDebug()<<"model row count"<<(model.rowCount());
    return flag;
}


UserSettingDialog::~UserSettingDialog()
{
    delete ui;
}

void UserSettingDialog::on_RemoveButton_clicked()
{
    this->removeUserFromTable();
}

//requist new RFID from device
void UserSettingDialog::on_AddButton_clicked()
{
    MainWindow* p = (MainWindow*) parentWidget();
    connect(&p->port, SIGNAL(readyRead()), this, SLOT(readNewRFID()));
    p->sendSignalToDevice(GENERATE_SIGNAL);

}

void UserSettingDialog::on_QuitButton_clicked()
{
    MainWindow* p = (MainWindow*) parentWidget();
    disconnect(&p->port, SIGNAL(readyRead()), this, SLOT(readNewRFID()));
    qDebug()<<"close user setting dialog";
    this->close();
}
// read Name, period, payment infomation from Edits
bool UserSettingDialog::getUserFromEdits(User& user){
    QString name;
    int period;
    bool payment,ok;

    name= ui->NameText->text();
    if(name.isEmpty()){
        QMessageBox::warning(this,"Error","please enter a name","OK");
        return false;
    }

    period = ui->PeriodText->text().toInt(&ok,10);
    if(!ok || period < 0){
        QMessageBox::warning(this,"Error","the period should be a positive integer","OK");
        return false;
    }

    payment = ui->PaymentText->text().toInt(&ok,2);
    if(!ok){
        if(payment != 0 && payment != 1){
        }
        QMessageBox::warning(this,"Error","the payment should be 0 or 1","OK");
        return false;
    }

    qDebug()<<"name ="<<name;
    qDebug()<<"period = "<<period;
    qDebug()<<"payment = "<<payment;

    user.setName(name);
    user.setPayment(payment);
    user.setPeriod(period);
    return true;
}

/* whenever data arrive at serial port, the signal ReadyRead will be generated. The system will call this slot function automaticlly.
 * it read RFID that the device generated
 * if the RFID exist in database, request RFID again
 * if RFID not exist in database, disconnect the signal and slot. Stop receive data from device set it as user's RFID. Store user's information in database
 */
void UserSettingDialog::readNewRFID(){
    qDebug()<<"readNewRFID begin";

    MainWindow *p = (MainWindow*) parentWidget();
    static QByteArray allData;
    QByteArray dataTemp =p->port.readAll();
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
        if( this->searchRFIDinDatabase(RFID)){
              qDebug()<<"RFID exist in database";
              p->sendSignalToDevice("2");
        }else{
         qDebug()<<"RFID = "<<RFID << ", No RFID information in database";
         User user;
         if(this->getUserFromEdits(user)){
             user.setRFID(RFID);
             this->addUser(user);
             disconnect(&p->port, SIGNAL(readyRead()), this, SLOT(readNewRFID()));
         }
        }
    }


}

/* make a query to search RFID in the database
 * if the RFID exist in database, return true
 * if the RFID is not exist in database, return false
 */
bool UserSettingDialog::searchRFIDinDatabase(QString RFID){
    bool flag = false;
    QString search ="SELECT * FROM mydb.tickets WHERE RFID = :RFID ";
    QSqlQuery qry;
    qry.prepare(search);
    qry.bindValue(":RFID",RFID);
    if(qry.exec()){
        while(qry.next()){
          flag = 1;
          qDebug()<<"find RFID: "<< RFID;
        }
    }else{
        qDebug()<<"RFID not exist:"<<RFID;
    }
    return flag;
}


// remove user from sql table mode and submit the changes

bool UserSettingDialog::removeUserFromTable(){
    bool flag = false;
    if(model.removeRow(ui->tableView->currentIndex().row())){
        model.select();
        qDebug()<<"remove user success!";
        flag = true;
        QMessageBox::information(this,"Success","Remove user succeed","OK");
    }else{
        QMessageBox::warning(this,"Error","Remove user failed!","OK");
    }
    return flag;
}

// insert a user information in database
bool UserSettingDialog::addUser(User user){
    bool flag = false;         
    QString search = "INSERT INTO `mydb`.`tickets` (`RFID`, `name`, `period`, `payment`) VALUES (:RFID, :name, :period, :payment)";
    QSqlQuery qry;
    qry.prepare(search);
    qry.bindValue(":RFID",user.getRFID());
    qry.bindValue(":name",user.getName());
    qry.bindValue(":period",user.getPeriod());
    qry.bindValue(":payment",user.getPayment());
    if(qry.exec()){
        flag = true;
         QMessageBox::information(this,"Success","add user succeed","OK");
         model.select();
    }else{
        QString error = qry.lastError().text();
        QMessageBox::warning(this,"Error",error,"OK");
        qDebug()<<"error text"<<error;
    }
    return flag;
}


