#ifndef NEWD_H
#define NEWD_H

#include <QDialog>
#include "nemployee.h"
#include "ntraining.h"

namespace Ui {
class newd;
}

class newd : public QDialog
{
    Q_OBJECT

public:
    explicit newd(QWidget *parent = 0);
    ~newd();

private slots:
    void on_pushButton_n_next_clicked();

private:
    Ui::newd *ui;
};

#endif // NEWD_H
