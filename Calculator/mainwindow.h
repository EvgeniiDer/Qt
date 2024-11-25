#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "calculatorLineEdit/calculatorLineEdit.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

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
    QLabel* mainLbl;
    QHBoxLayout* hLayout;
    QVBoxLayout* vLayout;
    QWidget* centralWgt;
    CalculatorLineEidt* lnEdit;
    void setStyle(QWidget& wgt);

};
#endif // MAINWINDOW_H
