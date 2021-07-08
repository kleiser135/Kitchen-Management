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
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::managerStage *ui;
};

#endif // MANAGERSTAGE_H
