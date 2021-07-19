#include "managerstage.h"
#include "ui_managerstage.h"
#include "popupwindow.h"
#include "mainwindow.h"
#include "clockoutpopup.h"

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

void managerStage::on_managerFunctionsButton_clicked() //button to open manager stage menu
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



void managerStage::on_newTableButton_clicked()
{
    //manager_menu(2);
}


void managerStage::on_getCheckButton_clicked()
{
    //manager_menu(4);
}


void managerStage::on_clockInButton_clicked()
{
    popUpWindow popUpWindow;
    popUpWindow.setModal(true);
    //manager_menu(1);
    popUpWindow.exec();

}


void managerStage::on_closeTabButton_clicked()
{
    //manager_menu(5);
}


void managerStage::on_clockOutButton_clicked()
{
    clockOutPopUp clockoutPopup;
    clockoutPopup.setModal(true);
    //manager_menu(6);
    clockoutPopup.exec();
    hide();
    mainpointer3 = new MainWindow(this);
    mainpointer3->show();

}

