#ifndef ETEDIT_H
#define ETEDIT_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QDateEdit>
#include <QMessageBox>

namespace Ui {
class etedit;
}

class etedit : public QDialog
{
    Q_OBJECT

public:
    explicit etedit(QWidget *parent = 0);
    ~etedit();

private slots:
    void on_pushButton_et_save_clicked();

private:
    Ui::etedit *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // ETEDIT_H
