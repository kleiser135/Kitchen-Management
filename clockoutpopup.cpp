#include "clockoutpopup.h"
#include "ui_clockoutpopup.h"

clockOutPopUp::clockOutPopUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clockOutPopUp)
{
    ui->setupUi(this);
}

clockOutPopUp::~clockOutPopUp()
{
    delete ui;
}

void clockOutPopUp::on_acceptButton_clicked()
{
    clockOutPopUp::close();
}
