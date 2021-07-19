#include "staffstage.h"
#include "ui_staffstage.h"
#include "popupwindow.h"
#include "clockoutpopup.h"
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


void staffStage::on_clockOutButton_clicked() //Clock Out
{
    clockOutPopUp clockoutPopup;
    clockoutPopup.setModal(true);
    //server_menu();
    clockoutPopup.exec();
    hide();
    mainpointer2 = new MainWindow(this);
    mainpointer2->show();
}


void staffStage::on_clockInButton_clicked() //Clock In
{
    popUpWindow popUpWindow;
    popUpWindow.setModal(true);
    //server_menu();
    popUpWindow.exec();
}

