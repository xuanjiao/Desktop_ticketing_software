#include "databasedialog.h"
#include "ui_databasedialog.h"


DatabaseDialog::DatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Database setting");
    this->loadLastSetting();

}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}

/* set up user's database
 * store setting in file system,
 * this setting can be invoked when the user open the application next time
 * if the application connected to database, it pop success message and quit the database dialog
*/
void DatabaseDialog::on_OKButton_clicked()
{
    MainWindow* p = (MainWindow*) parentWidget();
    qDebug()<<p->isDatabaseSettingFinish;
    QString hostName = ui->HostNameEdit->text();
    QString databaseName = ui->DatabaseNameEdit->text();
    QString portName = ui->PortEdit->text();
    QString userName = ui->UserNameEdit->text();
    QString password = ui->PasswordEdit->text();

    if(this->setUpDatabase(hostName, databaseName, portName, userName, password)){
       qDebug()<<"test edit:"<<hostName<<databaseName<<portName<<password;
       qDebug()<<"setting database finish";

     QSettings settings("database setting");
     settings.setValue("database/hostName",hostName);
     settings.setValue("database/databaseName",databaseName);
     settings.setValue("database/portName",portName);
     settings.setValue("database/userName",userName);
     settings.setValue("database/password",password);

    }else{
         qDebug()<<"setting database failed";
    }


    if(p->connectToDatabase()){
        qDebug()<<"setting database succeed";
        QString success = QString("connected to database [").append(databaseName).append("] !");
        QMessageBox::information(this,"succeess",success);
        p->isDatabaseSettingFinish = true;
        this->close();
    }else{
            if(p->running){
                p->stopRunning();
            }
            QString error ="Connecting to database failed. Error type: ";
            error.append(p->getDatabase().lastError().text());
            error.append("\nPlease reconnect the database");
            QMessageBox::warning(this,"Error",error,"OK");
    }
}

void DatabaseDialog::on_SkipButton_clicked()
{
    qDebug()<<"skip database setting , start disconnect mode";
    this->close();
}

/*
 *  invoke the database setting that user used last time
 */
void DatabaseDialog::loadLastSetting(){
    QSettings settings("database setting");
    QString hostName = settings.value("database/hostName").toString();
    QString databaseName = settings.value("database/databaseName").toString();
    QString portName = settings.value("database/portName").toString();
    QString userName = settings.value("database/userName").toString();
    QString password = settings.value("database/password").toString();

    ui->HostNameEdit->setText(hostName);
    ui->DatabaseNameEdit->setText(databaseName);
    ui->PortEdit->setText(portName);
    ui->UserNameEdit->setText(userName);
    ui->PasswordEdit->setText(password);

}

/* read user's database setting from line edits
 * store setting in databse setting object (which is a member variable of mainwindow)
 * if one element is empty return false
 * if every elements has a value, return true
 */
bool DatabaseDialog::setUpDatabase(QString hostName,QString databaseName, QString portName, QString userName, QString password){
    bool flag = true;
    MainWindow* p = (MainWindow*) parentWidget();
    DatabaseSetting set;

    if(!hostName.isEmpty()){
        set.setHostName(hostName);
    }else{
        QMessageBox::warning(this,"","please enter a host name","OK");
        flag = false;
        return flag;
    }

    if(!databaseName.isEmpty()){

       set.setDatabaseName(databaseName);
    }else{
        QMessageBox::warning(this,"","please enter a database name","OK");
        flag = false;
        return flag;
    }

    if(!portName.isEmpty()){

        set.setPortName(portName);
    }else{
        QMessageBox::warning(this,"","please enter a port","OK");
        flag = false;
        return flag;
    }

    if(!userName.isEmpty()){
        set.setUserName(userName);
    }else{
        QMessageBox::warning(this,"","please enter a user name","OK");
        flag = false;
        return flag;
    }

    if(!password.isEmpty()){
        set.setPassport(password);
    }else{
        QMessageBox::warning(this,"","please enter a password","OK");
        flag = false;
        return flag;
    }
    set.showInfo();

     p->databaseSetting = set;
    return flag;
}



