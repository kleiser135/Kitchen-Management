#include "cookstage.h"
#include "ui_cookstage.h"
#include "popupwindow.h"
#include "clockoutpopup.h"
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


void cookStage::on_trackOrderTimeButton_pressed()
{
    //call track order time
}


void cookStage::on_clockOutButton_clicked() //Clock Out
{
    clockOutPopUp clockoutPopup;
    clockoutPopup.setModal(true);
    //cook_menu();
    clockoutPopup.exec();
    hide();
    mainpointer = new MainWindow(this);
    mainpointer->show();

}


void cookStage::on_clockInButton_clicked() //Clock In
{
    popUpWindow popUpWindow;
    popUpWindow.setModal(true);
    //cook_menu();
    popUpWindow.exec();
}


void cookStage::on_getCheckTime_clicked() //Get Check
{

}


void cookStage::on_trackOrderTimeButton_clicked() //Track Order Time
{

}

