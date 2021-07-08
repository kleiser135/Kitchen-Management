#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include "managerstage.h" //manager menu stage
//#include "cookstage.h" //cook menu stage
//#include "staffstage.h" //staff menu stage

#include <QMessageBox> //need this in order to use error boxes, the form is QMessageBox::warning(this, "Name of error box", "Message within error box");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString pin = ui->lineEditPin->text(); //store the string that the user enters in the "enter PIN box"

    if(pin == "cook") //compare PIN with default values
    {
        //open cooks menu
        //cookStage cookMenu;
        hide();
        cookstage=new cookStage(this);
        cookstage->show();
        //cookMenu.setModal(true);
        //cookMenu.exec();

    }
    else if(pin == "server")
    {
        //opens server menu
        //staffStage serverMenu;
        hide();
        staffstage=new staffStage(this);
        staffstage->show();
        //serverMenu.setModal(true);
        //serverMenu.exec();

    }
    else if(pin == "manager")
    {
        //opens manager menu
        //managerStage managerMenu;
        hide();
        managerstage=new managerStage(this);
        managerstage->show();
        //managerMenu.setModal(true);
        //managerMenu.exec();
    }
    else
    {
        QMessageBox::warning(this, "Login Error", "Invalid pin, Please enter a valid pin."); //prints error message if the pin is wrong
    }
}

