#ifndef CALCULATORLINEDIT_H
#define CALCULATORLINEDIT_H

#include<QDebug>
#include<QLineEdit>
#include<QKeyEvent>
#include<QFont>
#include<QPalette>
#include<QValidator>
#include"../ExprValidator/expvalidator.h"
class CalculatorLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    CalculatorLineEdit(QWidget* parent = nullptr);
private:
    void validateInput();
    ExpValidator* validator;
protected:
    void keyPressEvent(QKeyEvent* event)override;



};

#endif // CALCULATORLINEEIDT_H
