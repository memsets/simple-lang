#include "arrayexpression.h"

ArrayExpression::ArrayExpression(const QString &name, QVector<std::shared_ptr<Expression>> indices) :
    Expression (),
    name(name),
    indices(indices)
{
}

std::shared_ptr<Value> ArrayExpression::eval()
{
    std::shared_ptr<Value> receivedArray = VariableContainer::get(name);

    for (int i = 0; i < indices.size(); i++) {
        if (auto arrValue = std::dynamic_pointer_cast<ArrayValue>(receivedArray)) {
            receivedArray = arrValue->index(indices[i]->eval());
        } else {
            throw std::runtime_error("Cannot cast value to array");
        }
    }
    return receivedArray;
}

QString ArrayExpression::getName() const
{
    return name;
}

void ArrayExpression::setName(const QString &value)
{
    name = value;
}

QVector<std::shared_ptr<Expression> > ArrayExpression::getIndices() const
{
    return indices;
}

void ArrayExpression::setIndices(const QVector<std::shared_ptr<Expression> > &value)
{
    indices = value;
}
