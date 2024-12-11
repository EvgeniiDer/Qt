#ifndef CALCULATORLINEDIT_H
#define CALCULATORLINEDIT_H

#include<QDebug>
#include<QLineEdit>
#include<QKeyEvent>
#include<QFont>
#include<QPalette>
#include<QValidator>
#include"../ExprValidator/expvalidator.h"
#include"../CalculatorCore/parser.h"

class CalculatorLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    CalculatorLineEdit(QWidget* parent = nullptr);
    bool isEquals();
public slots:
    void addInput(const QString& inputChar);
private:
    void validateInput();
    ExpValidator* validator;
    bool equals;
    QString result;
protected:
    void keyPressEvent(QKeyEvent* event)override;
signals:
    void equalsPressed(const QString& result);



};

#endif // CALCULATORLINEEIDT_H
