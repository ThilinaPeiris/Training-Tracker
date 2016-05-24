#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include "newd.h"
#include "etedit.h"
#include "showe.h"
#include "showt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_new_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_showe_clicked();

    void on_pushButton_showt_clicked();

    void on_pushButton_sorte_clicked();

    void on_pushButton_sortt_clicked();

    void on_pushButton_refresh_clicked();

    void on_pushButton_help_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
    QString path;
};

#endif // MAINWINDOW_H
