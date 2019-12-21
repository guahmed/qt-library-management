#include "emprunt.h"
#include "ui_emprunt.h"
#include"dialog.h"
emprunt::emprunt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emprunt)
{
    ui->setupUi(this);

}


emprunt::~emprunt()
{
    delete ui;
}

void emprunt::on_pushButton_refrech_clicked()
{

    ConOpen_DB_Livre();
    ConOpen_DB_user();

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select livre_titre from livre");
    query->exec();
    modal->setQuery(*query);
    ui->comboBox_livre->setModel(modal);


    QSqlQueryModel * modal1=new QSqlQueryModel();
    QSqlQuery *query1=new QSqlQuery();
    query->prepare("select nom from user");
    query->exec();
    modal->setQuery(*query1);
    ui->comboBox_emprunteur->setModel(modal1);
    ConClose_DB_user();
    ConClose_DB_Livre();


}
