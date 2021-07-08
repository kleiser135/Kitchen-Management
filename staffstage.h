#ifndef STAFFSTAGE_H
#define STAFFSTAGE_H

#include <QDialog>

namespace Ui {
class staffStage;
}

class staffStage : public QDialog
{
    Q_OBJECT

public:
    explicit staffStage(QWidget *parent = nullptr);
    ~staffStage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::staffStage *ui;
};

#endif // STAFFSTAGE_H
