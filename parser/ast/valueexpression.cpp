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
