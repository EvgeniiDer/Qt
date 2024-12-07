#include "mainwindow.h"
#include "./ui_mainwindow.h"
/*
 Что нужно доделалть!!
1. Прописать логику для Калькулятора(или польская нотация или Лексического анализа) +
2. Дописать QLabel для отражения результата                                         +
3. Если будет вермя изменить расположение кнопок в ручную
4. Не работают дробные числа
5
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
    lblResult = new CalLabel("Result", centralWgt);
    lnEdit = new CalculatorLineEdit();
    //Подключаем сигнал из CalcualatorLineEdit к слоту MainWindow
    connect(lnEdit, &CalculatorLineEdit::equalsPressed, this, &MainWindow::updateLabel);

    mainLayout->addWidget(lnEdit);
    mainLayout->addWidget(lblResult);
    grdLayout = new QGridLayout(this);


    grdLayout->setSpacing(1);



    QStringList buttonLabels[5] = {
        {"<-","AC", "-/+", "/"},
        {"7", "8", "9", "*"},
        {"4", "5", "6", "/"},
        {"1", "2", "3", "+"},
        {"pr", "0", ".", "="}
    };
    CalculatorButton* buttons = nullptr;
    int row = 1; // Начинаем с первой строки
    int col = 0; // Начинаем с первого столбца
    for (int i = 0; i < 5; ++i) { // 5 строк
        for (int j = 0; j < 4; ++j)// 4 колонки
        {
            if (i == 0 && j < 3) { // Проверяем, есть ли кнопка в данной позиции
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, "#303030");
                connect(buttons, &CalculatorButton::clicked, this,[this,buttonLabels, i, j]()
                {
                    lnEdit->addInput(buttonLabels[i][j]);
                });
                grdLayout->addWidget(buttons, row, col); // Добавляем кнопку в сетку
                col++; // Переходим к следующему столбцу
            }else if(j == 3)
            {
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, "#CC9900");
                connect(buttons, &CalculatorButton::clicked, this, [this, buttonLabels, i, j]()
                        {
                    lnEdit->addInput(buttonLabels[i][j]);

                });

                grdLayout->addWidget(buttons, row, col); // Добавляем кнопку в сетку
                col++; // Переходим к следующему столбцу
            }
            else
            {
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, "#505050");
                connect(buttons, &CalculatorButton::clicked, this, [this, buttonLabels, i, j]()
                        {
                    lnEdit->addInput(buttonLabels[i][j]);
                        });
                connect(buttons, &QPushButton::pressed, this, [buttons]()
                        {
                            buttons->setProperty("isPressed", true);
                            buttons->update();
                        });
                connect(buttons, &QPushButton::released, this, [buttons]() {
                    buttons->setProperty("isPressed", false); // Сбрасываем состояние нажатия
                    buttons->update(); // Перерисовываем кнопку
                });
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
void MainWindow::updateLabel(const QString& result)
{
    lblResult->setText(lnEdit->text());
}
