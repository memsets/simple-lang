#include "arraystatement.h"

ArrayStatement::ArrayStatement(const QString &name,QVector<std::shared_ptr<Expression>> indices,
                               std::shared_ptr<Expression> value) :
    Statement (),
    name(name),
    indices(indices),
    value(value)
{
}

ArrayStatement::ArrayStatement()
{
}

void ArrayStatement::exec()
{
    std::shared_ptr<Value> arr = VariableContainer::get(name);

    //TODO: needs make better names for variables
    for (int i = 0; i < indices.size() - 1 ; i++) {
        if (auto arrVal = std::dynamic_pointer_cast<ArrayValue>(arr)) {
            arr = arrVal->index(indices[i]->eval());
        } else {
            throw std::runtime_error("Cannot cast value to array");
        }
    }

    auto last = std::dynamic_pointer_cast<ArrayValue>(arr);
    last->set(indices[indices.size() - 1]->eval(), value->eval());
}

std::shared_ptr<Expression> ArrayStatement::getValue() const
{
    return value;
}

void ArrayStatement::setValue(const std::shared_ptr<Expression> &value)
{
    this->value = value;
}

QVector<std::shared_ptr<Expression>> ArrayStatement::getIndices() const
{
    return indices;
}

void ArrayStatement::setIndices(const QVector<std::shared_ptr<Expression> > &value)
{
    indices = value;
}

QString ArrayStatement::getName() const
{
    return name;
}

void ArrayStatement::setName(const QString &value)
{
    name = value;
}
