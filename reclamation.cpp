#include "reclamation.h"

reclamation::reclamation()
{
    id=0;
     nom="";
      prenom="";
     email="";
     sujet="";
     message="";
}
reclamation::reclamation(int id ,QString nom,QString prenom,QString email,QString sujet ,QString message,QString status)
{
    this->id=id;
     this->nom=nom;
      this->prenom=prenom;
     this->email=email;
     this->sujet=sujet;
     this->message=message;
    this->status = status;
}
bool reclamation::ajouter()
{
    QSqlQuery query;
    QString res1= QString::number(id);
    QString res2= nom;
    QString res3= prenom;
  QString res4= email;
    QString res5= sujet;
      QString res6= message;
      QString res7= status;

    query.prepare(" INSERT INTO RECLAMATION(ID,NOM,PRENOM,EMAIL,SUJET,MESSAGE,STATUS) VALUES (:ID,:NOM,:PRENOM,:EMAIL,:SUJET,:MESSAGE,:STATUS)" );

    query.bindValue(":ID" , res1);
    query.bindValue(":NOM", res2 );
    query.bindValue(":PRENOM", res3);
    query.bindValue(":EMAIL",res4);
    query.bindValue(":SUJET",res5);
    query.bindValue(":MESSAGE",res6);
   query.bindValue(":STATUS",res7);
    return   query.exec();

}

QSqlQueryModel * reclamation::comboR()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    QSqlQuery *modelquery = new QSqlQuery() ;

    modelquery->prepare("select ID from RECLAMATION ");
    modelquery->exec();
    model->setQuery(*modelquery);

        return model;
}

bool reclamation::modifier(QString idrec,QString sujet,QString message)
{
    QSqlQuery query;
    QString res0 = idrec;
    QString res1= sujet;
    QString res2= message;
    query.prepare("UPDATE RECLAMATION SET sujet='"+res1+"',message='"+res2+"' WHERE ID='"+res0+"'");

    return query.exec();
}

bool reclamation::supprimer(QString id)
{
QSqlQuery query;
QString res= id;
query.prepare("Delete from reclamation where ID ='"+res+"' ");
query.bindValue(":ID", res);
return    query.exec();
}


QSqlQueryModel * reclamation::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamation");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("sujet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("message"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("status"));
    return model;
}

QSqlQueryModel * reclamation::rechercher(QString idd)
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from reclamation where ID ='"+idd+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("sujet"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("message"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("status"));

        return model;
}
QSqlQueryModel * reclamation::afficherAscnom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamation ORDER BY nom ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("sujet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("message"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("status"));
    return model;
}
QSqlQueryModel * reclamation::afficherdescnom()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamation ORDER BY nom DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("sujet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("message"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("status"));
    return model;
}
QSqlQueryModel * reclamation::afficherAscID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamation ORDER BY ID ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("sujet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("message"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("status"));
    return model;
}
QSqlQueryModel * reclamation::afficherdescID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from reclamation ORDER BY ID DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("sujet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("message"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("status"));
    return model;
}


