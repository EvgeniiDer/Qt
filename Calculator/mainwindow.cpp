#include "mainwindow.h"
#include "./ui_mainwindow.h"
/*
 Что нужно доделалть!!
1. Реализовать кнопки '<-' и 'C';                                +
2. На экране калькулятора использовать кастомный шрифт;          +
3. При нажатии ПКМ на калькуляторе отобраить контекстное меню,
   из которого можно выбрать скин и шрифт экрана калькулятора;   +
4. При переключении скинов должен меняться цвет окна;            +
5. Изменить размер шрифта на экране
6. Добавлено максимальное доступное колличество шрифтов +
7. Сделать программу установки калькулятора в систему +
8. При выходе из калькулятора активная тема должна сохраняться(Реализовать Save Load)
9. Загружать присеты из библиотеке DLL
*/


constexpr int WINDOW_WIDTH = 300;
constexpr int WINDOW_HEIGHT = 450;

constexpr int WINDOW_XP = 800;
constexpr int WINDOW_YP = 300;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->move(WINDOW_XP, WINDOW_YP);
    centralWgt = new QWidget();
    this->setStyle(*centralWgt);
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

    contextMenuHandler = new ContextMenuHandler(this);
    grdLayout->setSpacing(1);
    //Настраиваем кнопки(в том числе по цвету)
    setupCalculatorButtons("#303030", "#CC9900", "#505050");


    mainLayout->addLayout(grdLayout);
    centralWgt->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QWidget* MainWindow::getCentralWgt()const
{
    return centralWgt;
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
void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton) { // Проверяем, нажата ли правая кнопка мыши
        contextMenuHandler->showContexMenu(event->globalPos()); // устанавливаем координаты контекстного выпадающего контектстного меню
    }
}

void MainWindow::setupCalculatorButtons(const QString& controlButtons, const QString& operationSymbols, const QString& numbers)
{


    QStringList buttonLabels[5] = {
        {"<-","AC", "-/+", "/"},
        {"7", "8", "9", "*"},
        {"4", "5", "6", "-"},
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
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, controlButtons);
                connect(buttons, &CalculatorButton::clicked, this,[this,buttonLabels, i, j]()
                        {
                            lnEdit->addInput(buttonLabels[i][j]);
                        });
                grdLayout->addWidget(buttons, row, col); // Добавляем кнопку в сетку
                col++; // Переходим к следующему столбцу
                //Добавляем кнопки <- AC -/+ первая строка до 3 столбика включительно
            }else if(j == 3)
            {
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, operationSymbols);
                connect(buttons, &CalculatorButton::clicked, this, [this, buttonLabels, i, j]()
                        {
                            lnEdit->addInput(buttonLabels[i][j]);

                        });

                grdLayout->addWidget(buttons, row, col); // Добавляем кнопку в сетку
                col++; // Переходим к следующему столбцу
                //Добавляем кнопки / * - + = в 4-й столбец каждой строки.
            }
            else
            {
                buttons = new CalculatorButton(buttonLabels[i][j], centralWgt, numbers);
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
                //Добавляем кнопки от 0 до 9 так же . pr
            }

        }
        row++; // Переходим на следующую строку
        col = 0; // Сбрасываем столбец
    }
}
