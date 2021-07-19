#ifndef CLOCKOUTPOPUP_H
#define CLOCKOUTPOPUP_H

#include <QDialog>

namespace Ui {
class clockOutPopUp;
}

class clockOutPopUp : public QDialog
{
    Q_OBJECT

public:
    explicit clockOutPopUp(QWidget *parent = nullptr);
    ~clockOutPopUp();

private slots:
    void on_acceptButton_clicked();

private:
    Ui::clockOutPopUp *ui;
};

#endif // CLOCKOUTPOPUP_H
