#include "valueexpression.h"

ValueExpression::ValueExpression(std::shared_ptr<Value> value) : Expression (), value(value)
{
}

ValueExpression::ValueExpression()
{
}

std::shared_ptr<Value> ValueExpression::eval()
{
    return value;
}

std::shared_ptr<Value> ValueExpression::getValue() const
{
    return value;
}

void ValueExpression::setValue(const std::shared_ptr<Value> &value)
{
    this->value = value;
}
