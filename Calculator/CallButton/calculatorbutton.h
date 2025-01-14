#ifndef CALCULATORBUTTON_H
#define CALCULATORBUTTON_H

#include<QPushButton>
#include<QPalette>
#include<QPaintEvent>
#include<QPainter>

class CalculatorButton : public QPushButton
{
    Q_OBJECT
public:
    CalculatorButton(const QString& strLabel, QWidget* parent = nullptr, const QColor& color = QColor("#404040")) ;
    void setFont(const QFont& font);
private:
    QColor btnColor;
    bool isPressed;
protected:
    void paintEvent(QPaintEvent* event)override;
private slots:
    void onPressed();
    void onReleased();
};

#endif // CALCULATORBUTTON_H
