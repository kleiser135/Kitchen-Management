#ifndef MANAGERFUNCTIONSTAGE_H
#define MANAGERFUNCTIONSTAGE_H

#include <QDialog>

namespace Ui {
class managerFunctionStage;
}

class managerFunctionStage : public QDialog
{
    Q_OBJECT

public:
    explicit managerFunctionStage(QWidget *parent = nullptr);
    ~managerFunctionStage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_menuEditsButton_clicked();

    void on_trackOrderTimeButton_clicked();

    void on_openTabButton_clicked();

    void on_eightySixItemsButton_clicked();

    void on_managerMessage_clicked();

    void on_adjustCheckButton_clicked();

    void on_pastChecksButton_clicked();

    void on_orderInventory_clicked();

    void on_trackInventoryButton_clicked();

    void on_compsAndDiscountsButton_clicked();

private:
    Ui::managerFunctionStage *ui;
};

#endif // MANAGERFUNCTIONSTAGE_H
