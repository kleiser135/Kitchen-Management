#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "managerstage.h" //manager menu stage
#include "cookstage.h" //cook menu stage
#include "staffstage.h" //staff menu stage
#include "managerfunctionstage.h" //manager function menu stage

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    cookStage *cookstage;
    managerFunctionStage *managerfunctionstage;
    managerStage *managerstage;
    staffStage *staffstage;
};
#endif // MAINWINDOW_H
