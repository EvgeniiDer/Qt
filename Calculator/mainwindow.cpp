#include "mainwindow.h"
#include "./ui_mainwindow.h"
/*
 Что нужно доделалть!!
1. Прописать логику для Калькулятора(или польская нотация или при помощи Рекурсии)
2. Дописать QLabel для отражения результата
3. Если будет вермя изменить расположение кнопок в ручную
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300, 450);
    centralWgt = new QWidget();
    setStyle(*centralWgt);
    this->setCentralWidget(centralWgt);

    this->setWindowTitle("Calculator");
    mainLayout = new QVBoxLayout(centralWgt);
    lblResult = new QLabel("", centralWgt);
    lnEdit = new CalculatorLineEdit();
    mainLayout->addWidget(lnEdit);
    mainLayout->addWidget(lblResult);
    grdLayout = new QGridLayout(this);


    grdLayout->setSpacing(1);
    //grdLayout->setSt


    QStringList buttonLabels[5] = {
        {"<-","AC", "-/+", "/"},
        {"7", "8", "9", "*"},
        {"4", "5", "6", "-"},
        {"1", "2", "3", "+"},
        {"pr", "0", ".", "="}
    };

    int row = 1; // Начинаем с первой строки
    int col = 0; // Начинаем с первого столбца

    for (int i = 0; i < 5; ++i) { // 5 строк
        for (int j = 0; j < 4; ++j) { // 4 колонки
            if (i == 0 && j < 3) { // Проверяем, есть ли кнопка в данной позиции
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, "#303030");
                grdLayout->addWidget(buttons, row, col); // Добавляем кнопку в сетку
                col++; // Переходим к следующему столбцу
            }else if(j == 3)
            {
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, "#CC9900");
                grdLayout->addWidget(buttons, row, col); // Добавляем кнопку в сетку
                col++; // Переходим к следующему столбцу
            }
            else
            {
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, "#505050");
                grdLayout->addWidget(buttons, row, col); // Добавляем кнопку в сетку
                col++; // Переходим к следующему столбцу
            }

        }
        row++; // Переходим на следующую строку
        col = 0; // Сбрасываем столбец
    }


    mainLayout->addLayout(grdLayout);
    centralWgt->setLayout(mainLayout);
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
