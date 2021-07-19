#ifndef MANAGERSTAGE_H
#define MANAGERSTAGE_H

#include <QDialog>

namespace Ui {
class managerStage;
}

class managerStage : public QDialog
{
    Q_OBJECT

public:
    explicit managerStage(QWidget *parent = nullptr);
    ~managerStage();

private slots:
    void on_pushButton_5_clicked();

    void on_newTableButton_clicked();

    void on_getCheckButton_clicked();

    void on_clockInButton_clicked();

    void on_closeTabButton_clicked();

    void on_managerFunctionsButton_clicked();

    void on_clockOutButton_clicked();

private:
    Ui::managerStage *ui;
};

#endif // MANAGERSTAGE_H
