#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    }
    else if(pin == "server")
    {
        //opens server menu
    }
    else if(pin == "manager")
    {
        //opens manager menu
    }
    else
    {
        QMessageBox::warning(this, "Login Error", "Invalid pin, Please enter a valid pin."); //prints error message if the pin is wrong
    }
}

