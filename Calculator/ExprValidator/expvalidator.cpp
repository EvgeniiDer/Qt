#include "expvalidator.h"

QValidator::State ExpValidator::validate(QString& input, int& pos)const
{
    QRegularExpression regexp("^[0-9]*([+\\-*/][0-9]+)*=?$");
    if(regexp.match(input).hasMatch())
    {
        return Acceptable;
    }
    else{
        return Invalid;
    }

}

