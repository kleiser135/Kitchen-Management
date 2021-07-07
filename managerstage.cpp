#include "managerstage.h"
#include "managerfunctionstage.h"
#include "ui_managerstage.h"

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

void managerStage::on_pushButton_clicked()
{
    managerFunctionStage managerFunctionMenu;
    hide();
    managerFunctionMenu.setModal(true);
    managerFunctionMenu.exec();
}

