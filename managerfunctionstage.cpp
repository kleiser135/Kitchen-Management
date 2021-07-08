#include "managerfunctionstage.h"
#include "ui_managerfunctionstage.h"

//#include "managerstage.h"
#include "mainwindow.h"

managerStage *managerpointer;
MainWindow *mainpointer4;

managerFunctionStage::managerFunctionStage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerFunctionStage)
{
    ui->setupUi(this);
}

managerFunctionStage::~managerFunctionStage()
{
    delete ui;
}

void managerFunctionStage::on_pushButton_clicked() //back button to manager stage
{
    hide();
    managerpointer=new managerStage(this);
    managerpointer->show();
}


void managerFunctionStage::on_pushButton_2_clicked() //home button to main menu login screen
{
    hide();
    mainpointer4=new MainWindow(this);
    mainpointer4->show();
}

