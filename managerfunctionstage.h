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

private:
    Ui::managerFunctionStage *ui;
};

#endif // MANAGERFUNCTIONSTAGE_H
