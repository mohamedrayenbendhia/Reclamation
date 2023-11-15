#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class reclamation
{
public:
    reclamation();
    reclamation(int,QString,QString,QString,QString,QString,QString);
     int getId();
      QString getNom();
       QString getPrenom();
        QString getEmail();
         QString getSujet();
          QString getMessage();
            bool ajouter();
             QSqlQueryModel *comboR();
              bool modifier(QString,QString,QString);
              bool supprimer(QString);
              QSqlQueryModel *afficher();

              QSqlQueryModel *afficherAscnom();

              QSqlQueryModel *afficherdescnom();

              QSqlQueryModel *afficherAscID();

              QSqlQueryModel *afficherdescID();


              QSqlQueryModel *rechercher(QString);
private:
    int id;
    QString nom;
     QString prenom;
    QString email;
    QString sujet;
    QString message;
    QString status;
};

#endif // RECLAMATION_H
