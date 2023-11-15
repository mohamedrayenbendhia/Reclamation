#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "greclamation.h"
#include <QMessageBox>
#include "connection.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    greclamation * a=new greclamation;
   this->hide();
   QString username=ui->username->text();
   QString password=ui->password->text();
    QSqlQuery qry;
   qry.prepare("select * from client where username='"+username+"' and password='"+password+"' ");

  if (!qry.exec())
  {

QMessageBox::critical(this,"failed","failed excuting the sql query");
 }
else if(!qry.first())

{
      QMessageBox::warning(this,"erreur","Username and password are not valid");
      this->show();
  }
      else{a->show();}
}
