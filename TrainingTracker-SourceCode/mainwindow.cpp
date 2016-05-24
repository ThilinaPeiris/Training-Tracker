#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlQueryModel *modal = new QSqlQueryModel();

    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        //Database not open
        //Implement error handleling

    }else
    {
        QSqlQuery *qry = new QSqlQuery(m_db);

        qry->prepare("SELECT e.eid,e.name,t.tid,t.name,et.status,et.s_date,et.e_date FROM emp e,training t,emp_train et WHERE e.eid = et.eid AND t.tid=et.tid ORDER BY e.eid");

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);

        //qDebug() << (modal->rowCount());
        m_db.close();
        m_db = QSqlDatabase();
        m_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_new_clicked()
{
    newd newdobj;
    newdobj.setModal(true);
    newdobj.exec();
}

void MainWindow::on_pushButton_edit_clicked()
{
    etedit eteditobj;
    eteditobj.setModal(true);
    eteditobj.exec();
}

void MainWindow::on_pushButton_exit_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_showe_clicked()
{
    showe showeobj;
    showeobj.setModal(true);
    showeobj.exec();
}

void MainWindow::on_pushButton_showt_clicked()
{
    showt showtobj;
    showtobj.setModal(true);
    showtobj.exec();
}

void MainWindow::on_pushButton_sorte_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        //Database not open
        //Implement error handleling

    }else
    {
        QSqlQuery *qry = new QSqlQuery(m_db);

        qry->prepare("SELECT e.eid,e.name,t.tid,t.name,et.status,et.s_date,et.e_date FROM emp e,training t,emp_train et WHERE e.eid = et.eid AND t.tid=et.tid ORDER BY e.eid");

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);

        //qDebug() << (modal->rowCount());
        m_db.close();
        m_db = QSqlDatabase();
        m_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

void MainWindow::on_pushButton_sortt_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        //Database not open
        //Implement error handleling

    }else
    {
        QSqlQuery *qry = new QSqlQuery(m_db);

        qry->prepare("SELECT e.eid,e.name,t.tid,t.name,et.status,et.s_date,et.e_date FROM emp e,training t,emp_train et WHERE e.eid = et.eid AND t.tid=et.tid ORDER BY t.tid");

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);

        //qDebug() << (modal->rowCount());
        m_db.close();
        m_db = QSqlDatabase();
        m_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

void MainWindow::on_pushButton_refresh_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    path = QDir::currentPath() + "\\TrainingTracker.sqlite";
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open())
    {
        //Database not open
        //Implement error handleling

    }else
    {
        QSqlQuery *qry = new QSqlQuery(m_db);

        qry->prepare("SELECT e.eid,e.name,t.tid,t.name,et.status,et.s_date,et.e_date FROM emp e,training t,emp_train et WHERE e.eid = et.eid AND t.tid=et.tid ORDER BY e.eid");

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);

        //qDebug() << (modal->rowCount());
        m_db.close();
        m_db = QSqlDatabase();
        m_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

void MainWindow::on_pushButton_help_clicked()
{
    QMessageBox::information(this,tr("save"),tr("<font color='black'><b>Please use README file located in Programfiles folder.</b></font>"));
}
