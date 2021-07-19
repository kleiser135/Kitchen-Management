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

private slots:
    void on_pushButton_clicked();

    void on_trackOrderTimeButton_pressed();

    void on_clockOutButton_clicked();

    void on_clockInButton_clicked();

    void on_getCheckTime_clicked();

    void on_trackOrderTimeButton_clicked();

private:
    Ui::cookStage *ui;
};

#endif // COOKSTAGE_H
