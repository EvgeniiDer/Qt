#ifndef CALCULATORBUTTON_H
#define CALCULATORBUTTON_H

#include<QPushButton>
#include<QPalette>
#include<QPaintEvent>
#include<QPainter>
class CalculatorButton : public QPushButton
{
public:
    CalculatorButton(const QString& strLabel, QWidget* parent = nullptr, const QColor& color = QColor("#404040")) ;
private:
    QColor btnColor;
protected:
    void paintEvent(QPaintEvent* event)override;
};

#endif // CALCULATORBUTTON_H
