#include "cookstage.h"
#include "ui_cookstage.h"

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
