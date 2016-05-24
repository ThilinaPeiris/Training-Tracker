#include "showt.h"
#include "ui_showt.h"

showt::showt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showt)
{
    ui->setupUi(this);

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

        qry->prepare("SELECT t.tid,t.name,t.details FROM training t ORDER BY t.tid");

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_showt->setModel(modal);

        //qDebug() << (modal->rowCount());
        m_db.close();
        m_db = QSqlDatabase();
        m_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

showt::~showt()
{
    delete ui;
}
