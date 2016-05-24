#ifndef NEMPLOYEE_H
#define NEMPLOYEE_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include <QMessageBox>

namespace Ui {
class nemployee;
}

class nemployee : public QDialog
{
    Q_OBJECT

public:
    explicit nemployee(QWidget *parent = 0);
    ~nemployee();

private slots:
    void on_pushButton_esave_clicked();

private:
    Ui::nemployee *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // NEMPLOYEE_H
