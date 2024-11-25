#include "calculatorLineEdit.h"

CalculatorLineEidt::CalculatorLineEidt(QWidget* parent)
{
    validator = new QDoubleValidator(0.0, 9999999999.9, 9);
    this->setValidator(validator);
    this->setAlignment(Qt::AlignRight);
    this->setStyleSheet("QLineEdit {"
                        "border: none;" // Удаление рамки
                        //"background-color: #e6e6e6;" // Цвет фона
                        //"color: #000000;" // Цвет текста
                        "padding: 5px;" // Отступы
                        "border-radius: 15px;" // Закругление углов
                        "}"
        );///Использование Каскадных таблиц
    QFont fnt("Arial", 40, QFont::Normal);
    this->setFont(fnt);
    QPalette plt = this->palette();
    plt.setColor(QPalette::Base, QColor(Qt::black));
    plt.setColor(QPalette::Text, QColor(Qt::lightGray));
    this->setPalette(plt);
    this->setPlaceholderText("Enter number");

}

void CalculatorLineEidt::keyPressEvent(QKeyEvent* event)
{
    QLineEdit::keyPressEvent(event);
    if(this->text().length() > 9)
    {
        this->setText(this->text().left(9));
    }

}
