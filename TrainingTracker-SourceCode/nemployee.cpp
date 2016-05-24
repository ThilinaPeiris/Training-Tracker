#include "nemployee.h"
#include "ui_nemployee.h"

nemployee::nemployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nemployee)
{
    ui->setupUi(this);
}

nemployee::~nemployee()
{
    delete ui;
}

void nemployee::on_pushButton_esave_clicked()
{
    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    QString ename = ui->lineEdit_ename->text();
    QString edid = ui->lineEdit_edid->text();
    QString eemail = ui->lineEdit_eemail->text();

    if (!m_db.open())
    {
       //qDebug() << "Error: connection with database fail";
       //Error Handle
    }
    else
    {
       //qDebug() << "Database: connection ok";
        QSqlQuery qry;
        qry.prepare("INSERT INTO emp(name,did,email) VALUES ('" +ename+ "','" +edid+"','"+eemail+"')");
        if(qry.exec())
        {
            m_db.close();
            m_db = QSqlDatabase();
            m_db.removeDatabase(QSqlDatabase::defaultConnection);

            QMessageBox::information(this,tr("save"),tr("<font color='black'><b>Employee details added.</b></font>"));

            this->hide();

        }else
        {
            //username and password doesn't match.
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
            //statusBar()->showMessage("Invalid Username or Password! Try Again!");
        }
    }
}
