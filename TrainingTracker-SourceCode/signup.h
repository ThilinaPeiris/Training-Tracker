#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include "signin.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();

private slots:
    void on_pushButton_S_SignUp_clicked();

private:
    Ui::SignUp *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // SIGNUP_H
