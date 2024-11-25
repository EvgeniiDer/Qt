#ifndef CALCULATORLINEDIT_H
#define CALCULATORLINEDIT_H

#include<QLineEdit>
#include<QDoubleValidator>
#include<QKeyEvent>
#include<QFont>
#include<QPalette>
class CalculatorLineEidt : public QLineEdit
{
public:
    CalculatorLineEidt(QWidget* parent = nullptr);
private:
    QDoubleValidator* validator;
protected:
    void keyPressEvent(QKeyEvent* event)override;


};

#endif // CALCULATORLINEEIDT_H
