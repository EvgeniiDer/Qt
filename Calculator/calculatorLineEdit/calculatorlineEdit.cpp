#include "calculatorLineEdit.h"

CalculatorLineEdit::CalculatorLineEdit(QWidget* parent)
{
    //validator = new ExpValidator();
    //this->setValidator(validator);
    this->setAlignment(Qt::AlignRight);
    this->setStyleSheet("QLineEdit {"
                        "border: none;" // Удаление рамки
                        "padding: 5px;" // Отступы
                        "border-radius: 15px;" // Закругление углов
                        "}");
    QFont fnt("Arial", 30, QFont::Normal);
    this->setFont(fnt);
    QPalette plt = this->palette();
    plt.setColor(QPalette::Base, QColor(Qt::black));
    plt.setColor(QPalette::Text, QColor(Qt::lightGray));
    this->setPalette(plt);
    this->setPlaceholderText("Enter number");

}
void CalculatorLineEdit::keyPressEvent(QKeyEvent* event)
{
    if (this->text().length() >= 9 &&
        !(event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete)) {
        event->ignore();
        return;
    }
    QString inputChar = event->text();
    if (inputChar.length() == 1 &&
        (inputChar[0].isDigit() ||
         inputChar[0] == '+' ||
         inputChar[0] == '-' ||
         inputChar[0] == '*' ||
         inputChar[0] == '/' /*||
         inputChar[0] == '='*/))
    {
        if(this->text().isEmpty() && (inputChar[0] == '+' || inputChar[0] == '-' ||
                                      inputChar[0] == '/' || inputChar[0] == '*' /*||
                                      inputChar[0] == '='*/))
        {
            event->ignore();
            return;
        }
        if(!this->text().isEmpty())
        {
            QChar lastChar = this->text().back();
            if((lastChar == '+' || lastChar == '-' ||
                lastChar == '*' || lastChar == '/' /*||
                lastChar == '='*/)
                &&
                (inputChar[0] == '+' || inputChar[0] == '-'||
                 inputChar[0] == '*' || inputChar[0] == '/'/*||
                 inputChar[0] == '='*/))
                {
                event->ignore();
                return;
                }
        }
        this->setText(this->text() + inputChar);
        this->setCursorPosition(this->text().length());
    } else if(event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete)
        {
        if(!this->text().isEmpty())
            {
                this->setText(this->text().chopped(1));
                this->setCursorPosition(this->text().length());
            }
        }
    else {
        event->ignore();
    }
}



