#include "staffstage.h"
#include "ui_staffstage.h"

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
