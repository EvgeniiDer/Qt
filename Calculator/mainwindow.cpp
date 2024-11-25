#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300, 400);
    centralWgt = new QWidget();
    setStyle(*centralWgt);
    this->setCentralWidget(centralWgt);

    this->setWindowTitle("Calculator");

    lnEdit = new CalculatorLineEidt();

    vLayout = new QVBoxLayout(centralWgt);
    vLayout->addWidget(lnEdit);
    centralWgt->setLayout(vLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStyle(QWidget& wgt)
{
    wgt.setStyleSheet("QWidget {"
                      "border: none;" // Удаление рамки
                      "background-color: #000000;" // Цвет фона
                      //"color: #000000;" // Цвет текста
                      "padding: 5px;" // Отступы
                      //"border-radius: 15px;" // Закругление углов
                      "}"
                      );
}
