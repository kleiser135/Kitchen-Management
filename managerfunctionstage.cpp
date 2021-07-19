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


void managerFunctionStage::on_menuEditsButton_clicked()
{
    //manager_functions(1);
}


void managerFunctionStage::on_trackOrderTimeButton_clicked()
{
    //manager_functions(7);
}


void managerFunctionStage::on_openTabButton_clicked()
{
    //manager_functions(2);
}


void managerFunctionStage::on_eightySixItemsButton_clicked()
{
    //manager_functions(5);
}


void managerFunctionStage::on_managerMessage_clicked()
{
    //manager_functions(9);
}


void managerFunctionStage::on_adjustCheckButton_clicked()
{
    //manager_functions(6);
}


void managerFunctionStage::on_pastChecksButton_clicked()
{
    //manager_functions(3);
}


void managerFunctionStage::on_orderInventory_clicked()
{
    //manager_functions(8);
}


void managerFunctionStage::on_trackInventoryButton_clicked()
{
    //manager_functions(4);
}


void managerFunctionStage::on_compsAndDiscountsButton_clicked()
{
    //manager_functions(10);
}

