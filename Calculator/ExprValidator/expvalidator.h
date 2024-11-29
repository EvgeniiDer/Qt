#ifndef EXPVALIDATOR_H
#define EXPVALIDATOR_H

#include<QValidator>
#include<QRegularExpressionValidator>

class ExpValidator : public QValidator
{
public:
    ExpValidator(QObject *parent = nullptr) : QValidator(parent) {};
    State validate(QString& input, int& pos)const override;
    //void fixup(QString& input)const override;

};

#endif // EXPVALIDATOR_H
