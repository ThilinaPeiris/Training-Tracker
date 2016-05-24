#include "etedit.h"
#include "ui_etedit.h"

etedit::etedit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::etedit)
{
    ui->setupUi(this);

    QSqlQueryModel *modal1 = new QSqlQueryModel();
    QSqlQueryModel *modal2 = new QSqlQueryModel();

    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        //Database not open
        //Implement error handleling

    }else
    {
        //combobox ec

        QSqlQuery *qry = new QSqlQuery(m_db);

        //qry->prepare("SELECT e.eid,e.name,t.tid,t.name,et.status,et.s_date,et.e_date FROM emp e,training t,emp_train et WHERE e.eid = et.eid AND t.tid=et.tid ORDER BY e.eid");
        qry->prepare("SELECT eid FROM emp");

        qry->exec();
        modal1->setQuery(*qry);
        ui->comboBox_ec->setModel(modal1);

        //combobox tc

        QSqlQuery *qry1 = new QSqlQuery(m_db);

        qry1->prepare("SELECT tid FROM training");

        qry1->exec();
        modal2->setQuery(*qry1);
        ui->comboBox_tc->setModel(modal2);

        //qDebug() << (modal->rowCount());
        m_db.close();
        m_db = QSqlDatabase();
        m_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

etedit::~etedit()
{
    delete ui;
}

void etedit::on_pushButton_et_save_clicked()
{
    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    QString eid = ui->comboBox_ec->currentText();
    QString tid = ui->comboBox_tc->currentText();
    QString s_date = ui->dateEdit_sd->date().toString();
    QString e_date = ui->dateEdit_ed->date().toString();
    QString status = ui->lineEdit_status->text();

    if (!m_db.open())
    {
        //qDebug() << "Error: connection with database fail";
        //Error Handle
    }
    else
    {
        //qDebug() << "Database: connection ok";
        QSqlQuery qry;
        //qry.prepare("SELECT * FROM emp_train WHERE eid='" + eid + "' AND tid='" + tid + "'" );

        if(qry.exec("SELECT * FROM emp_train WHERE eid='" + eid + "' AND tid='" + tid + "'"))
        {
            int count = 0;
            while(qry.next())
            {
                count++;
            }

            if(count == 1)
            {

                qry.prepare("UPDATE emp_train SET s_date='" + s_date + "', e_date='" + e_date + "', status='" +status +"' WHERE eid='" + eid +"' AND tid='"+ tid + "'");
                if(qry.exec())
                {
                    m_db.close();
                    m_db = QSqlDatabase();
                    m_db.removeDatabase(QSqlDatabase::defaultConnection);

                    QMessageBox::information(this,tr("save"),tr("<font color='black'><b>Employee details updated.</b></font>"));

                    this->hide();
                }else
                {
                    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
                }
            }else
            {
                qry.prepare("INSERT INTO emp_train(eid,tid,s_date,e_date,status) VALUES ('" +eid+ "','" +tid+"','"+ s_date + "','" + e_date + "','" +status +"')");
                if(qry.exec())
                {
                    m_db.close();
                    m_db = QSqlDatabase();
                    m_db.removeDatabase(QSqlDatabase::defaultConnection);

                    QMessageBox::information(this,tr("save"),tr("<font color='black'><b>Employee details added.</b></font>"));

                    this->hide();

                }else
                {
                    QMessageBox::critical(this,tr("error::"),qry.lastError().text());
                }
            }

        }else
        {
            //username and password doesn't match.
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
            //statusBar()->showMessage("Invalid Username or Password! Try Again!");
        }
    }
}

