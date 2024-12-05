#include "calculatorLineEdit.h"

CalculatorLineEdit::CalculatorLineEdit(QWidget* parent)
{
    //validator = new ExpValidator();
    //this->setValidator(validator);
    this->setFocus();
    equals = false;
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
void CalculatorLineEdit::addInput(const QString& inputChar)
{

    if(this->text().length() > 9)
    {
        return;
    }
    if (!this->text().isEmpty()) {
        QChar lastChar = this->text().back();
        if ((lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/' || lastChar == '=') &&
            (inputChar == "+" || inputChar == "-" || inputChar == "*" || inputChar == "/" || inputChar == '='))
        {
            qDebug() << "Error Repeating!!";
            return; // Игнорируем повторяющийся оператор
        }
    }
    else if(this->text().isEmpty())
        {
        if((inputChar == "+" || inputChar == "-" || inputChar == "*" || inputChar == "/" || inputChar == '='))
        {
            qDebug() << "Error: Cannot start with an operator";
            return;//Проверка выражения на вхождение первым Токеном арифметических операторов
        }
    }
    if(inputChar == "=")
    {
        if(!this->text().contains("*") &&
           !this->text().contains("/") &&
           !this->text().contains("+") &&
           !this->text().contains("-"))
        {
            qDebug() << "Erro: Ignore not operators";
            return;//Проверка на пристутсвите Арифметических операторов
        }else
        {
            QString result = this->text();
            emit equalsPressed(result);
            qDebug() << "Signal sent: " << result;
            Lexer lexer(result);
            Parser parser(lexer);
            try{
                double result = parser.parse();
                this->setText(QString::number(result));
            }catch(const std::exception& e)
                {
                    qDebug() << "Error: " << e.what();
                }

        }
        return;
    }
    // Добавляем ввод в QLineEdit
    this->setText(this->text() + inputChar);
    this->setCursorPosition(this->text().length());
}
void CalculatorLineEdit::keyPressEvent(QKeyEvent* event)
{
    if (this->text().length() >= 9 &&
        !(event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete)) {
        equals = false;
        event->ignore();
        return;
    }
    QString inputChar = event->text();
    if (inputChar.length() == 1 &&
        (inputChar[0].isDigit() ||
         inputChar[0] == '+' ||
         inputChar[0] == '-' ||
         inputChar[0] == '*' ||
         inputChar[0] == '/' ||
         inputChar[0] == '='))
    {
        if(this->text().isEmpty() && (inputChar[0] == '+' || inputChar[0] == '-' ||
                                      inputChar[0] == '/' || inputChar[0] == '*' ||
                                      inputChar[0] == '='))
        {
            event->ignore();
            equals = false;
            return;
        }
        else if(!this->text().isEmpty())
        {
            //Проверка на повторяющие символы
            QChar lastChar = this->text().back();
            if((lastChar == '+' || lastChar == '-' ||
                lastChar == '*' || lastChar == '/' ||
                lastChar == '=')
                &&
                (inputChar[0] == '+' || inputChar[0] == '-'||
                 inputChar[0] == '*' || inputChar[0] == '/'||
                 inputChar[0] == '='))
                {
                qDebug() <<"Error Repeting!!";
                equals = false;
                event->ignore();
                return;
                }
           if (inputChar[0] == '=' || event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
            {
                // Проверка на наличие операторов
                if (!this->text().contains('*') &&
                    !this->text().contains('-') &&
                    !this->text().contains('/') &&
                    !this->text().contains('+'))
                {
                    qDebug() << "Ignore not operators";
                    equals = false;
                    event->ignore();
                    return;
                }
                else{
                    equals = true;
                    QString result = this->text();
                    emit equalsPressed(result);
                    qDebug() << "Signal sent: " << result;
                    Lexer lexer(result);
                    Parser parser(lexer);
                    try{
                        double result = parser.parse();
                        this->setText(QString::number(result));
                    }catch(const std::exception& e)
                    {
                        qDebug() << "Error: " << e.what();
                    }
                    event->accept();
                    return;
                }
            }
        }

        this->setText(this->text() + inputChar);
        this->setCursorPosition(this->text().length());
        event->accept();
    } else if(event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete)
        {
        if(!this->text().isEmpty())
            {
                this->setText(this->text().chopped(1));
                this->setCursorPosition(this->text().length());
            }
        event->accept();
        }


    else {
        event->ignore();
    }
}
bool CalculatorLineEdit::isEquals()
{
    return equals;
}



