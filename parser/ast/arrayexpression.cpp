#include "arrayexpression.h"

ArrayExpression::ArrayExpression(QString name, QVector<std::shared_ptr<Expression>> indices) : Expression (),
    name(name),
    indices(indices)
{
}

std::shared_ptr<Value> ArrayExpression::eval()
{
    std::shared_ptr<Value> value = VariableContainer::get(name);

    for (int i = 0; i < indices.size(); i++) {
        if (auto arrValue = std::dynamic_pointer_cast<ArrayValue>(value)) {
            value = arrValue->index(indices[i]->eval());
        } else {
            throw std::runtime_error("Cannot cast value to array");
        }
    }
    return value;
}
