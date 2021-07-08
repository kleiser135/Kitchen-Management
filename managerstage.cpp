#include "managerstage.h"
#include "ui_managerstage.h"

#include "mainwindow.h"

MainWindow *mainpointer3;

managerStage::managerStage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerStage)
{
    ui->setupUi(this);
}

managerStage::~managerStage()
{
    delete ui;
}

void managerStage::on_pushButton_clicked() //button to open manager stage menu
{
    managerFunctionStage *managerfunctionstage1;
    hide();
    managerfunctionstage1=new managerFunctionStage(this);
    managerfunctionstage1->show();
    //managerFunctionMenu.setModal(true);
    //managerFunctionMenu.exec();
}


void managerStage::on_pushButton_5_clicked() //back button to main menu
{
    hide();
    mainpointer3=new MainWindow(this);
    mainpointer3->show();
}

