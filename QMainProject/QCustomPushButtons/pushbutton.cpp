#include "pushbutton.h"

PushButton::PushButton(const QString& _buttonText, const int& _buttonW, const int& _buttonH)
{
    buttonText = _buttonText;
    buttonW = _buttonW;
    buttonH = _buttonH;
    setupButton(buttonText, buttonW, buttonH);
}

void PushButton::setupButton(const QString& _buttonText, const int& _buttonW , const int& _buttonH)
{
    this->setText(_buttonText);
    this->setFixedSize(_buttonW, _buttonH);
}
