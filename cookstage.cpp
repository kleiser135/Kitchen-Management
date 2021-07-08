#include "cookstage.h"
#include "ui_cookstage.h"

#include "mainwindow.h"

MainWindow *mainpointer;

cookStage::cookStage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cookStage)
{
    ui->setupUi(this);
}

cookStage::~cookStage()
{
    delete ui;
}

void cookStage::on_pushButton_clicked()
{
    hide();
    mainpointer=new MainWindow(this);
    mainpointer->show();
}

