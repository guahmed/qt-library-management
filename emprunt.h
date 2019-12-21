#ifndef EMPRUNT_H
#define EMPRUNT_H

#include <QDialog>
#include <QSqlDatabase>
#include<QtSql>
#include<QMessageBox>



namespace Ui {
class emprunt;
}

class emprunt : public QDialog
{
    Q_OBJECT

public:
    explicit emprunt(QWidget *parent = nullptr);
    ~emprunt();

private:
    Ui::emprunt *ui;

public:
    QSqlDatabase DB_Livre ;
    QSqlDatabase DB_user;
    void ConClose_DB_user()
    {
        DB_user.close();
        DB_user.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool ConOpen_DB_user(){
        DB_user=QSqlDatabase::addDatabase("QSQLITE");
        DB_user.setDatabaseName("C:/Users/LENOVO/Documents/gestion_livres/user.sqlite");
        if (!DB_user.open()){
            QMessageBox::critical(this,tr("error"),"error");
            return(false);}
        else return true;
    }

    void ConClose_DB_Livre()
    {
        DB_Livre.close();
        DB_Livre.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool ConOpen_DB_Livre(){
        DB_Livre=QSqlDatabase::addDatabase("QSQLITE");
        DB_Livre.setDatabaseName("C:/Users/LENOVO/Documents/gestion_livres/livre.sqlite");
        if (!DB_Livre.open()){
            QMessageBox::critical(this,tr("error"),"error");
            return(false);}
        else return true;
    }


private slots:
    void on_pushButton_refrech_clicked();
};

#endif // EMPRUNT_H
