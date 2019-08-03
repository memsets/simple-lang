#include "arraystatement.h"

ArrayStatement::ArrayStatement(QString name,QVector<std::shared_ptr<Expression>> indices,
                               std::shared_ptr<Expression> value) :
    Statement (),
    name(name),
    indices(indices),
    value(value)
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
