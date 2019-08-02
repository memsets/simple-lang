#include "arrayexpression.h"

ArrayExpression::ArrayExpression(QString name, std::shared_ptr<Expression> expression) : Expression (),
    name(name),
    expression(expression)
{
}

std::shared_ptr<Value> ArrayExpression::eval()
{
    std::shared_ptr<Value> val = VariableContainer::get(name);
    if (auto v = std::dynamic_pointer_cast<ArrayValue>(val)) {
        return v->index(expression->eval());
    }
    throw std::runtime_error("Cannot cast value to array");
}
