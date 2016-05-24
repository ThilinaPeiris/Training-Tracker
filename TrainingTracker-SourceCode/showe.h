#ifndef SHOWE_H
#define SHOWE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>

namespace Ui {
class showe;
}

class showe : public QDialog
{
    Q_OBJECT

public:
    explicit showe(QWidget *parent = 0);
    ~showe();

private:
    Ui::showe *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // SHOWE_H
