#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QDialog>

namespace Ui {
class popUpWindow;
}

class popUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit popUpWindow(QWidget *parent = nullptr);
    ~popUpWindow();

private slots:
    void on_acceptButton_clicked();

private:
    Ui::popUpWindow *ui;
};

#endif // POPUPWINDOW_H
