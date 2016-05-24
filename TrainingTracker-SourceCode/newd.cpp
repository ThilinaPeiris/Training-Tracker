#include "newd.h"
#include "ui_newd.h"

newd::newd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newd)
{
    ui->setupUi(this);
}

newd::~newd()
{
    delete ui;
}

void newd::on_pushButton_n_next_clicked()
{
    if(ui->radioButton_nemployee->isChecked())
    {
        this->hide();
        nemployee neobj;
        neobj.setModal(true);
        neobj.exec();

    }else if(ui->radioButton_ntraining->isChecked())
    {
        this->hide();
        ntraining ntobj;
        ntobj.setModal(true);
        ntobj.exec();
    }
}
