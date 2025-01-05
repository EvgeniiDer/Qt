#include "calculatorbutton.h"

CalculatorButton::CalculatorButton(const QString& strLabel,QWidget* parent, const QColor& color) : QPushButton(strLabel, parent),
    btnColor(color)
{
    connect(this, &QPushButton::pressed, this, &CalculatorButton::onPressed);
    connect(this, &QPushButton::pressed, this, &CalculatorButton::onReleased);

    this->setFixedSize(50, 50);
}
void CalculatorButton::onPressed()
{
    isPressed = true;
    this->update();
}
void CalculatorButton::onReleased()
{
    isPressed = false;
    this->update();
}
void CalculatorButton::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if(isPressed)
    {
        painter.setBrush(QColor(0,0,0));
    }else{
        painter.setBrush(QColor(btnColor));
    }

    painter.setPen(Qt::NoPen);
    painter.drawEllipse(0, 0, this->width(), this->height());

    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, text());

}
