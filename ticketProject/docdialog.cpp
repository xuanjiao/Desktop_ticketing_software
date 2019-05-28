#include "docdialog.h"
#include "ui_docdialog.h"

DocDialog::DocDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DocDialog)
{
    ui->setupUi(this);
}

DocDialog::~DocDialog()
{
    delete ui;
}

void DocDialog::on_listWidget_activated(const QModelIndex &index)
{
    QFile file0(":/document/doc/connect_to_database.txt");
    QFile file1(":/document/doc/connect_to_provided_database.txt");
    QFile file2(":/document/doc/connect_remote_database.txt");
    QFile file3(":/document/doc/connect_to_new_database.txt");
    QFile file4(":/document/doc/connect_to_serial_port.txt");
    QFile file5(":/document/doc/add_new_user.txt");
    QFile file6(":/document/doc/remove_user.txt");
    switch(index.row()) {
    case 0:
        if(!file0.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,"Error","open help document failed","OK");
        }else{
            QTextStream in0(&file0);
            ui->textBrowser->setText(in0.readAll());
        }
       break;
    case 1:
        if(!file1.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,"Error","open help document failed","OK");
        }else{
            QTextStream in1(&file1);
            ui->textBrowser->setText(in1.readAll());
        }
       break;
     case 2:

        if(!file2.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,"Error","open help document failed","OK");
        }else{
            QTextStream in2(&file2);
            ui->textBrowser->setText(in2.readAll());
        }
        break;
    case 3:

        if(!file3.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,"Error","open help document failed","OK");
        }else{
            QTextStream in3(&file3);
            ui->textBrowser->setText(in3.readAll());
        }
       break;
    case 4:
        if(!file4.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,"Error","open help document failed","OK");
        }else{
            QTextStream in4(&file4);
            ui->textBrowser->setText(in4.readAll());
        }
       break;
    case 5:
        if(!file5.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,"Error","open help document failed","OK");
        }else{
            QTextStream in5(&file5);
            ui->textBrowser->setText(in5.readAll());
        }
      break;
   case 6:
        if(!file6.open(QIODevice::ReadOnly)){
            QMessageBox::warning(this,"Error","open help document failed","OK");
        }else{
            QTextStream in6(&file6);
            ui->textBrowser->setText(in6.readAll());
        }
        break;
    }
}

void DocDialog::on_QuitButton_clicked()
{
    this->close();
}
