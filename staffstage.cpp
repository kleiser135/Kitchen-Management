#include "staffstage.h"
#include "ui_staffstage.h"

#include "mainwindow.h"

MainWindow *mainpointer2;

staffStage::staffStage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffStage)
{
    ui->setupUi(this);
}

staffStage::~staffStage()
{
    delete ui;
}

void staffStage::on_pushButton_clicked()
{
    hide();
    mainpointer2=new MainWindow(this);
    mainpointer2->show();
}

