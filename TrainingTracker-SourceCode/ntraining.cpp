#include "ntraining.h"
#include "ui_ntraining.h"

ntraining::ntraining(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ntraining)
{
    ui->setupUi(this);
}

ntraining::~ntraining()
{
    delete ui;
}

void ntraining::on_pushButton_tsave_clicked()
{
    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    QString tname = ui->lineEdit_tname->text();
    QString tdetails = ui->textEdit_tdetails->toPlainText();

    if (!m_db.open())
    {
       //qDebug() << "Error: connection with database fail";
       //Error Handle
    }
    else
    {
       //qDebug() << "Database: connection ok";
        QSqlQuery qry;
        //qry.prepare("INSERT INTO training(name,did,email) VALUES ('" +ename+ "','" +edid+"','"+eemail+"')");
        qry.prepare("INSERT INTO training(name,details) VALUES ('" + tname + "','" + tdetails + "')");
        if(qry.exec())
        {
            m_db.close();
            m_db = QSqlDatabase();
            m_db.removeDatabase(QSqlDatabase::defaultConnection);

            QMessageBox::information(this,tr("save"),tr("<font color='black'><b>Training details added.</b></font>"));

            this->hide();

        }else
        {
            //username and password doesn't match.
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
            //statusBar()->showMessage("Invalid Username or Password! Try Again!");
        }
    }
}
