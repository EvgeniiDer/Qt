#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "calculatorLineEdit/calculatorLineEdit.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "CallButton/calculatorbutton.h"
#include <QGroupBox>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* lblResult;
    //QHBoxLayout* hLayout;
    QVBoxLayout* mainLayout;
    QWidget* centralWgt;
    CalculatorLineEdit* lnEdit;
    void setStyle(QWidget& wgt);
    CalculatorButton* buttons;
    QGridLayout* grdLayout;


};
#endif // MAINWINDOW_H
