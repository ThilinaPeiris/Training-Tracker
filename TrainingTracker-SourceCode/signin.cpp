#include "signin.h"
#include "ui_signin.h"

SignIn::SignIn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
    statusBar()->setStyleSheet("background: rgb(52, 152, 219);");
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_PushButton_SignIn_clicked()
{
    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    QString username = ui->LineEdit_UserName->text();
    QString password = ui->LineEdit_Password->text();

    if (!m_db.open())
    {
       //qDebug() << "Error: connection with database fail";
       //Error Handle
    }
    else
    {
       //qDebug() << "Database: connection ok";
        QSqlQuery qry;
        if(qry.exec("select * from users where name='" + username + "' and password='" + password +"'"))
        {
            int count = 0;
            while(qry.next())
            {
                count++;
            }

            if(count == 1)
            {
                m_db.close();
                m_db = QSqlDatabase();
                m_db.removeDatabase(QSqlDatabase::defaultConnection);
                this->hide();
                MainWindow mainwindow;
                mainwindow.setModal(true);
                mainwindow.exec();

            }else
            {
                //username and password doesn't match.
                statusBar()->showMessage("Invalid Username or Password! Try Again!");
            }

        }
    }

//    if(QString::compare(username, "Bhagy") == 0 && QString::compare(password, "123") == 0)
//    {
//        this->hide();
//        MainWindow mainwindow;
//        mainwindow.setModal(true);
//        mainwindow.exec();
//    }else
//    {
//        statusBar()->showMessage("Invalid Username or Password! Try Again!");
//    }
}

void SignIn::on_pushButton_SignUp_clicked()
{
    this->hide();
    SignUp signup;
    signup.setModal(true);
    signup.exec();
}
