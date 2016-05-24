#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include "mainwindow.h"
#include "signup.h"
#include <QtSql>
#include <QtDebug>

namespace Ui {
class SignIn;
}

class SignIn : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = 0);
    ~SignIn();

private slots:
    void on_PushButton_SignIn_clicked();
    void on_pushButton_SignUp_clicked();

private:
    Ui::SignIn *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // SIGNIN_H
