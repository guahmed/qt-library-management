#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{


    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_pass->text();

    if (username=="user" && password=="user"){
        QMessageBox::information(this ,"login","username and password correct");
        hide();
        seconddialog = new Dialog(this);
        seconddialog->exec();

    }else
        QMessageBox::warning(this,"login","user name or password incorrect");




}
