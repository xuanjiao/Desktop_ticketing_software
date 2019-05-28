#ifndef DOCDIALOG_H
#define DOCDIALOG_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

namespace Ui {
class DocDialog;
}

class DocDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DocDialog(QWidget *parent = 0);
    ~DocDialog();

private slots:
    void on_listWidget_activated(const QModelIndex &index);

    void on_QuitButton_clicked();

private:
    Ui::DocDialog *ui;
};

#endif // DOCDIALOG_H
