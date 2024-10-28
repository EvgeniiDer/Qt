#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include<QPushButton>

class PushButton : public QPushButton
{
public:
    PushButton(const QString& _buttonText = "ClickMe",
               const int& _buttonW =100, const int& _buttonH = 100);
    void setButtonText(const QString& _buttonText)
    {
        buttonText = _buttonText;
    }
    QString getButtonText()
    {
        return buttonText;
    }
    void setButtonWidth(const int& _buttonW)
    {
        buttonW = _buttonW;
    }
    void setButtonHeight(const int& _buttonH)
    {
        buttonH = _buttonH;
    }
    int getButtonWidth()
    {
        return buttonW;
    }
    int getButtonHeight()
    {
        return buttonH;
    }

private:
    QString buttonText;
    int buttonW;
    int buttonH;
    void setupButton(const QString& _buttonText, const int& _buttonW , const int& _buttonH );

};

#endif // PUSHBUTTON_H