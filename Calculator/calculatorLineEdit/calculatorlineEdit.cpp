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
/*void CalculatorLineEdit::setFont(const QFont& font)
{
    this->setFont(font);
}*/
void CalculatorLineEdit::addInput(const QString& inputChar)
{
    if(inputChar == "AC")
    {
        if(!this->text().isEmpty())
        {
            this->clear();
        }
        return;
    }
    if(inputChar == "<-")
    {
        QString currentText = this->text();
        if(!currentText.isEmpty())
        {
            currentText.chop(1);
            this->setText(currentText);
            this->setCursorPosition(currentText.length());
        }
        return;
    }

    if(this->text().length() > 9)
    {
        return;
    }
    if (!this->text().isEmpty())
    {
        // Проверка на повторяющиеся операторы
        QChar lastChar = this->text().back();
        if ((lastChar == '.' || lastChar == '+' || lastChar == '-' || lastChar == '*' || lastChar == '/' || lastChar == '=') &&
            (inputChar == "."|| inputChar == "+"|| inputChar == "-"|| inputChar == "*"|| inputChar == "/"|| inputChar == '='))
        {
            qDebug() << "Input Error: Repeating!!";
            return;
        }
    }
    else if(this->text().isEmpty())
        {
        //Проверка выражения на вхождение первым Токеном арифметических операторов
        if((inputChar == "+" || inputChar == "-" || inputChar == "*" || inputChar == "/" || inputChar == '=' /*|| inputChar == "."*/))
        {
            qDebug() << "Input Error: Cannot start with an operator";
            return;
        }
        else if(inputChar == ".")
        {
            QString shiftText = 0 + this->text();
            this->setText(shiftText);
        }
    }
    if(inputChar == "=")
    {
        //Проверка на пристутсвите Арифметических операторов
        if(!this->text().contains("*") &&
           !this->text().contains("/") &&
           !this->text().contains("+") &&
           !this->text().contains("-"))
        {
            qDebug() << "Input Error: Ignore not operators";
            return;
        }else
        {
            QString result = this->text();
            sentSignal(result);//Отправляем Сигнал в Calculator QLabel(CallLabel)
        }
        return;
    }
    // Добавляем ввод в QLineEdit
    this->setText(this->text() + inputChar);
    this->setCursorPosition(this->text().length());
}
void CalculatorLineEdit::keyPressEvent(QKeyEvent* event)
{
    //Проверка на максимальное колличество симолов во вхождении
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
         inputChar[0] == '=' ||
         inputChar[0] == '.' ||
         event->key() == Qt::Key_Return ||
         event->key() == Qt::Key_Enter))
    {
        //Проверка на первый символ
        if(this->text().isEmpty() && (inputChar[0] == '+' || inputChar[0] == '-' ||
                                      inputChar[0] == '/' || inputChar[0] == '*' ||
                                      inputChar[0] == '='))
        {
            event->ignore();
            equals = false;
            return;
        }
        else if(this->text().isEmpty() &&(inputChar[0] == '.'))
        {
            QString shiftText = 0 + this->text();
            this->setText(shiftText);
        }
        else if(!this->text().isEmpty())
        {
            //Проверка на повторяющие символы
            QChar lastChar = this->text().back();
            if((lastChar == '+' || lastChar == '-' ||
                lastChar == '*' || lastChar == '/' ||
                lastChar == '=' || lastChar == '.')
                &&
                (inputChar[0] == '+' || inputChar[0] == '-'||
                 inputChar[0] == '*' || inputChar[0] == '/'||
                 inputChar[0] == '=' || inputChar[0] == '.'||
                    event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter))
                {
                qDebug() <<"KeyEvent Error: Repeting!!";
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
                    qDebug() << "KeyEvent Error: Ignore not operators";
                    equals = false;
                    event->ignore();
                    return;
                }
                //Проверка на воторяющие
                else{
                    equals = true;
                    QString result = this->text();
                    sentSignal(result);//Отправляем Сигнал в Calculator QLabel(CallLabel)
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
void CalculatorLineEdit::sentSignal(const QString& result)
{
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
bool CalculatorLineEdit::isEquals()
{
    return equals;
}



