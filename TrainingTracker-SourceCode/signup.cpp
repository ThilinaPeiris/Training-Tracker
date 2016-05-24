#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_S_SignUp_clicked()
{
    //update useraccounts table and open signin window

    QString username = ui->lineEdit_S_UserName->text();
    QString password = ui->lineEdit_S_Password->text();
    QString m_email = ui->lineEdit_S_Email->text();


    path = QDir::currentPath() + "\\TrainingTracker.sqlite";

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
       //qDebug() << "Error: connection with database fail";
       //Implement Error Handleling
    }
    else
    {
       //qDebug() << "Database: connection ok";
        QSqlQuery qry;
        qry.prepare("insert into users(name,password,email) values ('" +username+ "','" +password+"','"+m_email+"')");
        if(qry.exec())
        {   
            m_db.close();
            m_db = QSqlDatabase();
            m_db.removeDatabase(QSqlDatabase::defaultConnection);

            QMessageBox::information(this,tr("save"),tr("<font color='black'><b>User Account Created.</b></font>"));

            this->hide();
            MainWindow mainwindow;
            mainwindow.setModal(true);
            mainwindow.exec();

        }else
        {
            //username and password doesn't match.
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
            //statusBar()->showMessage("Invalid Username or Password! Try Again!");
        }
    }
}
