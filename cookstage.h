#ifndef COOKSTAGE_H
#define COOKSTAGE_H

#include <QDialog>

namespace Ui {
class cookStage;
}

class cookStage : public QDialog
{
    Q_OBJECT

public:
    explicit cookStage(QWidget *parent = nullptr);
    ~cookStage();

private:
    Ui::cookStage *ui;
};

#endif // COOKSTAGE_H
