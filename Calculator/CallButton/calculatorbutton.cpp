#include "calculatorbutton.h"

CalculatorButton::CalculatorButton(const QString& strLabel,QWidget* parent, const QColor& color) : QPushButton(strLabel, parent),
    btnColor(color)
{

    this->setFixedSize(50, 50);
}
void CalculatorButton::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(btnColor);

    painter.setPen(Qt::NoPen);
    painter.drawEllipse(0, 0, this->width(), this->height());

    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, text());

}
