#include "showe.h"
#include "ui_showe.h"

showe::showe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showe)
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

        qry->prepare("SELECT e.eid,e.name,e.did,e.email FROM emp e ORDER BY e.eid");

        qry->exec();
        modal->setQuery(*qry);
        ui->tableView_showe->setModel(modal);

        //qDebug() << (modal->rowCount());
        m_db.close();
        m_db = QSqlDatabase();
        m_db.removeDatabase(QSqlDatabase::defaultConnection);
    }
}

showe::~showe()
{
    delete ui;
}
