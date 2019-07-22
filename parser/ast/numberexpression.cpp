#include "numberexpression.h"

double NumberExpression::getNumber() const
{
    return number;
}

void NumberExpression::setNumber(double value)
{
    number = value;
}

NumberExpression::NumberExpression(const double number) : Expression (), number(number)
{
}

NumberExpression::NumberExpression()
{
}

double NumberExpression::eval()
{
    return number;
}
