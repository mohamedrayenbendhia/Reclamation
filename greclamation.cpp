#include "greclamation.h"
#include "ui_greclamation.h"
#include <QMessageBox>
#include "reclamation.h"
#include "mainwindow.h"
#include "smtp.h"
greclamation::greclamation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::greclamation)
{
    ui->setupUi(this);
        ui->comboBox_2->setModel(tmprec.comboR());
        ui->tablereclamation->setModel(tmprec.afficher());
}

greclamation::~greclamation()
{
    delete ui;
}

void greclamation::on_pushButton_12_clicked()
{
    int idr = ui->lineEdit_12->text().toUInt();
    QString nomr = ui->lineEdit_13->text();
    QString prenomr = ui->lineEdit_14->text();
    QString emailr = ui->lineEdit_15->text();
    QString sujetr = ui->lineEdit_16->text();
    QString messager = ui->textEdit->toPlainText();
    reclamation rec(idr,nomr,prenomr,emailr,sujetr,messager,"not treated");
    bool test=rec.ajouter();
    if (test)
    {
           QMessageBox::information(this,"succès","reclamation a été ajoutée avec succés ");
           ui->comboBox_2->setModel(tmprec.comboR());
           ui->tablereclamation->setModel(tmprec.afficher());
    }
    else{
         QMessageBox::critical(this,"failed",".............");
    }
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->textEdit->setText("");


}

void greclamation::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString id=ui->comboBox_2->currentText();

    QSqlQuery qry;


    qry.prepare("select SUJET,MESSAGE from RECLAMATION where ID='"+id+"'");
    if(qry.exec())

    {

        while(qry.next())
        {

             ui->lineEdit_21->setText(qry.value(0).toString());
              ui->textEdit_2->setText(qry.value(1).toString());

        }
    }
}



void greclamation::on_pushButton_9_clicked()
{
    QString id = ui->comboBox_2->currentText();

    QString sujet = ui->lineEdit_21->text();
    QString message = ui->textEdit_2->toPlainText();
    bool test=tmprec.modifier(id,sujet,message);

    if(test)

{


        QMessageBox::information(this,"succès","reclalmation a été modifié avec succés ");
        ui->comboBox_2->setModel(tmprec.comboR());
        ui->tablereclamation->setModel(tmprec.afficher());
    }

    else
    {
        QMessageBox::critical(this,"echec ","reclalmation n a pas été modifié ");

    }

ui->lineEdit_21->setText("");
 ui->textEdit_2->setText("");
}

void greclamation::on_pushButton_10_clicked()
{
    QString id = ui->comboBox_2->currentText();
    bool test=tmprec.supprimer(id);
    if(test)
 {
        QMessageBox::information(this,"succès","reclamation a été supprimée avec succés ");
        ui->comboBox_2->setModel(tmprec.comboR());
        ui->tablereclamation->setModel(tmprec.afficher());

    }

    else
    {QMessageBox::critical(this,"echec ","reclamation n a pas été supprimée ");}

    }


void greclamation::on_pushButton_5_clicked()
{
    QString id = ui->lineEdit_r->text();
     ui->tableView_r->setModel(tmprec.rechercher(id));
}

void greclamation::on_pushButton_14_clicked()
{
     ui->tablereclamation->setModel(tmprec.afficherAscnom());
}

void greclamation::on_pushButton_15_clicked()
{
    ui->tablereclamation->setModel(tmprec.afficherdescnom());

}

void greclamation::on_pushButton_16_clicked()
{
    ui->tablereclamation->setModel(tmprec.afficherAscID());

}

void greclamation::on_pushButton_17_clicked()
{
    ui->tablereclamation->setModel(tmprec.afficherdescID());

}

void greclamation::on_pushButton_18_clicked()
{
    ui->tablereclamation->setModel(tmprec.afficher());

}

void greclamation::on_pushButton_7_clicked()
{
    MainWindow * a=new MainWindow;
   this->hide();
    a->show();
}

void greclamation::on_pushButton_19_clicked()
{
    MainWindow * a=new MainWindow;
   this->hide();
    a->show();
}

void greclamation::on_pushButton_11_clicked()
{
    MainWindow * a=new MainWindow;
   this->hide();
    a->show();
}

void greclamation::on_pushButton_13_clicked()
{
    MainWindow * a=new MainWindow;
   this->hide();
    a->show();
}

void greclamation::on_pushButton_20_clicked()
{
    QString uname="mohamedrayen.bendhia@esprit.tn";
        QString passwd="221JMT3794";
        QString server="smtp.gmail.com";
        QString port="465";
        Smtp* smtp = new Smtp(uname,passwd,server,port.toUShort());
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


        smtp->sendMail(uname, "medrayen.bendhia@gmail.com" , "mail object","contenu du mail");
    }







