#include "managerfunctionstage.h"
#include "ui_managerfunctionstage.h"

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
