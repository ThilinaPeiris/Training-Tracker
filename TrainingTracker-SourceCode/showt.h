#ifndef SHOWT_H
#define SHOWT_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>

namespace Ui {
class showt;
}

class showt : public QDialog
{
    Q_OBJECT

public:
    explicit showt(QWidget *parent = 0);
    ~showt();

private:
    Ui::showt *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // SHOWT_H
