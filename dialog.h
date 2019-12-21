#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QTableWidget >
#include <QtSql>
#include<QtDebug>
#include<QFileDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include "ui_dialog.h"
#include"emprunt.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

private:
    emprunt* Emprunt_Window;

public:
    QSqlDatabase DB_emprunt;
    QSqlDatabase DB_Livre ;
    QSqlDatabase DB_user;

    bool ConOpen_DB_emprunt(){
        DB_emprunt=QSqlDatabase::addDatabase("QSQLITE");
        DB_emprunt.setDatabaseName("C:/Users/LENOVO/Documents/gestion_livres/empunt.sqlite");
        if (DB_emprunt.open()){
        return(true);
        }
        else
        {
            return(false);}
    }


    void ConClose_DB_emprunt()
    {
        DB_emprunt.close();
        DB_emprunt.removeDatabase(QSqlDatabase::defaultConnection);
    }

    void ConClose_DB_user()
    {
        DB_user.close();
        DB_user.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool ConOpen_DB_user(){
        DB_user=QSqlDatabase::addDatabase("QSQLITE");
        DB_user.setDatabaseName("C:/Users/LENOVO/Documents/gestion_livres/user.sqlite");
        if (DB_user.open()){
            ui->label_db_user->setText("connected");
        return(true);
        }
        else
        {
            ui->label_db_user->setText("not connected");
            return(false);}
    }

    void ConClose_DB_Livre()
    {
        DB_Livre.close();
        DB_Livre.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool ConOpen_DB_Livre(){
        DB_Livre=QSqlDatabase::addDatabase("QSQLITE");
        DB_Livre.setDatabaseName("C:/Users/ahmed guetat/Desktop/gestion_livres/livre.sqlite");
        if (DB_Livre.open()){
            ui->label_database->setText("connected");
        return(true);
        }
        else
        {
            ui->label_database->setText("not connected");
            return(false);}
    }
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public:void on_pushbutton_refrech_clicked();

private slots:


    void on_delete_2_clicked();

    void on_save_clicked();

    void on_update_clicked();


    void on_pushButton_clicked();


    void on_pushButton_enregistrer_user_clicked();

    void on_pushButton_modif_user_clicked();

    void on_pushButton_supp_user_clicked();

    void on_pushbutton_refrech_user_clicked();

    void on_pushButton_2_clicked();

    void on_afficher_clicked();

    void on_push_rendre_clicked();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
