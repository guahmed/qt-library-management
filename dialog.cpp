#include "dialog.h"
#include "ui_dialog.h"
#include<QTableWidget>
#include<QLabel>
#include<QMessageBox>
#include<QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    if (ConOpen_DB_Livre())
        ui->label_database->setText("connected");
    else
        ui->label_database->setText("not connected");


}

Dialog::~Dialog()
{
    delete ui;
}







void Dialog::on_delete_2_clicked()
{

    QString title_book,autor_name,id,qte;
    title_book=ui->lineEdit_livre->text();
    autor_name=ui->lineEdit_auteur->text();
    id=ui->lineEdit_id->text();
    qte=ui->lineEdit_qte->text();
    ConOpen_DB_Livre();

    QSqlQuery query;
    query.prepare("delete from livre where livre_id="+id+";" );
    if (query.exec()){
        QMessageBox::information(this,"save in database","deleted");
        ConClose_DB_Livre();
    }else
        QMessageBox::critical(this,tr("error"),query.lastError().text());


    ConClose_DB_Livre();
    on_pushButton_clicked();

}

void Dialog::on_save_clicked()
{

    QString title_book,autor_name,id,qte;
    title_book=ui->lineEdit_livre->text();
    autor_name=ui->lineEdit_auteur->text();
    id=ui->lineEdit_id->text();
    qte=ui->lineEdit_qte->text();
    ConOpen_DB_Livre();

    QSqlQuery query;
    query.prepare("insert into livre(livre_id ,livre_titre ,livre_auteur ,liv_Emprunteur) "
                  "values("+id+",'"+title_book+"','"+autor_name+"',"+qte+");");
    if (query.exec()){
        QMessageBox::information(this,"save in database","save in database");
        ConClose_DB_Livre();
    }else
        QMessageBox::critical(this,tr("error"),query.lastError().text());

    ConClose_DB_Livre();
    on_pushButton_clicked();
}

void Dialog::on_update_clicked()
{

    QString title_book,autor_name,id,qte;
    title_book=ui->lineEdit_livre->text();
    autor_name=ui->lineEdit_auteur->text();
    id=ui->lineEdit_id->text();
    qte=ui->lineEdit_qte->text();
    ConOpen_DB_Livre();

    QSqlQuery query;
    query.prepare("update livre set livre_id="+id+",livre_titre='"+title_book+"',livre_auteur='"+autor_name+"',liv_Emprunteur="+qte+" where livre_id="+id+" ;");
    if (query.exec()){
        QMessageBox::information(this,"save in database","update in database");
        ConClose_DB_Livre();
    }else

        QMessageBox::critical(this,tr("error"),query.lastError().text());


    ConClose_DB_Livre();
    on_pushButton_clicked();
    ui->lineEdit_qte->clear();
    ui->lineEdit_livre->clear();
    ui->lineEdit_auteur->clear();
    ui->lineEdit_id->clear();

    qDebug() << DB_Livre.hostName()<<endl;
     }

void Dialog::on_pushButton_clicked()
{

    ConOpen_DB_Livre();
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select livre_id,livre_titre,livre_auteur,liv_Emprunteur from livre");
    query->exec();
    modal->setQuery(*query);
    ui->tableView->setModel(modal);
    ConClose_DB_Livre();


    ConOpen_DB_Livre();

    QSqlQueryModel * modal1=new QSqlQueryModel();
    QSqlQuery *query1=new QSqlQuery;
    query1->prepare("select livre_titre from livre");
    query1->exec();
    modal1->setQuery(*query1);
    ui->comboBox_nom->setModel(modal1);

    ConClose_DB_Livre();


}


void Dialog::on_pushButton_enregistrer_user_clicked()
{
    QString user_name,user_second_name,id_user,qte_emprunt;
    user_name=ui->lineEdit_nom->text();
    user_second_name=ui->lineEdit_prenom->text();
    id_user=ui->lineEdit_id_user->text();
    qte_emprunt=ui->lineEdit_nbre->text();
    ConOpen_DB_user();

    QSqlQuery query;
    query.prepare("insert into user(user_id ,nom ,prenom ,nombre ) "
                  "values ("+id_user+",'"+user_name+"','"+user_second_name+"',"+qte_emprunt+");");
    if (query.exec()){
        QMessageBox::information(this,"save in database","save in database");
        ConClose_DB_Livre();
    }else
        QMessageBox::critical(this,tr("error"),query.lastError().text());

    ConClose_DB_user();
    on_pushbutton_refrech_clicked();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_id_user->clear();
    ui->lineEdit_nbre->clear();
    ui->lineEdit_nom->clear();
}

void Dialog::on_pushButton_modif_user_clicked()
{
    QString user_name,user_second_name,id_user,qte_emprunt;
    user_name=ui->lineEdit_nom->text();
    user_second_name=ui->lineEdit_prenom->text();
    id_user=ui->lineEdit_id_user->text();
    qte_emprunt=ui->lineEdit_nbre->text();
    ConOpen_DB_user();

    QSqlQuery query;
    query.prepare("update user set user_id="+id_user+",nom='"+user_name+"',prenom='"+user_second_name+"',nombre="+qte_emprunt+" where user_id="+user_name+" ;");
    if (query.exec()){
        QMessageBox::information(this,"save in database","save in database");
        ConClose_DB_Livre();
    }else
        QMessageBox::critical(this,tr("error"),query.lastError().text());

    ConClose_DB_user();
    on_pushbutton_refrech_clicked();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_id_user->clear();
    ui->lineEdit_nbre->clear();
    ui->lineEdit_nom->clear();

}

void Dialog::on_pushButton_supp_user_clicked()
{
    QString user_name,user_second_name,id_user,qte_emprunt;
    user_name=ui->lineEdit_nom->text();
    user_second_name=ui->lineEdit_prenom->text();
    id_user=ui->lineEdit_id_user->text();
    qte_emprunt=ui->lineEdit_nbre->text();
    ConOpen_DB_user();

    QSqlQuery query;
    query.prepare("delete from user where user_id ="+id_user+";" );
    if (query.exec()){
        QMessageBox::information(this,"save in database","deleted");
        ConClose_DB_Livre();
    }else
        QMessageBox::critical(this,tr("error"),query.lastError().text());


    ConClose_DB_user();
    on_pushbutton_refrech_clicked();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_id_user->clear();
    ui->lineEdit_nbre->clear();
    ui->lineEdit_nom->clear();

}

void Dialog::on_pushbutton_refrech_clicked()
{
    ConOpen_DB_user();
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select user_id ,nom ,prenom,nombre from user");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_user->setModel(modal);
    ConClose_DB_user();
}



void Dialog::on_pushbutton_refrech_user_clicked()
{
    ConOpen_DB_user();
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select user_id ,nom ,prenom,nombre from user");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_user->setModel(modal);
    ConClose_DB_user();

    ConOpen_DB_user();
    QSqlQueryModel * modal1=new QSqlQueryModel();
    QSqlQuery *query1=new QSqlQuery;
    query1->prepare("select nom from user");
    query1->exec();
    modal1->setQuery(*query1);
    ui->comboBox_user->setModel(modal1);
    ConClose_DB_user();




}


void Dialog::on_pushButton_2_clicked()
{
    // botton emprunter
    QString qte=ui->lineEdit_dem->text();
    QString name=ui->comboBox_nom->currentText();
    QString user_comb=ui->comboBox_user->currentText();
    ConOpen_DB_Livre();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select liv_Emprunteur from livre where livre_titre='"+name+"'");
    // query->exec();
    //if (query->value(1).toString()>q  te)
    query->exec();
    query->next();
    int qte_dispo = query->value(0).toInt();

    ConClose_DB_Livre();




     if (qte_dispo < qte.toInt()){
         QMessageBox::information(this,"qte","la quantité n est pas disponible");

     }else {
         int k=qte_dispo - qte.toInt();
         ConOpen_DB_Livre();

       QSqlQuery *query1=new QSqlQuery;
         query1->prepare("update livre set liv_Emprunteur="+(QString::number(k))+" where livre_titre='"+name+"'");
         query1->exec();
        ConClose_DB_Livre();

        ConOpen_DB_user();
        QSqlQuery *query2=new QSqlQuery;
        query2->prepare("update user set nombre = nombre +"+qte+" where nom='"+user_comb+"'");
        // query->exec();
        //if (query->value(1).toString()>q  te)
        query2->exec();
        ConClose_DB_user();

        ConOpen_DB_emprunt();
        QSqlQuery *query3=new QSqlQuery;
        query3->prepare("INSERT INTO emprunt(nom,livre_titre,qte) VALUES('"+user_comb+"','"+name+"',"+qte+")");
        // query->exec();
        //if (query->value(1).toString()>q  te)
        query3->exec();
        ConClose_DB_emprunt();



     }



        ConClose_DB_Livre();

}






void Dialog::on_afficher_clicked()
{

    ConOpen_DB_emprunt();

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select nom	,livre_titre ,qte from emprunt");
    query->exec();
    modal->setQuery(*query);
    ui->tableView_2->setModel(modal);

    ConClose_DB_emprunt();


}

void Dialog::on_push_rendre_clicked()
{
    QString nom_livre=ui->comboBox_nom->currentText();
    QString nom_user=ui->comboBox_user->currentText();



    ConOpen_DB_emprunt();
    QSqlQuery *query=new QSqlQuery;
    query->prepare("delete from emprunt where nom='"+nom_user+"' and livre_titre='"+nom_livre+"'");
    if (query->exec()){
    ConClose_DB_emprunt();

    ConOpen_DB_Livre();
    QSqlQuery *query1=new QSqlQuery;
    query1->prepare("update livre set liv_Emprunteur = liv_Emprunteur+1  where livre_titre='"+nom_livre+"'");
    query1->exec();
    ConClose_DB_Livre();


    ConOpen_DB_user();
    QSqlQuery *query2=new QSqlQuery;
    query2->prepare("update user set nombre=nombre+1 where nom='"+nom_user+"'");
    query2->exec();
    ConClose_DB_user();


    }




}
