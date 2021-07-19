#include "popupwindow.h"
#include "ui_popupwindow.h"

popUpWindow::popUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popUpWindow)
{
    ui->setupUi(this);
}

popUpWindow::~popUpWindow()
{
    delete ui;
}

void popUpWindow::on_acceptButton_clicked()
{
    popUpWindow::close();
}

