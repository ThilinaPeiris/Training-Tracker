#ifndef NTRAINING_H
#define NTRAINING_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>

namespace Ui {
class ntraining;
}

class ntraining : public QDialog
{
    Q_OBJECT

public:
    explicit ntraining(QWidget *parent = 0);
    ~ntraining();

private slots:
    void on_pushButton_tsave_clicked();

private:
    Ui::ntraining *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // NTRAINING_H
